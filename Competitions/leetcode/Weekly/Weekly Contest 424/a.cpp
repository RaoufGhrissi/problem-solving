#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& p) {
        map<int, multiset<int>> endByStart;

        for (auto &pp:p) {
            endByStart[pp[0]].insert(pp[1]);
        }

        vector<int> start;
        for (auto &a:endByStart) {
            start = {a.first, *a.second.begin()};
            if (a.second.size() == 1) {
                break;
            }
        }

        vector<vector<int>> ans = {start};

        endByStart[start[0]].erase(endByStart[start[0]].lower_bound(start[1]));
        if (!endByStart[start[0]].empty())
            endByStart.erase(start[0]);

        int n = p.size() - 1;

        while(n>0) {
            int lastEnd = start[1];
            for (auto &x:endByStart[lastEnd]) {
                if (n==1 || endByStart.count(x)) {
                    start = {lastEnd, x};
                    ans.push_back(start);
                    break;
                }
            }

            n--;
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> p = {{5, 1},{4, 5},{11, 9},{9, 4}};
    auto x = Solution().validArrangement(p);
}