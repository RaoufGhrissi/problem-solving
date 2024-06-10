#include <bits/stdc++.h>
//https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& v) {
        int n = s.size()-1;

        set<string> st(v.begin(), v.end());

        vector<string> ans;
        for (int i=0 ; i<(1<<n) ; i++) {
            int prev = 0;
            string res = "";
            bool ok = 1;
            for (int j=0 ; j<n+1 ; j++) {
                int mask = 1<<j;

                if (mask&i || j==n) {
                    int l = j-prev+1;
                    string sub = s.substr(prev, l);
                    if (st.count(sub)) {
                        res += sub;
                        if (j < n)
                            res += " ";

                        prev = j+1;
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }

            if (ok) {
                ans.push_back(res);
            }
        }

        return ans;
    }
};

int main() {
    vector<string> v = {"cat","cats","and","sand","dog"};
    auto a = Solution().wordBreak("catsanddog", v);
    return 0;
}