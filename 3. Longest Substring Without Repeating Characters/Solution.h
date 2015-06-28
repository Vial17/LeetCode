class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<int> last_appear(256, -1);
        int max_len = 0;
        int len;
        int start = 0;
        
		for(int i = 0; i < s.size(); ++i) {
            int old_pos = last_appear[s[i]];
			int new_pos = i;
			
			// Update mex_len when meeting a character in current substring.
            if(old_pos >= start) {
                len = new_pos - start;
                max_len = max_len > len? max_len : len;
                start = old_pos + 1;
            }
            
			last_appear[s[i]] = i;
        }
        
        // Handle the tail substring of s.
		len = s.size() - start;
        max_len = max_len > len? max_len : len;
        
		return max_len;
    }
};