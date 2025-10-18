#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, pair<ll,ll>>
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

bool query(string s) {
    int ans;
    cout<<s<<endl;    
    cin>>ans;
    return ans;
}

void out() {
    cout<<"!"<<endl;
    fflush(stdout);

    int ans;
    cin>>ans;
}

void solve() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        // 1 -> 81
        query("mul 9");
        query("digit");
        query("digit");
        query("add " + to_string(n-9));
        out();
    }
}

int main() {
    solve();
    return 0;
}