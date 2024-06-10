#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);
        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        int ans = 0;
        int i = 0;
        int j = n-1;


        while(i+1<n && v[i+1] == v[i])
            i++;
        
        while(j && v[j-1] == v[j])
            j--;
        
        if (v[i] != v[j]) {
            cout<<n-max(i+1, n-j)<<endl;
            continue;
        }

        i++;
        j--;

        if (i>j) {
            cout<<0;
        } else {
            cout<<j-i+1;
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}