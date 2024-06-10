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

using namespace std;

int main()
{
    ll t,n,k;
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        string ch;
        cin>>ch;

        vector<int> cum(n,0);

        for (int i=0 ; i<n ; i++)
        {
            cum[i]=ch[i]=='B';
        }

        for (int i=1 ; i<n ; i++)
            cum[i]+=cum[i-1];

        int maxx=-1;
        int res=0;
        for (int i=0 ; i<n ; i++)
        {
            if (i+k-1<n)
            {
                res=cum[i+k-1];
                if (i>0)
                    res-=cum[i-1];
                maxx=max(maxx,res);
            }
        }

        cout<<k-maxx;

        newL;
    }


    return 0;
}