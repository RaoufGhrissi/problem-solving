#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        
        int ones = 0;
        bool zeros = 0;
        
        for (char &a:s) {
            if (a == '0')
                zeros = 1;
            else {
                if (zeros)
                    ans += ones;
                
                zeros = 0;
                ones++;
            }
        }
        
        if (zeros)
            ans += ones;
        
        return ans;
    }
};