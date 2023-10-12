/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
struct Node
{
    int key, val, freq;
};
class LFUCache
{
private:
    int minfreq;
    int capacity;
    // key -> Node's location
    unordered_map<int, list<Node>::iterator> key_table;
    // freq -> Node list with this freq
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->minfreq = 0;
        this->key_table.clear();
        this->freq_table.clear();
    }

    int get(int key)
    {
        // not found
        if (capacity == 0)
        {
            return -1;
        }
        auto it = key_table.find(key);
        if (it == key_table.end())
        {
            return -1;
        }
        // found
        auto node = it->second;
        int val = node->val, freq = node->freq;
        // delete node from freq_table[freq]
        freq_table[freq].erase(node);
        // last node in freq_table
        if (freq_table[freq].size() == 0)
        {
            freq_table.erase(freq);
            if (minfreq == freq)
            {
                minfreq++;
            }
        }
        // add node to freq_table[freq + 1]'s front
        freq_table[freq + 1].push_front(Node{key, val, freq + 1});
        // relocate key_table[key]
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        auto it = key_table.find(key);
        // not found
        if (it == key_table.end())
        {
            // cache is full
            if (capacity == key_table.size())
            {
                // delete minfreq's last node
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0)
                {
                    freq_table.erase(minfreq);
                }
            }
            // add node to freq_table[1]'s front
            freq_table[1].push_front(Node{key, value, 1});
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        }
        else
        {
            // found
            auto node = it->second;
            int freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0)
            {
                freq_table.erase(freq);
                if (minfreq == freq)
                {
                    minfreq++;
                }
            }
            freq_table[freq + 1].push_front(Node{key, value, freq + 1});
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
