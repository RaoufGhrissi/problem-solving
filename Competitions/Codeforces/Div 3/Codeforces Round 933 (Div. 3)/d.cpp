#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int dp[1000][1001];

int dfs(int i, int person, vector<pp> &v, int &n) {
    if (i==v.size()) {
        return dp[person][i] = 1;
    }

    pp p = v[i];
    int d = p.first;
    int s = p.second;

    if (dp[person][i] != -1)
        return dp[person][i];

    dp[person][i] = 0;
    int xx;
    if (s==0 || s==-1) {
        xx = (person+d)%n;
        dp[person][i] += dfs(i+1, xx, v, n);
    }

    if (s==1 || s==-1) {
        xx = (person-d+n)%n;
        dp[person][i] += dfs(i+1, xx, v, n);
    }

    return dp[person][i]; 
}

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, person;
        cin>>n>>m>>person;
        person--;

        vector<pp> v(m);
        for (int i=0 ; i<m ; i++) {
            int x;
            char c;
            cin>>x>>c;

            if (c == '?')
                v[i] = {x, -1};
            else
                v[i] = {x, c-'0'};
        }

        memset(dp, -1, sizeof dp);
        dfs(0, person, v, n);
        vector<int> ans;

        for (int i=0 ; i<n ; i++)  {
            if (dp[i][m] != -1) {
                ans.push_back(i+1);
            }
        }

        cout<<ans.size()<<endl;
        for (auto &a:ans)
            cout<<a<<" ";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}