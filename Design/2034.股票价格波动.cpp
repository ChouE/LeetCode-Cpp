/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
private:
    // 哈希表 + 有序集合
    unordered_map<int, int> time2price;
    set<pair<int, int>> price2time;
    int maxTimestamp = 0;
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        if (time2price.count(timestamp)) {
            // 删除旧的价格
            auto oldPrice = time2price[timestamp];
            price2time.erase({oldPrice, timestamp});
        }
        // 更新价格
        time2price[timestamp] = price;
        price2time.insert({price, timestamp});
        maxTimestamp = max(maxTimestamp, timestamp);

    }
    
    int current() {
        return time2price[maxTimestamp];
    }
    
    int maximum() {
        return price2time.rbegin()->first;
    }
    
    int minimum() { 
        return price2time.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

