#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n, m, d = 0;
        cin>>n>>m;
        vector<int> z;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            string s = to_string(x);

            int j = s.size();
            int cnt = 0;
            while(j && s[j-1] == '0')
                j--;

            int zeros = s.size() - j;
            int rest = s.size() - zeros;
            z.push_back(zeros);
            d += s.size();
        }

        sort(z.begin(), z.end(), greater<int>());
        for (int i=0 ; i<n ; i += 2) {
            d -= z[i];
        }

        if (d>m) {
            cout<<"Sasha";
        } else {
            cout<<"Anna";
        }
        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}