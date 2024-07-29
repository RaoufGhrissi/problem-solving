#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        
        set<char> v = {'a', 'e', 'i', 'o', 'u'};
        
        for (char &c:s) {
            if (v.count(c))
                cnt++;
        }
        
        return cnt;
    }
};