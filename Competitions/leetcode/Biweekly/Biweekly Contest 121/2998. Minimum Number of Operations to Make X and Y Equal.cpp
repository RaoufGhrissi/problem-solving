#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>> q;
        int n = 1e6;
        unordered_set<int> vis;
        q.push({x, 0});

        while(!q.empty()) {
            pair<int,int> f = q.front();
            q.pop();
            int x = f.first;
            int d = f.second;

            if (x == y)
                return d;

            int xx = x+1;
            if (xx < 1e6 && xx > -1 && !vis.count(xx)) {
                vis.insert(xx);
                q.push({xx, d + 1});
            }

            xx = x-1;
            if (xx < 1e6 && xx > -1 && !vis.count(xx)) {
                vis.insert(xx);
                q.push({xx, d + 1});
            }

            xx = x/11;
            if (x%11 == 0 && xx < 1e6 && xx > -1 && !vis.count(xx)) {
                vis.insert(xx);
                q.push({xx, d + 1});
            }

            xx = x/5;
            if (x%5 == 0 && xx < 1e6 && xx > -1 && !vis.count(xx)) {
                vis.insert(xx);
                q.push({xx, d + 1});
            }
        }

        return 0;
    }
};

int main() {
    cout<<Solution().minimumOperationsToMakeEqual(3, 18);
}