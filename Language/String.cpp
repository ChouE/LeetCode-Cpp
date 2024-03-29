#include <cstring>
#include <iostream>

namespace my {
class String {
 private:
  char* data;

 public:
  String() : data(new char[1]) { data[0] = '\0'; }
  // Constructor with C-String
  String(const char* s) {
    if (s) {
      size_t length = strlen(s);
      data = new char[length + 1];
      strcpy(data, s);
    } else {
      data = new char[1];
      data[0] = '\0';
    }
  }
  // Copy Constructor
  String(const String& other) : data(new char[std::strlen(other.data) + 1]) {
    std::strcpy(data, other.data);
  }
  // Move Constructor
  String(String&& other) noexcept : data(other.data) { other.data = nullptr; }
  ~String() { delete[] data; }
  // Copy Assignment operator
  String& operator=(const String& other) {
    if (this != &other) {
      delete[] data;
      data = new char[std::strlen(other.data) + 1];
      std::strcpy(data, other.data);
    }
    return *this;
  }
  // Mova Assignment operator
  String& operator=(String&& other) noexcept {
    if (this != &other) {
      delete[] data;
      data = other.data;
      other.data = nullptr;
    }
    return *this;
  }

  // Access by index
  char& operator[](size_t index) const { return data[index]; }

  // Get length
  size_t size() const { return std::strlen(data); }

  // c_str
  const char* c_str() const { return data; }

  // output
  friend std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.data;
    return os;
  }
};
}  // namespace my

int main() {
  using namespace my;
  String s1("hello");
  String s2 = s1;
  String s3;
  s3 = s2;
  std::cout << s1 << '\n';
  std::cout << s2 << '\n';
  std::cout << s3 << '\n';
}