#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";
        int n = s.size();
        
        for (int i=0 ; i<n ; i++) {
            int o = (i+k)%n;
            ans += s[o];    
        }
        
        return ans;
    }
};