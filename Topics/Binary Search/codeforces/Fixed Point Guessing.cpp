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

ll t,n,m,k;

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int l=1;
        int r=n;
        vector<int> v;
        while(l<r)
        {
            int mid=(l+r)/2;
            cout<<"? "<<l<<" "<<mid;
            newL;
            int len=mid-l+1;
            v.clear();
            v.resize(len);
            for (int i=0 ; i<len ; i++)
                cin>>v[i];

            int fix = 0;
            for (int i=0 ; i<len ; i++)
            {
                if (v[i]<=mid && v[i]>=l)
                    fix++;
            }

            if (fix%2==0)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }

        cout<<"? "<<l<<" "<<l;
        newL;
        int x;
        cin>>x;
        cout<<"! "<<x;

        newL;
    }


    return 0;
}