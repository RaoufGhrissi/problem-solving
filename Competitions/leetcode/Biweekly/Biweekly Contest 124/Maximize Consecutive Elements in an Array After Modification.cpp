#include <bits/stdc++.h>

using namespace std;

class Group {
    public:
        int last;
        int first;
        int sz;
        int tot;
        int cumSz;
    
    Group(int x) {
        first = x;
        last = x;
        sz = 1;
        tot = 1;
        cumSz = 1;
    }
};

class Solution {
public:
    int maxSelectedElements(vector<int>& v) {
        sort(v.begin(), v.end());
        Group group = Group(v[0]);
        vector<Group> groups;
        
        int n = v.size();

        for (int i=1 ; i<n ; i++) {
            if (v[i]==v[i-1]) {
                group.tot++;
            } else if (v[i] == v[i-1]+1) {
                group.sz++;
                group.tot++;
                group.cumSz++;
                group.last = v[i];
            } else {
                groups.push_back(group);
                group = Group(v[i]);
            }

            if (i==n-1)
                groups.push_back(group);
        }

        int m = groups.size();
        int ans = 1;
        for (int i=0 ; i<m ; i++) {
            if (i+1 < m && groups[i].last + 2 == groups[i+1].first) {
                if (groups[i].tot > groups[i].sz) {
                    groups[i+1].cumSz = groups[i+1].sz + groups[i].cumSz + 1;
                } else if (i+1 < m) {
                    groups[i+1].cumSz = groups[i+1].sz + groups[i].sz;
                }
            } else {
                if (groups[i].tot > groups[i].sz)
                    groups[i].cumSz++;
            }

            ans = max(ans, groups[i].cumSz);
        }

        return ans;
    }
};