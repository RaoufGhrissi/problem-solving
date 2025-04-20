#include <bits/stdc++.h>
#define ll long long
#define mod (int)(1e9 + 7)

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> occ(26, 0);
        string ans = "";
        int n = s.size();
        
        for (char &c:s) {
            ans += '-';
            occ[c-'a']++;
        }
        
        int i = 0;
        for (char c='a' ; c<='z' ; c++) {
            while(occ[c-'a'] > 1) {
                ans[i] = c;
                ans[n-1-i] = ans[i];
                i++;
                
                occ[c-'a']-=2;
            }
            
            if (occ[c-'a'] == 1) {
                ans[n/2] = c;
            }
        }
        
        return ans;
    }
};