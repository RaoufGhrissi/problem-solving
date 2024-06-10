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
    ll t,n;
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);

        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        for (int i=0 ; i<n ; i++)
            cin>>b[i];

        cout<<b[0]-a[0]<<" ";
        for (int i=1 ; i<n ; i++)
        {
            if (a[i]>=b[i-1])
                cout<<b[i]-a[i];
            else
                cout<<b[i]-b[i-1];
            cout<<" ";
        }

        newL;
    }


    return 0;
}