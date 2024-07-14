#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string actual = "";
        stack<string> res;
        int n = s.size();
        for (int i=0 ; i<s.size() ; i++) {
            char c = s[i];
            if (c==')') {
                reverse(actual.begin(), actual.end());
                if (res.empty()) {
                    res.push(actual);
                    actual = "";
                } else {
                    string prev = res.top();
                    res.pop();
                    actual = prev + actual;
                }
            } else if (c=='(') {
                if (actual.empty()) continue;
                res.push(actual);
                actual = "";
            } else {
                actual += c;
            }
        }

        return res.top();
    }
};


int main() {
    cout<<Solution().reverseParentheses("s()uteawj((eg))");
}