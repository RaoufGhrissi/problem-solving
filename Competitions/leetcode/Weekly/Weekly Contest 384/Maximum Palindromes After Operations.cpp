#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& v) {
        vector<int> occ(26, 0);
        vector<int> sz;
        
        for (auto &w:v) {
            sz.push_back(w.size());
            for (auto &c:w) {
                occ[c-'a']++;
            }
        }
        
        int odd = 0;
        int even = 0;
        
        for (int i=0 ; i<26 ; i++) {
            odd += occ[i]&1 ? occ[i]-1 : occ[i];
            even += occ[i]&1 ? 1 : 0;
        }
                
        sort(sz.begin(), sz.end());
        int ans = 0;
        for (auto &x:sz) {
            if (x&1) {
                if (x-1 <= odd) {
                    if (even) {
                        ans++;
                        odd -= x-1;
                        even--;
                    } else if (x <= odd) {
                        ans++;
                        odd -= x;
                    } else
                        break;
                    
                } else {
                    break;
                }
            } else {
                if (x <= odd) {
                    ans++;
                    odd -= x;
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};