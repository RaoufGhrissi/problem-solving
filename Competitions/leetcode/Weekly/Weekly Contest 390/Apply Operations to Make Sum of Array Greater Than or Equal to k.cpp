#include <bits/stdc++.h>

using namespace std;

#define pp pair<string, int>

class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9;
        for (int i=1 ; i<=k ; i++) {
            ans = min(i-1 + (k%i ? k/i : k/i - 1), ans);
        }

        return ans;
    }
};