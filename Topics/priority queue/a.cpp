#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>> &v) {
        int n = v.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> ends;
        for (auto &rec:v) {
            ends.push_back(rec[1]);
        }

        sort(v.begin(), v.end());
        sort(ends.begin(), ends.end());

        int j = 0;
        int cuts = 0;

        for (int i=0 ; i<n ; i++) {
            int e = ends[i];
            if (i && e == ends[i-1]) continue;
            if (e == ends[n-1]) break;

            while(j<n && v[j][0] < e) {
                minHeap.push(v[j][1]);
                j++;
            }

            while(!minHeap.empty() && minHeap.top() <= e) {
                minHeap.pop();
            }

            cuts += minHeap.empty();
        }

        return cuts >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& v) {
        vector<vector<int>> xx, yy;
        
        for (auto &rec:v) {
            xx.push_back({rec[0], rec[2]});
            yy.push_back({rec[1], rec[3]});
        }
        
        return isValid(xx) || isValid(yy);
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{0,0,1,4},{1,0,2,3},{2,0,3,3},{3,0,4,3},{1,3,4,4}};
    cout<<s.checkValidCuts(4, v)<<endl;
    return 0;
}