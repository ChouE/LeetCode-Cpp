#include <iostream>
#include <vector>

class SparseSet {
  std::vector<int> dense;
  std::vector<int> sparse;
  size_t capacity;
  size_t size;

public:
  SparseSet(size_t cap) : capacity(cap), size(0) {
    sparse.resize(capacity, -1);
  }

  void insert(int val) {
    if (val < 0 || val >= capacity || contains(val)) {
      return;
    }
    dense.push_back(val);
    sparse[val] = size++;
  }

  bool contains(int val) const {
    return val >= 0 && val < capacity && sparse[val] >= 0 &&
           sparse[val] < size && dense[sparse[val]] == val;
  }

  void erase(int val) {
    if (!contains(val)) {
      return;
    }
    int last = dense[size - 1];
    dense[sparse[val]] = last;
    sparse[last] = sparse[val];
    size--;
  }

  void print() {
    for (size_t i = 0; i < size; i++) {
      std::cout << dense[i] << " ";
    }
    std::cout << '\n';
  }
};

int main() {
  SparseSet sset(10);
  sset.insert(3);
  sset.insert(6);
  sset.insert(9);
  sset.print();
  if (sset.contains(9)) {
    std::cout << "9 is in the set.\n";
  }
  sset.erase(6);
  sset.print();
  return 0;
}