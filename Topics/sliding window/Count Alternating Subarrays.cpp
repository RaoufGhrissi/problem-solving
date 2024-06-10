#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& p) {
        int n = p.size();
        int ans = 1e9;
        multiset<int> x, y;

        for (int i=0 ; i<n ; i++) {
            int a = p[i][0];
            int b = p[i][1];

            p[i][0] = a+b;
            p[i][1] = a-b;
            x.insert(p[i][0]);
            y.insert(p[i][1]);
        }

        for (int i=0 ; i<n ; i++) {
            int a = p[i][0];
            int b = p[i][1];

            x.erase(x.lower_bound(a));
            y.erase(y.lower_bound(b));

            ans = min(ans, max(abs(*x.begin() - *x.end()), abs(*y.begin() - *y.end())));
            x.insert(a);
            y.insert(b);
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> v = {{3,10},{5,15},{10,2},{4,4}};
    cout<<Solution().minimumDistance(v);
    
    return 0;
}