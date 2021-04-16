/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        bool a[1000] = {false};
        vector<vector<int>> ans(n);
        //按照身高从低到高排序，如果身高相同则按照k值大小从大到小排序
        sort(people.begin(),people.end(),[&](vector<int>&x,vector<int>&y)->bool{return x[0]<y[0]||(x[0]==y[0]&&x[1]>y[1]);});
        int i,j,k;
        for (i=0;i<n;++i){
            for(j=k=0;;++j){
                if(!a[j]){
                    if(++k>people[i][1])break;    //从低到高，找到能让前面空余k个位置的地方，直接定位这个人
                }
            }
            a[j] = true;
            ans[j] = people[i];
        }
        return ans;
    }
};
// @lc code=end

