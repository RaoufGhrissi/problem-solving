#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int ss) {
        sort(t.begin(), t.end());
        int n = t.size();

        sort(w.begin(), w.end());
        int m = w.size();

        int s = 0;
        int e = n;

        multiset<int> st(w.begin(), w.end());
        multiset<int> copy;
        while(s<e) {
            int mid = (s+e+1)/2;

            int cnt = 0;
            int j = m-1;
            int pp = p;
            copy = st;

            for (int i=mid-1 ; i>-1 ; i--) {
                // asgher wehed ynajem yekhdemha
                auto it = copy.lower_bound(t[i]);
                if (it != copy.end()) {
                    cnt++;
                    copy.erase(it);
                } else if (pp) {
                // asgher (wehed + ss) ynajem yekhdemha 
                    it = copy.lower_bound(t[i]-ss);
                    if (it != copy.end()) {
                        copy.erase(it);
                        pp--;
                        cnt++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            if (cnt == mid) {
                s = mid;
            } else {
                e = mid-1;
            }
        }

        return s;
    }
};

int main() {
    vector<int> t = {4, 5};
    vector<int> w = {0, 0, 0};
    cout<<Solution().maxTaskAssign(t, w, 1, 5);
}