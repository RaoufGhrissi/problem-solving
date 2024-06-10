#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void backtrack(int i, int &n, int &k, vector<int> &ans, vector<int> &res, multiset<int> &sums) {
    if (i == n+1) {
        ans = res;
        return;
    }

    if (i==k || sums.count(i))
        backtrack(i+1, n, k, ans, res, sums);
    else {
        for (auto &sm:sums) {
            if (sm >= i || i-sm == k) continue;
            if (i+sm == k) continue;

            
            int diff = i-sm;
            for (int i=0 ; i<n ; i++) {
                sums.push_back(sums[i] + diff);
            }

            res.push_back(diff);
            backtrack(i+1, n, k, ans, res, sums);
            if (!ans.empty())
                return ;

            res.pop_back();

            for (int i=0 ; i<n ; i++) {
                sums.pop_back();
            }
        }
    }
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<int> ans, res;
        vector<int> sums = {0};

        backtrack(0, n, k, ans, res, sums);

        for (auto &a:ans)
            cout<<a<<" ";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}