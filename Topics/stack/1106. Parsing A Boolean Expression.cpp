
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool toBool(char c) {
        return c=='t' ? 1 : 0;
    }

    char toChar(bool a) {
        return a ? 't' : 'f';
    }

    bool parseBoolExpr(string s) {
        stack<char> ops;
        stack<char> vals;

        int n = s.size();

        for (int i=0 ; i<n ; i++) {
            char c = s[i];
            if (c == ',') {
                continue;
            } else if (c == '(') {
                vals.push('(');
            } else if (c == ')') {
                char op = ops.top();
                ops.pop();

                if (op == '!') {
                    char val = vals.top();
                    vals.pop();
                    vals.pop();
                    vals.push(toChar(!toBool(val)));
                } else {
                    bool ans = toBool(vals.top());
                    vals.pop();
                    
                    while(!vals.empty() && vals.top() != '(') {
                        if (op == '&')
                            ans &= toBool(vals.top());
                        else
                            ans |= toBool(vals.top());

                        vals.pop();
                    }

                    vals.pop();
                    vals.push(toChar(ans));
                }
            } else if (c == 'f' || c == 't') {
                vals.push(c);
            } else {
                ops.push(c);
            }
        }

        return(toBool(vals.top()));
    }
};