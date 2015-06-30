class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long original_number = x;
        long reversed_number = reverse(x);
        return original_number == reversed_number;
    }
    
    // Use LONG to handle overflow in INT.
    long reverse(long x) {
        long result = 0;
        while(x) {
            result = 10 * result + x % 10;
            x /= 10;
        }
        return result;
    }
};