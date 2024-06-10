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

        bool yes=1;
        int zeros=0;
        int diff;
        for (int i=0 ; i<n ; i++)
        {           
            if (a[i]<b[i])
            {
                yes=0;
                break;
            }
            if (!b[i])
                zeros++;
            
            if (a[i]>=b[i] && b[i])
                diff=a[i]-b[i];
        }

        if (!yes)
        {
            cout<<"NO";
            newL;
            continue;
        }

        if (zeros == n)
        {
            cout<<"YES";
            newL;
            continue;
        }

        for (int i=0 ; i<n ; i++)
        {
            if((b[i] && a[i]-b[i]!=diff) || (!b[i] && a[i]>diff))
            {
                yes=0;
                break;
            }
        }

        if (!yes)
        {
            cout<<"NO";
            newL;
            continue;
        }
        else
        {
            cout<<"YES";
            newL;
            continue;
        }

        newL;
    }


    return 0;
}