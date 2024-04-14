#include <iostream>
class Singleton {
 public:
  static Singleton& getInstance() {
    static Singleton instance;
    return instance;
  }
  void doSomething() {
    std::cout << "doing something\n";
  }
  private:
    Singleton(){
        std::cout << "Create\n"; 
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton& singleton = Singleton::getInstance();
    singleton.doSomething();
    Singleton& singleton2 = Singleton::getInstance();
    singleton2.doSomething();
    return 0;
}