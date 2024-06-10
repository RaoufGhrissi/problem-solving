#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cum[1000][26];
    int dp[1000][1001];
    
    bool check(int i, int prev, int &n) {
        int diff = -1;
        bool ok = 1;
        
        for (int dd=0 ; dd<26 ; dd++) {
            int cnt = cum[i][dd]; // r = i
            if (prev != 1000)
                cnt -= cum[prev][dd]; // l-1 = prev
            
            // houni bech naaref number of the char dd from l = prev+1 to r = i, i nesta3mel cum sum eli hsebtha m lowel
            // w nekhou result fi O(1)
            if (!cnt) continue;
                        
            if (diff != -1 && diff != cnt) {
                ok = 0;
                break;
            }
            
            diff = cnt;
        }
        
        return ok;
    }
    
    int rec(int i, int prev, int &n) {
        if (i==n) {
            return check(n-1, prev, n) ? 1 : 1e5;
        }
        
        int &ans = dp[i][prev];
        if (ans != -1) return ans;
        
        ans = rec(i+1, prev, n); // mat9osch
        
        if (check(i, prev, n)) // chouf tnajem t9os wala
            ans = min(ans, 1+rec(i+1, i, n));
        
        return ans;
    }
    
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        memset(cum, 0, sizeof cum);
        memset(dp, -1, sizeof dp);

        for (int i=0 ; i<n ; i++) {
            cum[i][s[i]-'a']++;
        }

        // cum sum = O(26*N) preprocessing, lbara mel algo
        for (int i=0 ; i<26 ; i++) {
            for (int j=1 ; j<n ; j++) {
                cum[j][i] += cum[j-1][i];
            }
        }
        
        return rec(0, 1000, n);
    }
};