#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int minimumArrayLength(vector<int>& v) {
        sort(v.begin(), v.end());
        int mi = v[0];

        for (int i=0 ; i<v.size() ; i++) {
            if (v[i]%mi)
                return 1;
        }

        int cnt = 1;
        for (int i=1 ; i<v.size() ; i++) {
            if (v[i] == v[0]) cnt++;
            else break;
        }

        return cnt&1 ? cnt/2 + 1 : cnt/2;
    }
};