class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> v;
            int n = nums.size();

            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) {
                    v.push_back(min(nums[2*i], nums[2*i + 1]));
                } else {
                    v.push_back(max(nums[2*i], nums[2*i + 1]));
                }
            }
            nums = v; 
        }
        return nums[0];
    }
};
