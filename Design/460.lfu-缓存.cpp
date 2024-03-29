class LFUCache {
public:
    struct Node {
        int key;
        int val;
        int freq;
    };
    LFUCache(int capacity) : capacity_(capacity), minfreq(0) {}

    int get(int key) {
        auto it = key_table.find(key);
        if (it != key_table.end()) {
            auto node = it->second;
            int val = node->val, freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) {
                    minfreq++;
                }
            }
            freq_table[freq + 1].emplace_front(key, val, freq + 1);
            key_table[key] = freq_table[freq + 1].begin();
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = key_table.find(key);
        if (it != key_table.end()) {
            // 存在
            auto node = it->second;
            int freq = node->freq;
            // 调整freq
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) {
                    // 这里需要对minfreq调整
                    minfreq++;
                }
            }
            // 加入到freq + 1，并在key_table中更新位置
            freq_table[freq + 1].emplace_front(key, value, freq + 1);
            key_table[key] = freq_table[freq + 1].begin();
        } else {
            if (capacity_ == key_table.size()) {
                // 缓存已满，删除最小freq的最后一个
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                // 删除完之后，如果minfreq中没有元素，删除
                if (freq_table[minfreq].size() == 0) {
                    // 这里的问题是，更不更新minfreq
                    // 答案是不需要，因为删除操作只会在缓存满的时候触发
                    // 这时候一定有了新的值插入，minfreq在那时会被更新
                    freq_table.erase(minfreq);
                }
            }
            // 插入新的元素，freq为1
            freq_table[1].emplace_front(key, value, 1);
            // 在key_table中记录位置
            key_table[key] = freq_table[1].begin();
            // 重置最小freq
            minfreq = 1;
        }
    }

private:
    int capacity_;
    int minfreq;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
};