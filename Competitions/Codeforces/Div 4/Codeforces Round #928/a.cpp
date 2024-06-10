#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;

    while(n--) {
        string s;
        cin>>s;

        int a = 0, b = 0;

        for (auto &c:s) {
            a += c == 'A';
            b += c == 'B';
        }

        if (a > b) {
            cout<<"A";
        } else {
            cout<<"B";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}