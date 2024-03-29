#include <chrono>
#include <iostream>
#include <list>
#include <thread>
#include <unordered_map>


using namespace std::chrono;

class LRUCache {
  using time_point = high_resolution_clock::time_point;

 private:
  int capacity_;
  struct CacheItem {
    int value;
    time_point lastAccess;
  };
  using PT = std::pair<int, CacheItem>;
  std::list<PT> lru;
  std::unordered_map<int, decltype(lru)::iterator> cache;
  high_resolution_clock::duration ttl;

 public:
  LRUCache(int capacity, high_resolution_clock::duration expireTime)
      : capacity_(capacity), ttl(expireTime) {
         //std::cout << ttl;
      }
  int get(int key) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      if (high_resolution_clock::now() - it->second->second.lastAccess > ttl) {
        lru.erase(it->second);
        cache.erase(it);
        return -1;
      }
      it->second->second.lastAccess = high_resolution_clock::now();
      lru.splice(lru.begin(), lru, it->second);
      return it->second->second.value;
    }
    return -1;
  }
  void put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      it->second->second.value = value;
      it->second->second.lastAccess = high_resolution_clock::now();
      lru.splice(lru.begin(), lru, it->second);
      return;
    }
    if (lru.size() == capacity_) {
      auto last = lru.back();
      cache.erase(last.first);
      lru.pop_back();
    }
    CacheItem newItem{value, high_resolution_clock::now()};
    lru.emplace_front(key, newItem);
    cache[key] = lru.begin();
  }
  void cleanup() {
    auto now = high_resolution_clock::now();
    while (!lru.empty() && now - lru.back().second.lastAccess > ttl) {
      cache.erase(lru.back().first);
      lru.pop_back();
    }
  }
};

int main() {
  using namespace std;
  using namespace std::chrono_literals;
  // 创建一个容量为2和过期时间为100毫秒的LRUCache实例
  LRUCache cache(2, 100ms);

  // 测试用例1: 添加元素并立即获取
  cache.put(1, 100);
  cout << "Test Case 1: Put (1,100)" << endl;
  cout << "Get 1: " << cache.get(1) << " (Expected: 100)" << endl;

  // 等待150毫秒让缓存项1过期
  this_thread::sleep_for(chrono::milliseconds(150));
  cout << "Get 1 after 150ms: " << cache.get(1) << " (Expected: -1, Expired)"
       << endl;

  // 测试用例2: 添加元素，稍等，然后添加第二个元素，确保第一个元素还在缓存中
  cache.put(2, 200);
  this_thread::sleep_for(chrono::milliseconds(50));
  cache.put(3, 300);
  cout << "Test Case 2: Put (2,200), wait 50ms, Put (3,300)" << endl;
  cout << "Get 2: " << cache.get(2) << " (Expected: 200)" << endl;
  cout << "Get 3: " << cache.get(3) << " (Expected: 300)" << endl;

  // 测试用例3: 测试LRU属性，第一个元素应该被替换
  this_thread::sleep_for(chrono::milliseconds(30));
  cache.put(4, 400);
  cout << "Test Case 3: Put (4,400) after waiting 100ms" << endl;
  cout << "Get 2: " << cache.get(2) << " (Expected: -1, Replaced by 4)" << endl;
  cout << "Get 3: " << cache.get(3) << " (Expected: 300)" << endl;
  cout << "Get 4: " << cache.get(4) << " (Expected: 400)" << endl;

  // 测试用例4: 添加元素，稍等，然后重复获取以防止过期，再添加新元素
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