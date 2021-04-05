/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 * 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠
 * 
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });//Lamda表达式，按照结尾从小到大对区间进行排序（自定义排序）
        int removed = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i){
            if(intervals[i][0] < prev){
                ++removed;  //下一个区间的开头与上一个结尾作比较，如果小则说明重合，按照贪心的策略将其去除
            }
            else{
                prev = intervals[i][1];  //否则则更新prev，用新的结尾值作为比较，不去除
            }
        }
        return removed;

    }
};
// @lc code=end

