#include <iostream>
class Base {
 public:
  virtual void show() = 0;
  virtual ~Base(){};
};

class D1 : public Base {
 public:
  void show() override { std::cout << "D1 out!\n"; }
};

class D2 : public Base {
 public:
  void show() override { std::cout << "D2 out!\n"; }
};

class D3 : public Base {
 public:
  void show() override { std::cout << "D3 out!\n"; }
};

template <typename T1>
class AbstractFactory {
 public:
  virtual T1* CreateProduct() = 0;
  virtual ~AbstractFactory() {}
};

template <typename T1, typename T2>
class ConcreteFactory : public AbstractFactory<T1> {
 public:
  T1* CreateProduct() { return new T2(); }
};

int main() {
  ConcreteFactory<Base, D1> d1fac;
  Base* p1 = d1fac.CreateProduct();
  p1->show();

  ConcreteFactory<Base, D2> d2fac;
  Base* p2 = d2fac.CreateProduct();
  p2->show();

  ConcreteFactory<Base, D3> d3fac;
  Base* p3 = d3fac.CreateProduct();
  p3->show();

  delete p1;
  delete p2;
  delete p3;
  return 0;
}