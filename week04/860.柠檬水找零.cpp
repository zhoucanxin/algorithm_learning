/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_cnt = 0, ten_cnt = 0;
        int n = bills.size();
        for (int i = 0; i < n; ++i) {
            if (bills[i] == 5)
                five_cnt++;
            else if (bills[i] == 10)
            {
                if (five_cnt == 0)
                    return false;
                else {
                    five_cnt--;
                    ten_cnt++;
                }
            }
            else
            {
                if (five_cnt > 0 && ten_cnt > 0)
                {
                    five_cnt--;
                    ten_cnt--;
                }
                else if (five_cnt >= 3)
                {
                    five_cnt -= 3;
                }
                else
                    return false;
            }
            
        }
        return true;
    }
};
// @lc code=end

