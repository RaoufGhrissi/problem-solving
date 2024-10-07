#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        int cnt = 0;
        int op = log2(k) + 1;
        
        for (int i=op ; i>-1 ; i--) {
            ll mid = (1ll<<(i+1))/2;
            if (k <= mid) continue;

            k -= mid;
            cnt += ops[i];
        }

        return (cnt%26) + 'a';
    }
};