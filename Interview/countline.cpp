#include <iostream>
#include <fstream>
#include <string>
// TODO: 字符串字面量中的注释符号解析
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file - " << filename << '\n';
        return 1;
    }
    std::string line;
    int codeLines {}, commentLines {};
    bool commentBlock = false;
    while (std::getline(file, line)) {

        // trim whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.empty()) continue;
        if (commentBlock) {
            commentLines++;
            if (line.find("*/") != std::string::npos) {
                commentBlock = false;
            }
        } else {
            if (line.find("/*") != std::string::npos) {
                commentLines++;
                commentBlock = true;
                if (line.find("*/") != std::string::npos) {
                    commentBlock = false;
                }
            } else if (line.find("//") != std::string::npos) {
                commentLines++;
            } else {
                codeLines++;
            }
        }
    }

    file.close();
    std::cout << "Total code lines: " << codeLines << '\n';
    std::cout << "Total comment lines: " << commentLines <<'\n';

    return 0;
}