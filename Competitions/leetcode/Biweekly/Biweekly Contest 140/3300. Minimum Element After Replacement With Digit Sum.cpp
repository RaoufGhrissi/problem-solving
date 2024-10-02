#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& v) {
        int ans = 1e9;

        for (int &x:v) {
            string s = to_string(x);

            int sm = 0;
            for (char &c:s)
                sm += c-'0';

            ans = min(ans, sm);
        }

        return ans;
    }
};