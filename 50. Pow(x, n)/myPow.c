double myPow(double x, int n) {
    if(n < 0) {
        if(n == INT_MIN)
            return myPow(1 / x, INT_MAX) * x;
        return myPow(1 / x, (-1) * n);
    }
    if(n == 0)
        return 1;
    if(n & 0x01)
        return x * myPow(x * x, n >> 1);
    else
        return myPow(x * x, n >> 1);
}