class Solution {
public:
    // Using backtrack method.
    void generateHelper(vector<string> &result, int balance, int n, string s) {
        if (s.length() == n) {
            result.push_back(s);
            return;
        }
        if (n > s.size() + balance)
            generateHelper(result, balance + 1, n, s + "(");
        if (balance > 0)
            generateHelper(result, balance - 1, n, s + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateHelper(result, 0, n * 2, "");
        return result;
    }
};