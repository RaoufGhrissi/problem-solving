#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        int ans = 0;
        int n = v.size();

        if (n==1) return 1;
        if (n==2) return 2;

        int l = log2(n);

        return (1<<(l+1));
    }
};