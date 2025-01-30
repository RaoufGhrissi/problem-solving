#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& s) {
        queue<int> q(st.begin(), st.end()); // students
        queue<int> ss(s.begin(), s.end()); // sandwiches = bokhl 

        /*stack<int> snd;

        for (int i=n-1 ; i>-1 ; i--)
            sn.push(s[i]);*/

        int stayed = 0;
        while(!q.empty() && q.size() > stayed) {
            if (q.front() == ss.front()) {
                q.pop();
                ss.pop();
                stayed = 0;
            } else {
                stayed++;
                q.push(q.front()); // nraj3ou f ekher saf
                q.pop(); // nraj3ou f ekher saf
            }
        }

        return q.size();
    }
};