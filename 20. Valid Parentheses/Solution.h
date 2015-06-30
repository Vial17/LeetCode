class Solution {
public:
    bool isValid(string s) {
        stack<char> par_stk;
        for(int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '(': {
                        par_stk.push(')');
                        break;
                }
                case '[': {
                        par_stk.push(']');
                        break;
                }
                case '{': {
                	par_stk.push('}');
                	break;
                }
                case ')': {
                	if(par_stk.empty() || par_stk.top() != ')')
                	    return false;
                	else
                	    par_stk.pop();
                	break;
                }
                case ']': {
                	if(par_stk.empty() || par_stk.top() != ']')
                	    return false;
                	else
                	    par_stk.pop();
                	break;
                }
                case '}': {
                	if(par_stk.empty() || par_stk.top() != '}')
                	    return false;
                	else
                	    par_stk.pop();
                	break;
                }
            }
        }
        return par_stk.empty();
    }
};
