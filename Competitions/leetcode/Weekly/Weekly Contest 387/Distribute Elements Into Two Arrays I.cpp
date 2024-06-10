#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        vector<int> arr1 = {v[0]};
        vector<int> arr2 = {v[1]};
        int n = v.size();
        
        for (int i=2 ; i<n ; i++) {
            if (arr1[arr1.size()-1] > arr2[arr2.size()-1])
                arr1.push_back(v[i]);
            else
                arr2.push_back(v[i]);
        }
        
        for (auto &a:arr2)
            arr1.push_back(a);
        
        return arr1;
    }
};