#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        int dist[n][n];
        x--;
        y--;
        memset(dist, 0, sizeof dist);

        if (x>y) swap(x, y);
        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                int d = j-i;
                if (d > abs(y-j) + 1 + abs(x-i))
                    d = abs(y-j) + 1 + abs(x-i);

                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        vector<int> ans(n, 0);
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (dist[i][j])
                    ans[dist[i][j] - 1]++;
            }
        }

        return ans;
    }
};



int main() {
    vector<int> ans = Solution().countOfPairs(5, 2, 4);
    return 0;
}