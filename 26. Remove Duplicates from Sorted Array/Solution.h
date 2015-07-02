class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        vector<int> result;
        result.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
            if(result[result.size() - 1] < nums[i])
                result.push_back(nums[i]);
        nums = result;
        return result.size();
    }
};