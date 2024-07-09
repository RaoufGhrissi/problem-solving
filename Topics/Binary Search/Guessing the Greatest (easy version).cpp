#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
int t,n;
int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--)
    {
        cin>>n;
        int p;
        cout<<"? 1 "<<n;
        newL;
        cin>>p;


        int p1=-1;
        if (p!=n)
        {
            cout<<"? "<<p<<" "<<n;
            newL;
            cin>>p1;
        }

        if (p1 == p)
        {
            // max is in the right part of the array
            int l=p+1;
            int r=n;
            while(l<r)
            {
                int mid = (l+r)/2;
                int p2;
                cout<<"? "<<p<<" "<<mid;
                newL;
                cin>>p2;
                if (p2 != p)
                    l=mid+1;
                else
                    r=mid;
            }

            cout<<"! "<<l;
        }
        else
        {
            // max is in the left part of the array
            int l=1;
            int r=p-1;
            while(l<r)
            {
                int mid = (l+r+1)/2;
                int p2;
                cout<<"? "<<mid<<" "<<p;
                newL;
                cin>>p2;
                if (p2 != p)
                    r=mid-1;
                else
                    l=mid;
            }

            cout<<"! "<<l;
        }

        newL;
    }

    return 0;
}