#include <bits/stdc++.h>

using namespace std;


#define ll long long

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        
        vector<int> ans;
        
        for (auto &q:queries) {
            int x = abs(q[0]) + abs(q[1]);
            if (pq.size() < k)
                pq.push(x);
            else if (pq.top() > x) {
                pq.pop();
                pq.push(x);
            }
            
            if (pq.size() == k)
                ans.push_back(pq.top());
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
};