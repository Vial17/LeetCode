class Solution {
public:
    int reverse(int x) {
        // abs(INT_MIN) = INT_MIN will lead to infinite loop.
        if(x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);
        
        long result = 0
        while(x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
		
        // Check whether overflow occurs.
        return result > INT_MAX? 0 : result;
    }
};
