#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        vector<string> v1, v2;

        int n = s.size();
        int q = n/k;

        string ch1 = "";
        string ch2 = "";

        for (int i=0 ; i<n ; i++) {
            if (ch1.size() < q) {
                ch1 += s[i];
                ch2 += t[i];
            } else {
                v1.push_back(ch1);
                v2.push_back(ch2);
                ch1 = "";
                ch2 = "";
                ch1 += s[i];
                ch2 += t[i];
            }
        }

        v1.push_back(ch1);
        v2.push_back(ch2);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};  