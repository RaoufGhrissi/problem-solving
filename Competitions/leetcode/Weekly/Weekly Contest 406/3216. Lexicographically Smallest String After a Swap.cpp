#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size(), i = 0;

        for (int i=0 ; i<n-1 ; i++) {
            int p1 = s[i]-'0';
            int p2 = s[i+1]-'0';
            if (s[i] > s[i+1] && ((p1&1 && p2&1) || (!(p1&1) && !(p2&1)))) {
                swap(s[i], s[i+1]);
                break;
            }
        }
        
        return s;
    }
};