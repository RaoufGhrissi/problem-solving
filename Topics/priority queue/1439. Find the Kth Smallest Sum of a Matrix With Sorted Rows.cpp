#include <bits/stdc++.h>

#define pp pair<int,string>

using namespace std;


class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = v.size();
        int m = v[0].size();

        int tot = 0;
        k--;

        for (int i=0 ; i<n ; i++) {
            tot += v[i][0];
            pq.push({m > 1 ? v[i][1] - v[i][0] : (int)1e9, i, 0});
        }

        while(k--) {
            cout<<tot<<endl;
            vector<int> t = pq.top();
            pq.pop();
            int diff = t[0];
            int i = t[1];
            int j = t[2];

            if (j+2 >= m) {
                pq.push({(int)1e9, i, j+1});
            } else {
                pq.push({v[i][j+2] - v[i][j+1], i, j+1});
                tot -= v[i][j];
                tot += v[i][j+1];
            }
        }

        return tot;
    }
};


int main() {
    vector<vector<int>> v = {{1, 3, 11}, {2, 4, 6}};
    cout<<Solution().kthSmallest(v, 9);
}