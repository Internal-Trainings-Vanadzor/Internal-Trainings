#include <iostream>
#include <string>
#include <fstream>

/**
 * Removes the single line comments from the "code" file and saves the output in "output" file
 *
 * TODO: Pass input and output files names as parameters
 * TODO: Do note remove the single line comment if it is contained in a multiple-line comment
 */
static void remove_single_line_comments (std::string comment_str_start) {
    std::string line;
    std::ifstream myfile ("code");
    std::ofstream output ("output");
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            int brackets_count = 0;
            unsigned int i = 0;
            std::string::size_type index = line.find(comment_str_start, i);
            while(index != std::string::npos) {
                while (i < index) {
                    if ('"' == line[i] && (0 == i || '\\' != line[i-1])) {
                        ++brackets_count;
                    }
                    ++i;
                }
                if (0 == brackets_count % 2) {
                    line.replace(index, std::string::npos, "");
                    break;
                } else {
                    i += 2;
                    index = line.find(comment_str_start, i);
                }
            }
            if (line.find_first_not_of (' ') != std::string::npos) {
                output << line << std::endl;
            }
        }
        myfile.close();
        output.close();
    } else {
        std::cout << "Failed" << std::endl;
    }
    return;
}

int main () {
    remove_single_line_comments("//");
    return 0;
}
