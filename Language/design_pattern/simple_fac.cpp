#include <iostream>
#include <memory>
class Shoes {
 public:
  virtual ~Shoes() {}
  virtual void show() = 0;
};

class Tebu : public Shoes {
 public:
  void show() override { std::cout << "tebutebu\n"; }
};

class Adi : public Shoes {
 public:
  void show() override { std::cout << "adiadi\n"; }
};

void test(Shoes&& sh) { sh.show(); }

int main() {
  test(Tebu{});
  test(Adi{});
  
  return 0;
}