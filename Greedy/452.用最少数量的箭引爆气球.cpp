/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @microsoft
 * [452] 用最少数量的箭引爆气球
 * 与[435]无重叠区间类似，先排序再遍历
 * 寻找最小交集
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        sort(points.begin(),points.end(),[](const vector<int>& u,const vector<int>& v){
            return u[1] < v[1]; //右端排序
        });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) { //c++11 for循环遍历的方法
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

