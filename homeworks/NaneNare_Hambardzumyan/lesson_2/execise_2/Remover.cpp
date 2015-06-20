#include <iostream>
#include <fstream>

class CommentsRemover {
    private:
        bool ifFileExist(const std::string& name) {
            std::ifstream f(name.c_str());
            bool isExist = false;
            if (f.good()) {
                isExist = true;
            }
            f.close();
            return isExist;
        }

        std::string processLine(std::string arg) {
            int indS = arg.find_first_of(m_block_com_start);
            int indE = 0;
            if ((0 <= indS) && (indS !=std::string::npos)) {
                arg = arg.erase(indS,m_block_com_start.size());
                int indE = arg.find_first_of(m_block_com_end);
                if ((0 <= indE) && (indE !=std::string::npos)) {
                    arg = arg.erase(indS,indE+m_block_com_end.size()-indS);
                } else {
                    std::cout << "WARN: Can't find end." << std::endl;
                    m_is_block_started = true;
                    arg = arg.erase(indS,arg.size());
                }
            } else {
                indE = arg.find_first_of(m_block_com_end);
                if ((0 <= indE) && (indE !=std::string::npos)) {
                    if (!m_is_block_started) {
                        std::cout << "WARN: Block hasn't start." << std::endl;
                    }
                    m_is_block_started = false;
                    arg = arg.erase(0,indE+m_block_com_end.size());
                }
            }
            if ((-1 == indS)&&(-1 == indE)) {
                return arg;
            }
            return processLine(arg);
        }

        void removeLines() {
            if (m_tmp_file.is_open()) {
                std::string line ;
                m_file.open(m_filename.c_str(), std::ios::in);
                while (getline(m_file,line)) {
                    std::cout << "line is : " << line  << std::endl;
                    int ind = line.find(m_line_com);
                    bool isComment = false;
                    if (0 < ind)  {
                        line = line.erase(ind,line.size()); 
                        isComment =true;
                    } else if (0 == ind) {
                        line = "";
                        isComment = true;
                    }
                    if (isComment) {
                        m_tmp_file << line;
                    } else {
                        m_tmp_file << line << std::endl;
                    }
                    m_tmp_file.flush();
                }
                m_file.close();
            } else {
                std::cout << "tmp can't be open !.\n";
            }
        }
        /*
         *
         */
        void removeBlocks() {
            m_is_block_started = false;
            if (!m_tmp_file.is_open()) {
                std::cout << "tmp can't be open !.\n";
            }
            std::string line ;
            m_file.open(m_filename.c_str(), std::ios::in);
            while (getline(m_file,line)) {
                std::cout << "line is : " << line  << std::endl;
                int indS = line.find(m_block_com_start);
                int indE = line.find(m_block_com_end);
                if ((0 <= indS) && ( 0 <= indE) 
                        && (indE !=std::string::npos)
                        && (indS !=std::string::npos)) {
                    line = line.erase(indS,indE-indS+m_block_com_end.size());
                           line = processLine(line);
                } else if ((0 <= indS) 
                        && (indS !=std::string::npos)) {
                    if (m_is_block_started) {
                        std::cout << "WARN: Start comment inside another comment block. Ignore." << std::endl;
                    }
                    m_is_block_started = true;
                    line = line.erase(indS,line.size());
                } else if ((0 <= indE) 
                        && (indE !=std::string::npos)) {
                    if (!m_is_block_started) {
                        std::cout << "WARN: There is nor Start comment for this end comment.Ignore." << std::endl;
                    }
                    m_is_block_started = false;
                    line = line.erase(0,indE+m_block_com_end.size());
                    line = processLine(line);
                } else if (((-1 == indS) && (-1 == indE)) ||
                        ((indE !=std::string::npos)
                         && (indS !=std::string::npos))) {
                    if (m_is_block_started) {
                        std::cout << "INFO: Remove line from block." 
                            << std::endl;
                        line = "";
                    }
                } else {
                    std::cout << "INFO: I don't know :). "
                        << indS << " - " << indE
                        << std::endl;
                }
                m_tmp_file << line << std::endl;
                m_tmp_file.flush();
            }
            m_file.close();
        }
    public:
        /*
         *  remove Line Comments
         */
        void removeLineComments() {
            m_tmp_file.open("tmp.txt");          
            removeLines();
            m_tmp_file.close();
            rename("tmp.txt",m_filename.c_str());
        }
        /*
         * remove Block Comments
         */
        void removeBlockComments() {
            m_tmp_file.open("tmp.txt");          
            removeBlocks();
            m_tmp_file.close();
            rename("tmp.txt",m_filename.c_str());
        }
        /*
         * constructor
         */
        CommentsRemover(const std::string filename,
                const std::string line="//",
                const std::string blockS="/*",
                const std::string blockE="*/")
            :m_filename(filename)
            ,m_line_com(line)
            ,m_block_com_start(blockS)
            ,m_block_com_end(blockE)
            {
                if (!ifFileExist(m_filename)) {
                    std::cout << "WARN: Specifed file is missing: " 
                        << m_filename << " Please update the path."
                        << std::endl;
                }
            }
        /*
         *  destructor
         */
        ~CommentsRemover() 
        {}
        /*
         * set Line Comment
         */
        void setLineComment(const std::string& arg) {
            m_line_com = arg;
        }
        /*
         * set Block Comments
         */
        void setBlockComments(const std::string& argS, const std::string argE) {
            m_block_com_start = argS;
            m_block_com_end = argE;
        }
    private:
        std::string m_filename;
        std::string m_line_com;
        std::string m_block_com_start;
        std::string m_block_com_end;
        std::ifstream m_file;
        std::ofstream m_tmp_file;
        bool m_is_block_started;
};

int main () {
    // CommentsRemover will replace existing file
    CommentsRemover obj("main.cpp");
    obj.removeBlockComments();
    obj.removeLineComments();
    return 0;
}
