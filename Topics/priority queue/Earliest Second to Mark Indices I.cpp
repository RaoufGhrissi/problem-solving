#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    bool check(int mid, vector<int>& v, vector<int>& c) {
        map<int,int> maxx;
        for (int i=0 ; i<mid ; i++) {
            int x = c[i]-1;
            maxx[x] = i;
        }
        
        map<int,int> inverse;
        for (auto &a:maxx) {
            inverse[a.second] = a.first;
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int n = v.size();
        set<int> zeros;
        for (int i=0 ; i<n ; i++) {
            if (v[i])
                pq.push({maxx[i], v[i], i});
            else
                zeros.insert(i);
        }
        
        int marked = v.size();
        for (int i=0 ; i<mid ; i++) {
            if (inverse.count(i)) {
                int x = inverse[i];
                if (!zeros.count(x))
                    return 0;
                
                zeros.erase(x);
                continue;
            }
        
            if(!pq.empty()) {
                vector<int> t = pq.top();
                pq.pop();
                int ss = t[0];
                int x = t[1];
                int index = t[2];
                x--;
                if (!x) {
                    zeros.insert(index);
                } else {
                    pq.push({ss, x, index});
                }
            }
        }
        
        return pq.empty() && zeros.empty();
    }
    
    int earliestSecondToMarkIndices(vector<int>& v, vector<int>& c) {
        int m = c.size();
        int i = 1;
        int j = m;

        while(i<j) {
            int mid = (i+j)/2;
            if (check(mid, v, c)) {
                j = mid;
            } else {
                i = mid+1;
            }
        }

        return check(i, v, c) ? i : -1;
    }
};
