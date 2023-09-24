/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1;
        vector<int> v1, v2;
        string s;
        s1 << version1;
        /**
         * getline(istream& is, string& str, char delim);
         * is: 输入流
         * str: 存储读取的字符串
         * delim: 分隔符, 默认为'\n'
         * 读取is中的字符, 直到遇到delim, 将读取的字符存储到str中
         */
        
        while (getline(s1, s, '.')) {
            v1.push_back(stoi(s));
        }
        s1.clear();
        s1 << version2;
        while(getline(s1, s, '.')) {
            v2.push_back(stoi(s));
        }
        while (v1.size() < v2.size()) {
            v1.push_back(0);
        }
        while (v2.size() < v1.size()) {
            v2.push_back(0);
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] > v2[i]) {
                return 1;
            } else if (v1[i] < v2[i] )  {
                return -1;
            }
        }
        return 0;
    }
};
// @lc code=end

