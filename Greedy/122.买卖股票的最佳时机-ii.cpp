/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 * 本题目等价于比前一天高即进行买卖，例如[1,5,6]第一天买入，第三天卖出得到最大收益为5，这一过程与第一天买，第二天卖，第二天买，第三天卖结果等价
 * 因此得到简化
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();  //这样速度要好很多，因为cases中有大样本，在循环中节省了时间
        for (int i = 1;i<n;++i){
            profit += max(0,prices[i]-prices[i-1]);
        }
        return profit;
    }
};
// @lc code=end

