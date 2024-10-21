#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define Pair pair<ll,ll>
#define iPair pair<int,int>
#define newL cout<<endl
#define ll_max 1e18
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define forn(j,n) for (int i=j ; i<n ; i++)
#define inf (int)1e9

using namespace std;

map<char, vector<int>> nxt = {
    {'R', {0, 1}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
    {'D', {1, 0}},
};

int main()
{
    ll t,n;
    FAST;
    freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n;
        string s;

        cin>>s;

        map<pair<int,int>, int> mp;

        int x = 0;
        int y = 0;

        mp[{x, y}] = -1;
        int mi = inf;
        int ax = -1;
        int ay = -1;

        for (int i=0 ; i<n ; i++) {
            x += nxt[s[i]][0];
            y += nxt[s[i]][1];

            if (mp.count({x, y})) {
                int pos = mp[{x, y}];

                if (mi > (i-pos)) {
                    ax = pos+2;
                    ay = i+1;
                    mi = i-pos;
                }
            }

            mp[{x, y}] = i;
        }

        if (mi < inf)
            cout<<ax<<" "<<ay;
        else
            cout<<-1;

        newL;
    }


    return 0;
}