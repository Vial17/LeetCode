class Solution {
public:
    // The classic offline algorithm.
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
   } 
};