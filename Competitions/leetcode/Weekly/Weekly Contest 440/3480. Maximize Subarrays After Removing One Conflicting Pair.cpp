#include<bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    ll get(ll d) {
        return d;
    }

    ll maxSubarrays(int n, vector<vector<int>>& c) {
        set<pp> after;
        int m = c.size();

        for (int i=0 ; i<m ; i++)
            if (c[i][0] > c[i][1]) swap(c[i][0], c[i][1]);

        sort(c.begin(), c.end());
        vector<ll> gainIfDeleted(m, 0);
        ll sm = 0;
        ll mxGain = 0;
        int j = m-1;

        for (int i=n ; i>0 ; i--) {
            ll tot = 0;
            while(j>-1 && c[j][0] >= i) {
                after.insert({c[j][1], j});
                j--;
            }

            if (after.empty()) {
                tot = get(n-i+1);
            } else {
                auto it = after.begin();
                int miEnd = (*it).first;
                int delId = (*it).second;
                tot = get(miEnd-i);

                if (after.size() > 1) {
                    it = next(it);
                    miEnd = (*it).first;
                } else {
                    miEnd = n+1;
                }

                int _tot = get(miEnd-i);

                gainIfDeleted[delId] += _tot-tot;
                mxGain = max(mxGain, gainIfDeleted[delId]);
            }

            sm += tot;
        }

        return sm + mxGain;
    }
};

int main() {
    vector<vector<int>> v = {{2,3},{1,4}};
    //vector<vector<int>> v = {{1,2},{2,5},{3,5}};
    cout<<Solution().maxSubarrays(4, v);
}