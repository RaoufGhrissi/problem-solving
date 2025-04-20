#include <bits/stdc++.h>
#define ll long long
#define mod (int)(1e9 + 7)

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(x-z);
        int d2 = abs(y-z);
        
        if (d1 == d2) return 0;
        else if (d1 < d2) return 1;
        else return 2;
    }
};