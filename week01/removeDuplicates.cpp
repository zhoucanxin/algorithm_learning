class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int vec_size = nums.size();
        if (vec_size == 0)
            return 0;
        int fast = 1;
        int slow = 1;
        while (fast < vec_size) {
            if (nums[fast] != nums[fast -1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};