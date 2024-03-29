#include <iostream>
#include <string>
#include <sstream>

unsigned int ipToInteger(const std::string& ip) {
    unsigned int res = 0;
    std::istringstream stream(ip);
    std::string oct;
    for (int i = 0; i < 4; ++i) {
        std::getline(stream, oct, '.');
        res = res * 256 + static_cast<unsigned>(std::stoul(oct));
    }
    return res;
}

int main() {
    std::string ip = "192.168.1.1";
    unsigned ipInt = ipToInteger(ip);
    std::cout << "IP Address: " << ip << " as an integer is: " << ipInt << std::endl;
}