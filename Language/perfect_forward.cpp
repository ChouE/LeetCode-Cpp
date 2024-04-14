#include <iostream>
#include <type_traits>

namespace my {

template <typename T>
struct remove_reference {
  using type = T;
};

// 左值引用特化
template <typename T>
struct remove_reference<T&> {
  using type = T;
};

// 右值引用特化
template <typename T>
struct remove_reference<T&&> {
  using type = T;
};

template <typename T>
using remove_reference_t = remove_reference<T>::type;

// forward
// 参数是左值引用的情况，t是去除引用的原始类型
// T被推导为 T& && 根据引用折叠，是一个T&
// static_cast<T&&> -> static_cast<T& &&> -> static_cast<T&>
// 返回值是T& && -> T&，保持了左值引用
template <typename T>
constexpr T&& forward(remove_reference_t<T>& t) noexcept {
  return static_cast<T&&>(t);
}

// T&& 表示的是模板推导的万能引用
// 根据引用折叠，会转化为对应的左值引用或者右值引用
// T&& && -> T&&
// static_cast<T&&> -> T&&
template <typename T>
constexpr T&& forward(remove_reference_t<T>&& t) noexcept {
  static_assert(!std::is_lvalue_reference_v<T>,
                "template argument"
                " T is an lvalue reference type");
  return static_cast<T&&>(t);
}

// 附带一个move实现
template <typename T>
remove_reference_t<T>&& move(T&& arg) noexcept {
  return static_assert<remove_reference_t<T>&&>(arg);
}

}  // namespace my

void printInt(int& i) { std::cout << "lv: " << i << "\n"; }

void printInt(int&& i) { std::cout << "rv: " << i << '\n'; }

template <typename T>
void f(T&& t) {
  // printInt(t);
  printInt(my::forward<T>(t));
}

int main() {
  int a = 5;

  f(5);
  f(a);
}
