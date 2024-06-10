//https://leetcode.com/contest/biweekly-contest-123/problems/find-the-number-of-ways-to-place-people-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool static compare(vector<int> p1, vector<int> p2) {
        if (p1[0] == p2[0])
            return p1[1] > p2[1];

        return p1[0] < p2[0];
    }

    int numberOfPairs(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), compare);
        int n = v.size();
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            int maxx = v[i][1];
            int minn = -1e9 - 7;
            for (int j=i+1 ; j<n ; j++) {
                if (v[j][1] <= maxx && v[j][1] > minn) {
                    ans++;
                    minn = v[j][1];
                }
            }
        }

        return ans;
    }
};



int main() {
    vector<vector<int>> v = {{2, 6}, {4, 4}, {6, 2}};
    cout<<Solution().numberOfPairs(v);
    return 0;
}