#include <cassert>
#include <iostream>
namespace my {
char *memcpy(char *dst, const char *src, int cnt) {
  assert(dst != nullptr && src != nullptr);
  char *ret = dst;
  if (dst >= src && dst <= src + cnt - 1) {
    dst = dst + cnt - 1;
    src = src + cnt - 1;
    while (cnt--) {
      *dst-- = *src--;
    }
  } else {
    while (cnt--) {
      *dst++ = *src++;
    }
  }
  return ret;
}

char *strcpy(char *strDest, const char *strSrc) {
  assert((strDest != nullptr) && (strSrc != nullptr));
  auto address = strDest;
  memmove(strDest, strSrc, strlen(strSrc) + 1);
  //memcpy(strDest, strSrc, strlen(strSrc) + 1);
  return address;
}

size_t strlen(const char *str) {
  assert(str != nullptr);
  size_t len = 0;
  while ((*str++) != '\0') len++;
  return len;
}

char *strcat(char *Dest, const char *Src) {
  assert(Dest && Src);
  char *ret = Dest;
  while (*Dest != '\0') {
    Dest++;
  }
  while (*Dest++ = *Src++) {
  }
  return ret;
}

int strcmp(const char *s1, const char *s2) {
  assert(s1 && s2);
  while (*s1 && *s2 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
}  // namespace my

int main() {
  const char src[]{"hello, world!"};
  char dest[30];
  my::strcpy(dest, src);
  auto len1 = my::strlen(dest);
  std::cout << dest << " " << len1 << '\n';
  auto ans = my::strcat(dest, src);
  auto len2 = my::strlen(dest);
  std::cout << dest << " " << len2 << '\n';
  std::cout << my::strcmp(dest, ans) << '\n';
  
  
}