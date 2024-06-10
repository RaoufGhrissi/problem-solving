#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
/*
    example 1: 
    10 20 5
    70 50 30

    10 -> 70     70 / 10 * quality of an employee
    20 -> 50     50 / 20 * quality of an employee
    5 -> 30      30 / 5 * quality of an employee

    let's consider 4 employees
    w1 / q1
    w2 / q2
    w3 / q3
    w4 / q4

    employee 4 will be paied max(w4, q4 * (wi / qi)) for i = 1, 2, 3
    in other words, max(w4, q4 * max(min(wi/qi)))
    the goal is to minimize wi/qi to decrease the ratio
*/
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n = q.size();
        if (k==1)
            return *min_element(w.begin(), w.end());

        vector<pair<double, int>> v;
        for (int i=0 ; i<n ; i++)
        {
            double a = w[i]/(double)q[i];
            v.push_back({a, i});
        }

        sort(v.begin(), v.end());
        k--;
        double ans = 1e9;
        double sm = 0;
        priority_queue<double> pq;
        for (int i=0 ; i<n ; i++)
        {
            double ratio = v[i].first;
            int index = v[i].second;
            int qlty = q[index];
            int wage = w[index];

            if (pq.size() == k)
                ans = min(ans, sm*ratio + wage);

            if (pq.size() < k) {
                pq.push(qlty);
                sm += qlty;
            } else if (pq.top() > qlty) {
                sm -= pq.top();
                pq.pop();
                pq.push(qlty);
                sm += qlty;
            }
        }

        return ans;
    }
};