class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> val_key;
		vector<int> result(2, -1);
		for(int i = 0; i < numbers.size(); ++i) {
			int cur_val = numbers[i];
			int exp_val = target - numbers[i];
			
			if(val_key.find(exp_val) != val_key.end()) {
				result[0] = val_key[exp_val] + 1;
				result[1] = i + 1;
				break;
			}
			else
				val_key[cur_val] = i;
		}	
		return result;
    }
};