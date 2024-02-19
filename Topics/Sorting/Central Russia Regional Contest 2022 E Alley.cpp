#include<bits/stdc++.h>
#define pp pair<long double, long double>

using namespace std;

const double PI = 4 * atan(1);
long double circleIntersectionArea(long double r1, long double r2, long double d) {
    // d is the distance between the 2 centers
    if (r1 < r2) swap(r1, r2);
    if (d >= r1 + r2) return 0;
    if (d <= r1 - r2) return PI * r2 * r2;
    long double alpha = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    long double s = alpha * r2 * r2;
    long double t = r2 * r2 * sin(alpha) * cos(alpha);
    long double x = s - t;
    alpha = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    s = alpha * r1 * r1;
    t = r1 * r1 * sin(alpha) * cos(alpha);
    long double y = s - t;
    return x + y;
}

long double area(long double r) {
    return PI * r * r;
}

void solve() {
    int n, x, r;
    cin>>n;

    vector<pp> v;
    for (int i=0 ; i<n ; i++) {
        cin>>x>>r;
        v.push_back({x, r});
    }

    sort(v.begin(), v.end());

    long double ans = 0;
    for (int i=0 ; i<n ; i++) {
        ans += area(v[i].second);

        if (i+1 < n) {
            ans -= circleIntersectionArea(v[i].second, v[i+1].second, v[i+1].first - v[i].first);
        }
    }

    cout<<ans;
}

int main() {
    solve();
    return 0;
}
