#include <bits/stdc++.h>

//https://leetcode.com/problems/ipo/

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pp> projects;
        priority_queue<int> profits;

        int n = p.size();

        for (int i=0 ; i<n ; i++)
            projects.push_back({c[i], p[i]});

        sort(projects.begin(), projects.end());

        int i = 0;
        int ans = w;

        while(k--) {
            while (i<n && projects[i].first <= w) {
                profits.push(projects[i].second);
                i++;
            }

            if (profits.empty()) break;
            ans += profits.top();
            w += profits.top();

            profits.pop();
        }

        return ans;
    }
};