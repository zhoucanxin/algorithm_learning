/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = { "" };
        dp[1] = { "()" };
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string p:dp[j]) {
                    for (string q:dp[i - j - 1]) {
                        string tmp_str = "(" + p + ")" + q;
                        dp[i].push_back(tmp_str);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

