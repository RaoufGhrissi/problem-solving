#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf (ll)1e18f

using namespace std;

class Solution {
public:
    bool isBalanced(string s) {
        int p = 0, imp = 0;

        int n = s.size();

        for (int i=0 ; i<n ; i+=2) {
            p += s[i]-'0';
            if (i+1 < n)
                imp += s[i+1] - '0';
        }
        return p == imp;
    }
};