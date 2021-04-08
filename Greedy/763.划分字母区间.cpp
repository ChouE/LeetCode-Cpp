/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 * 本题首先进行了一次遍历，统计每个字母出现的最后位置，降低了问题难度
 * 如频率、个数、第一次出现位置、最后出现位置等信息的统计，不会影响算法时间复杂度，但可以降低难度
 */

// @lc code=start
class Solution {
public:
    // vector<int> partitionLabels(string S) {
    //     vector<int> result;
    //     unordered_map<char, int> map; //记录char c 和其最后出现位置的 map模板类
    //     int start = 0, end = 0;
    //     for (int i = 0; i < S.size(); i ++) {
    //         map[S[i]] = i;   //记录对应字母出现的最后位置
    //     }
    //     for (int i = 0; i < S.size(); i ++) {
    //         end = max(end, map[S[i]]);  //使end达到最大，如果遍历到最远的end处进行一次分割，此次分割是局部最优
    //         if (i == end) {
    //             result.push_back(end - start + 1);
    //             start = i + 1;
    //         }
    //     }
    //     return result;
    // } //69.93% runtime || 36.5% mu -6.6 MB
    vector<int> partitionLabels(string S) {
        int last[26];
        int length = S.size();
        for (int i = 0; i < length; i++) {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
}
}; //mu - 6.2 MB
// @lc code=end

