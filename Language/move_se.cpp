#include <iostream>
struct C {
    C() {}
    C(const C&) {std::cout << "copy\n"; }
    C(C&& rhs) {std::cout << "move\n";}
};
C f() {
    return C();
}
/* 
复制消除：
return语句中，和函数返回值类型一致的右值
变量初始化时，初始化表达式是右值
*/
int main() {
    std::cout << "hello\n" ;
    f();
}