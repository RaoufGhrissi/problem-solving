#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int sm = 0;

        for (int &x:v)
            sm += x;

        return sm%k;
    }
};