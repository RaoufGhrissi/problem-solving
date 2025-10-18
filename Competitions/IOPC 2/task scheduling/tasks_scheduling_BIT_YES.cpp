#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pp pair<ll, string>

using namespace std;

class BIT {
    public:
        vector<int> tree;
        int n;

        BIT() {}

        BIT(int k) {
            n = k;
            tree.clear();
            tree.resize(n);
        }   
        
        void update(int x, int val)
        {
            while(x<n)
            {
                tree[x] += val;
                x+=(x)&(-x);
            }
        }

        int get(int x)
        {
            int res=0;
            while(x>0)
            {
                res += tree[x];
                x-=(x)&(-x);
            }

            return res;
        }
};

int main() {
    ll t,n;
    FAST;
    freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--) {
        int n, m, q;
        cin >> n >> m >> q;

        BIT bits[m][m];

        for (int emp1=0 ; emp1<m ; emp1++) {
            for (int emp2=emp1+1 ; emp2<m ; emp2++) {
                bits[emp1][emp2] = BIT(n*7*2 + 1); // n weeks * 7 days * 2 shifts / day
                for (int week=0 ; week<n ; week++) {
                    for (int day=0 ; day<7 ; day++) {
                        for (int shift=1 ; shift<=2 ; shift++) {
                            int c = day < 5 ? 4 : 0;
                            //cout<<week*14 + 2*day + shift<<" = "<<c<<" ";
                            bits[emp1][emp2].update(week*14 + 2*day + shift, day < 5 ? 4 : 0);
                        }
                    }
                    //cout<<endl;
                }
            }
        }
        
        for (int i=0 ; i<q ; i++) {
            int type;
            cin>>type;

            if (type == 1) {
                int e, day;
                cin>>e>>day;
                e--;
                day--;
                for (int e2 = 0 ; e2<m ; e2++) {
                    if (e != e2) {
                        int x = min(e, e2);
                        int y = max(e, e2);
                        // avoid updating a range with is already off
                        int r = day*2 + 1;
                        int l = r>1 ? bits[x][y].get(r-1) : 0;
                        if (bits[x][y].get(r) - l == 4)
                            bits[x][y].update(r, -4); // morning
                        
                        r = day*2 + 2;
                        l = bits[x][y].get(r-1);
                        if (bits[x][y].get(r) - l == 4)
                            bits[x][y].update(r, -4); // afternoon
                    }
                }
            } else if (type == 2) {
                int e, day, half;
                cin>>e>>day>>half;
                e--;
                day--;

                for (int e2 = 0 ; e2<m ; e2++) {
                    if (e != e2) {
                        int x = min(e, e2);
                        int y = max(e, e2);
                        // avoid updating a range with is already off
                        int r = day*2 + half;
                        int l = r>1 ? bits[x][y].get(r-1) : 0;
                        if (bits[x][y].get(r) - l == 4)
                            bits[x][y].update(r, -4);
                    }
                }

            } else {
                int e1, e2, day, time;
                cin>>e1>>e2>>day>>time;

                e1--;
                e2--;
                day--;

                int x = min(e1, e2);
                int y = max(e1, e2);

                int s = 2*day + 1;
                int e = n*7*2;

                int l = s>1 ? bits[x][y].get(s-1) : 0;

                if (bits[x][y].get(e) - l < time) {
                    cout<<-1<<endl;
                    continue;
                }

                while(s<e) {
                    int mid = (s+e)/2;
                    int cnt = bits[x][y].get(mid) - l;

                    if (cnt < time) {
                        s = mid+1;
                    } else if (cnt >= time) {
                        e = mid;
                    }
                }

                int res = s&1 ? s/2 + 1 : s/2;
                cout<<res<<endl;
            }
        }
    }

    return 0;
}