class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int max_left = 0, max_len = 1;
        int left, right;
        for (int start = 0; start < s.size();) {
            left = right = start;
            
            //  Find the "center" part of palindromic substring.
            while (right < s.size() - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            
            while (right < s.size() - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};