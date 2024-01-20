#include <bits/stdc++.h>

using namespace std;

class BIT {
    public:
        vector<int> tree;
        int n;

        BIT(vector<int> v) {
            tree = v;
            n = v.size();
        }   
        
        void update(int x, int val)
        {
            while(x<n)
            {
                tree[x] = max(tree[x], val);
                x+=(x)&(-x);
            }
        }

        int get_max(int x)
        {
            int res=0;
            while(x>0)
            {
                res = max(tree[x], res);
                x-=(x)&(-x);
            }

            return res;
        }
};