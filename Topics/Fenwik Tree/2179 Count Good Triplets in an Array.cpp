#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

using namespace std;

class BIT {
    public:
        vector<int> tree;
        int n;  

        BIT(int k) {
            n = k;
            tree.resize(n);
        }   
        
        void update(int x, int val)
        {
            while(x<n)
            {
                tree[x] += val;
                x+=(x)&(-x);
            }
        }

        int get(int x)
        {
            int res=0;
            while(x>0)
            {
                res += tree[x];
                x-=(x)&(-x);
            }

            return res;
        }
};


class Solution {
public:
    long long goodTriplets(vector<int>& v1, vector<int>& v2) {
        map<int,int> pos;
        int n = v1.size();

        ll ans = 0;
        for (int i=0 ; i<n ; i++) {
            pos[v2[i]] = i+1;
        }

        BIT bit = BIT(n+1);

        for (int i=0 ; i<n ; i++) {
            if (i && i+1<n) {
                int prev = bit.get(pos[v1[i]]);
                int no = i-prev;
                int after = n-pos[v1[i]];

                ans += prev*1ll*(after-no);
            }

            bit.update(pos[v1[i]], 1);
        }

        return ans;
    }
};