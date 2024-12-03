#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    int maxRemoval(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        sort(q.begin(), q.end());

        priority_queue<pp, vector<pp>, greater<pp>> minHeap;
        priority_queue<pp> maxHeap;

        int used = 0;
        int j = 0;

        for (int i=0 ; i<n ; i++) {
            while(!minHeap.empty() && (minHeap.top().first < i)) {
                minHeap.pop();
            }

            while(j<q.size() && q[j][1] < i) j++;   

            while(j<q.size() && q[j][0] <= i && q[j][1] >= i) {
                maxHeap.push({q[j][1], q[j][0]});
                j++;
            }

            while(v[i] > minHeap.size() && !maxHeap.empty()) {
                if (maxHeap.top().first >= i && maxHeap.top().second <= i) {
                    minHeap.push(maxHeap.top());
                    used++;
                }
                maxHeap.pop();
            }

            if (v[i] > minHeap.size()) return -1;
        }

        return q.size() - used;
    }
};