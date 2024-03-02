#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long

using namespace std;

class Solution {
public:
    bool check(int mid, vector<int> &v, vector<int> &c) {
        map<int,int> first_possible;
        map<int,int> inverse;

        for (int i=mid-1 ; i>-1 ; i--) {
            int index = c[i]-1;
            first_possible[index] = i;
        }

        for (auto &a:first_possible) {
            inverse[a.second] = a.first;
        }

        ll tot = 0;
        int n = v.size();
        int prev = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0 ; i<n ; i++) {
            if (first_possible.count(i))
                continue;

            tot += v[i];
        }
        
        for (int i=mid-1 ; i>-1 ; i--) {
            if (inverse.count(i)) {
                int x = v[inverse[i]];
                if (!prev) {
                    if (!pq.empty() && pq.top() < x) {
                        int t = pq.top();
                        pq.pop();
                        prev += 2;
                        tot += t;
                        pq.push(x);
                        prev--;
                    } else {
                        prev++;
                        tot += x;
                    }
                } else {
                    prev--;
                    pq.push(x);
                }
            } else {
                prev++;
            }
        }

        int cnt = 0;
        while(!pq.empty()) {
            int t = pq.top();
            cnt += t > 0;
            pq.pop();
        }

        return tot+cnt+n <= mid;
    }

    int earliestSecondToMarkIndices(vector<int>& v, vector<int>& c) {
        int m = c.size();   
        int i = 1;
        int j = m;

        while(i<j) {
            int mid = (i+j)/2;
            if (!check(mid, v, c)) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }

        return check(i, v, c) ? i : -1;
    }
};