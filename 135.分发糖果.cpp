/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @tags = greedy
 * [135] 分发糖果
 */
/*
 *使用贪心策略，进行两次遍历，第一次从左到右，若右比左大则将右更新为左加一
 *第二遍从右向左，若左比右大，且其糖数不超过右，则更新为右加一
 *这样在局部满足了规则，通过两次遍历使得整体也是满足规则的
 */
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) return size;
        vector<int> num(size,1);
        for (int i = 1; i < size;++i){
            if (ratings[i] > ratings[i-1]) num[i] = num[i-1] + 1;
            //第一次遍历
        }
        for (int i = size -1; i > 0; --i){
            if (ratings[i] < ratings[i-1]) num[i-1] = max(num[i-1],num[i]+1);
            //第二次遍历
        }
        return accumulate(num.begin(),num.end(),0); //std::accumulate 求和
    }
};
// @lc code=end

