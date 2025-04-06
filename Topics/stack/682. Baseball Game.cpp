#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<string> notIntegerOps = {"D", "C", "+"};

    map<string, function<void(string, stack<int>&)>> ops = {
        {
            "+", [](string x, stack<int> &st) {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                
                int s = t1 + t2;
                st.push(t1);
                st.push(s); 
            }
        },
        {
            "D", [](string x, stack<int> &st) {
                st.push(st.top() * 2); 
            }
        },
        {
            "C", [](string x, stack<int> &st) {
                st.pop(); 
            }
        },
        {
            "I", [](string x, stack<int> &st) {
                st.push(stoi(x)); 
            }
        },
    };

    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;

        for (string &op:operations) {
            if (notIntegerOps.count(op)) {
                ops[op](op, st);
            } else {
                ops["I"](op, st);
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }


        return ans;
    }
};

int main() {
    Solution s;
    vector<string> v = {"5","2","C","D","+"};
    cout << s.calPoints(v) << endl;
    return 0;
}