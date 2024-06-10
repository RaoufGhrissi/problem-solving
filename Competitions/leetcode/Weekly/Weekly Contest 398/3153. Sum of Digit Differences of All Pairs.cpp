#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long sumDigitDifferences(vector<int>& v) {
        vector<vector<int>> cnt(10, vector<int>(10, 0));

        ll ans = 0; 

        for (auto &a:v) {
            string s = to_string(a);
            int n = s.size();
            for (int i=0 ; i<n ; i++)
                cnt[i][s[i]-'0']++;
        }

        for (int i=0 ; i<10 ; i++) { // digits
            for (int j=0 ; j<10 ; j++) { // numbers
                for (int k=j+1 ; k<10 ; k++) { // other numbers
                    ans += cnt[i][k]*cnt[i][j];
                }
            }
        }

        return ans;
    }
};