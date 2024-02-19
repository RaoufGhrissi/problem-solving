#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& v) {
        sort(v.begin(), v.end());
        if (v[0]+v[1] <= v[2])
            return "none";
        
        map<int,int> occ;
        
        for (auto &c:v)
            occ[c]++;
        
        int n = occ.size();
        if (n == 1) {
            return "equilateral";
        } else if (n==2) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};