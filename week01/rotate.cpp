//方法1 数组翻转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverise(nums, 0, nums.size() - 1);
        reverise(nums, 0, k - 1);
        reverise(nums, k, nums.size() - 1);
    }

    void reverise(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
};