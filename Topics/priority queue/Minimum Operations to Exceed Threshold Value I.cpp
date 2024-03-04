#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

#define ll long long
class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        for (auto &a:v)
            pq.push(a);
        
        int ans = 0;
        while(!pq.empty() && pq.top() < k) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            
            pq.push(min(x, y)*2 + max(x, y));
            ans++;
        }
        
        return ans;
    }
};