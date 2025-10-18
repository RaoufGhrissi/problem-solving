#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

using namespace std;

int main() {
    FAST;
    freopen("a.txt", "r", stdin); // Read input from a.txt

    int n, m, q;
    cin >> n >> m >> q;

    int total_slots = n * 7 * 2 + 1;
    bool avail[m][total_slots];

    // Mark only valid weekday shifts as available (2 per day, 5 days/week)
    for (int e = 0; e < m; e++) {
        for (int week = 0; week < n; week++) {
            for (int day = 0; day < 7; day++) {
                for (int shift = 1; shift <= 2; shift++) {
                    int c = day<5;
                    int idx = week * 14 + 2 * day + shift;

                    cout<<idx<<" ";
                    avail[e][idx] = day < 5;
                }
            }
            cout<<endl;
        }
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int e, day;
            cin >> e >> day;
            e--;
            day--;

            int shift1 = day * 2 + 1;
            int shift2 = day * 2 + 2;

            avail[e][shift1] = 0;
            avail[e][shift2] = 0;
        } else if (type == 2) {
            int e, day, half;
            cin >> e >> day >> half;
            e--;
            day--;

            int shift = day * 2 + half;
            avail[e][shift] = 0;
        } else {
            int e1, e2, day, time;
            cin >> e1 >> e2 >> day >> time;
            e1--;
            e2--;
            day--;

            int s = 2 * day + 1;
            int t = total_slots;
            int cnt = 0, ans = -1;

            for (int i = s; i < t; i++) {
                if (avail[e1][i] && avail[e2][i]) {
                    cnt += 4;
                }

                if (cnt >= time) {
                    ans = i&1 ? (i / 2) + 1 : i/2;
                    break;
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
