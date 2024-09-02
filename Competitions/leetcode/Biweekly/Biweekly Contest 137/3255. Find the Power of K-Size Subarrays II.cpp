#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> resultsArray(vector<int>& v, int k) {
        int i = 0;
        int j = 1;
        int n = v.size();

        vector<int> ans(n-k+1, -1);
        while (j<n) {
            if (v[j] == v[j-1]+1)
                j++;
            else {
                while(j-i >= k) {
                    ans[i] = v[i+k-1];
                    i++;
                }
                i = j;
                j++;
            }
        }

        while(n-i >= k) {
            ans[i] = v[i+k-1];
            i++;
        }

        return ans;
    }
};