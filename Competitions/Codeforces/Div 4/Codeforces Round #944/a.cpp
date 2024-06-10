#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;

    while(n--) {
        int x, y;
        cin>>x>>y;

        cout<<min(x,y)<<" "<<max(x, y)<<endl;
    }
}

int main() {
    solve();
    return 0;
}