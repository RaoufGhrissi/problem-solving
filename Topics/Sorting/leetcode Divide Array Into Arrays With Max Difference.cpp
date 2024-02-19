//https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01
#include<bits/stdc++.h>
#define pp pair<long double, long double>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<int> inter;
        vector<vector<int>> ans;

        int n = v.size();

        if (n%3)
            return ans;

        for (int i=0 ; i<n ; i+=3) {
            if (v[i+2]-v[i] > k) {
                return {};
            }

            inter.push_back(v[i]);
            inter.push_back(v[i+1]);
            inter.push_back(v[i+2]);

            ans.push_back(inter);
            inter.clear();
        }

        return ans;
    }
};