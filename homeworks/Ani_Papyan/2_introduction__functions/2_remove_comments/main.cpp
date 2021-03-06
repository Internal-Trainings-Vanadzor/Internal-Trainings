#include <iostream>
#include <string>
#include <fstream>

/**
 * Removes the single line comments from the "code" file and saves the output in "output" file
 *
 * TODO: Do not remove the single line comment if it is contained in a multiple-line comment
 */
static void remove_comments (const char* input_file, const char* output_file, std::string comment_str_start) {
    std::string line;
    std::ifstream myfile (input_file);
    std::ofstream output (output_file);
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

/**
 * Removes the multiple-line comments from the "code" file and saves the output in "output" file
 *
 * TODO: Do not remove the multiple line comment if it is contained in a single-line comment
 */
static void remove_comments (const char* input_file, const char* output_file, std::string comment_str_start, std::string comment_str_end) {
    std::string line;
    std::ifstream myfile (input_file);
    std::ofstream output (output_file);
    if (myfile.is_open()) {
        bool comment_started = false;
        int brackets_count = 0;
        while (getline (myfile,line)) {
            if (!comment_started) {
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
                        std::string::size_type index_end = line.find(comment_str_end, index + 2);
                        if (index_end != std::string::npos) {
                            line.replace(index, index_end + 2 - index, "");
                            index = line.find(comment_str_start, i);
                        } else {
                            line.replace(index, std::string::npos, "");
                            comment_started = true;
                            break;
                        }
                    } else {
                        i += 2;
                        index = line.find(comment_str_start, i);
                    }
                }
            } else {
                std::string::size_type index = line.find(comment_str_end, 0);
                if (index != std::string::npos) {
                    line.replace(0, index + 2, "");
                    comment_started = false;
                } else {
                    line = " ";    
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
    remove_comments("code", "output_single", "//");
    remove_comments("output_single", "output", "/*", "*/");
    return 0;
}
