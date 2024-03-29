#include <chrono>
#include <iostream>
#include <list>
#include <thread>
#include <unordered_map>

using namespace std::chrono;
class LRUCache {
  using time_point = high_resolution_clock::time_point;
  using Duration = high_resolution_clock::duration;
 private:
  int capacity_;
  struct Item {
    int key;
    int value;
    time_point lastAccess;
  };
  std::list<Item> lru;
  std::unordered_map<int, std::list<Item>::iterator> cache;
  Duration ttl;

 public:
  LRUCache(int capacity, Duration expireTime)
      : capacity_(capacity), ttl(expireTime) {}
  int get(int key) {
    if (auto it = cache.find(key); it != cache.end()) {
      // 判断是否过期
      if (high_resolution_clock::now() - it->second->lastAccess > ttl) {
        lru.erase(it->second);
        cache.erase(it);
        return -1;
      }
      // 未过期 更新访问时间
      it->second->lastAccess = high_resolution_clock::now();
      lru.splice(lru.begin(), lru, it->second);
      return it->second->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (auto it = cache.find(key); it != cache.end()) {
      it->second->value = value;
      it->second->lastAccess = high_resolution_clock::now();
      lru.splice(lru.begin(), lru, it->second);
      return;
    }
    if (lru.size() == capacity_) {
      auto last = lru.back();
      cache.erase(last.key);
      lru.pop_back();
    }
    Item newItem{key, value, high_resolution_clock::now()};
    lru.emplace_front(newItem);
    cache[key] = lru.begin();
  }
};

int main() {
  using namespace std;
  using namespace std::chrono_literals;
  LRUCache cache(2, 100ms);

  // Test 1
  cache.put(1, 100);
  cout << "Test Case 1: Put (1,100)" << endl;
  cout << "Get 1: " << cache.get(1) << " (Expected: 100)" << endl;

  // Test 2
  this_thread::sleep_for(chrono::milliseconds(150));
  cout << "Get 1 after 150ms: " << cache.get(1) << " (Expected: -1, Expired)"
       << endl;
  cache.put(2, 200);
  this_thread::sleep_for(chrono::milliseconds(50));
  cache.put(3, 300);
  cout << "Test Case 2: Put (2,200), wait 50ms, Put (3,300)" << endl;
  cout << "Get 2: " << cache.get(2) << " (Expected: 200)" << endl;
  cout << "Get 3: " << cache.get(3) << " (Expected: 300)" << endl;

  // Test 3
  this_thread::sleep_for(chrono::milliseconds(30));
  cache.put(4, 400);
  cout << "Test Case 3: Put (4,400) after waiting 30ms" << endl;
  cout << "Get 2: " << cache.get(2) << " (Expected: -1, Replaced by 4)" << endl;
  cout << "Get 3: " << cache.get(3) << " (Expected: 300)" << endl;
  cout << "Get 4: " << cache.get(4) << " (Expected: 400)" << endl;

  // Test 4
  cache.put(5, 500);
  this_thread::sleep_for(chrono::milliseconds(50));
  cout << "Get 5 after 50ms: " << cache.get(5) << " (Expected: 500)" << endl;
  this_thread::sleep_for(chrono::milliseconds(50));
  cout << "Get 5 again after 50ms: " << cache.get(5) << " (Expected: 500)"
       << endl;
  cache.put(6, 600);
  cout << "Test Case 4: After repeated gets, Put (6,600)" << endl;
  cout << "Get 5: " << cache.get(5) << " (Expected: 500)" << endl;
  cout << "Get 6: " << cache.get(6) << " (Expected: 600)" << endl;

  return 0;
}