#include <bits/stdc++.h>

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
    vector<int> countOfPeaks(vector<int>& v, vector<vector<int>>& qq) {
        int n = v.size();
        BIT bit = BIT(n+1);
        
        for (int i=1 ; i<n-1 ; i++) {
            if (v[i] > v[i-1] && v[i] > v[i+1])
                bit.update(i+1, 1);
        }
        
        vector<int> ans;
        for (auto &q:qq) {
            if (q[0] == 1) {
                int l = q[1]+1;
                int r = q[2]+1;
            
                ans.push_back(l == r ? 0 : bit.get(r-1) - bit.get(l));
            } else {
                int index = q[1];
                int val = q[2];

                bool isPick = index > 0 && index<n-1 && v[index] > v[index-1] && v[index] > v[index+1];
                
                int prev = index-1;
                bool isPrevPick = prev > 0 && prev<n-1 && v[prev] > v[prev-1] && v[prev] > v[prev+1];
                
                int nxt = index+1;
                bool isNextPick = nxt > 0 && nxt<n-1 && v[nxt] > v[nxt-1] && v[nxt] > v[nxt+1];

                v[index] = val;
                
                if (index > 0 && index<n-1 && v[index] > v[index-1] && v[index] > v[index+1]) { // ena walit peak
                    if (!isPick) bit.update(index+1, 1); // ida makontch peak nwali peak
                } else if (isPick) { // idha walit mch peak ama kont peak 
                    bit.update(index+1, -1);
                }
                
                if (prev > 0 && prev<n-1 && v[prev] > v[prev-1] && v[prev] > v[prev+1]) {
                    if (!isPrevPick) bit.update(prev+1, 1);
                } else if (isPrevPick) {
                    bit.update(prev+1, -1);
                }
                
                if (nxt > 0 && nxt<n-1 && v[nxt] > v[nxt-1] && v[nxt] > v[nxt+1]) {
                    if (!isNextPick) bit.update(nxt+1, 1);
                } else if (isNextPick) {
                    bit.update(nxt+1, -1);
                }
            }
        }
        
        return ans;
    }
};