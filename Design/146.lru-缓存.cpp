/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
  using PII = pair<int, int>;
  int capacity;
  // 使用双向链表+哈希表完成
  unordered_map<int, list<PII>::iterator> cache;

  list<PII> lru;

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    // it是unordered_map的迭代器，first是key，second是PII
    auto it = cache.find(key);
    // 如果找到了，就把它放到链表头部
    if (it != cache.end()) {
      // splice函数的作用是把it->second指向的节点移动到lru的头部
      // 三个参数的作用分别是：目标位置，目标链表，目标节点
      lru.splice(lru.begin(), lru, it->second);
      return it->second->second;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = cache.find(key);
    // 如果找到了，就把它放到链表头部
    if (it != cache.end()) {
      lru.splice(lru.begin(), lru, it->second);
      it->second->second = value;
      return;
    }
    // 容量满了，就把最后一个节点删除
    if (lru.size() == capacity) {
      // 获取的是元素，不是迭代器
      auto last = lru.back();
      cache.erase(last.first);
      lru.pop_back();
    }
    // 没找到，而且没满，加入到头部
    lru.emplace_front(key, value);
    cache[key] = lru.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
