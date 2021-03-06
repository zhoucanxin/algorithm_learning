/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n];
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        if (n >= 2) {
            if (s[1] == '0' && s[0] != '1' && s[0] != '2')
                return 0;
            else if (s[1] == '0' )
                dp[1] = 1;
            else if ((s[0] - '0') * 10 + s[1] - '0' <= 26)
                    dp[1] = 2;
            else
                 dp[1] = 1;
        }
        for (int i = 2; i < n; i++)
        {
            if (s[i] == '0' && s[i - 1] != '1' && s[i - 1] != '2')
                return 0;
            else if (s[i] == '0' )
            {
                dp[i] = dp[i - 2];
            }
            else if (s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0' <= 26))
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[n - 1];
    }
};
// @lc code=end

