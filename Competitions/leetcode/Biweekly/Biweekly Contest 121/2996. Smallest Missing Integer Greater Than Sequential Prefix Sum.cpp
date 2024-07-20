#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& v) {
        set<int> st(v.begin(), v.end());
        int sm = v[0];
        for (int i=1 ; i<v.size() ; i++) {
            if (v[i] != v[i-1]+1)
                break;

            sm += v[i];
        }

        while(st.count(sm)) {
            sm++;
        }

        return sm;
    }
};