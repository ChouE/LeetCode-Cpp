#include <iostream>
void func(char str[100]) {
    // 8 for 64bit
    std::cout << sizeof(str) << '\n';
}

void func1(char (&str)[100]) {
    // 100
    std::cout << sizeof(str) << '\n';
}
int main() {
    char s[100] {};

    func(s);
    // 100
    std::cout << sizeof(s) << '\n';
    func1(s);
}