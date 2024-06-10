// https://codeforces.com/group/YTYmnVxV00/contest/104805/problem/I

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    int zeros = 0;

    for (int i=0 ; i<n ; i++) {
        cout<<"get "<<i+1<<endl;
        cin>>v[i];
        zeros += !v[i];
    }

    int i=0;
    int j=n-1;

    while(zeros && i<j) {
        while (i<n && !v[i]) i++;
        while (j>-1 && v[j]) j--;

        if (i>=j) break;
        cout<<"swap "<<i+1<<" "<<j+1<<endl;
        swap(v[i], v[j]);
        i++;
        j--;
    }

    i=zeros;
    j=n-1;

    while(i<j) {
        while (i<n && v[i] == 1) i++;
        while (j>-1 && v[j] == 2) j--;

        if (i>=j) break;
        cout<<"swap "<<i+1<<" "<<j+1<<endl;
        swap(v[i], v[j]);
        i++;
        j--;
    }

    cout<<"Sorted!";
    fflush(stdout);
}

int main() {
    solve();
    return 0;
}