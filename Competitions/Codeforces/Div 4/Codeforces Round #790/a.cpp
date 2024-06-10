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
        int h1 = (n+3)/3;
        int rest = (n+3)%3;
        int h2 = h1-1;
        int h3 = h2-1;
        if (rest)
        {
            h1++;
            rest--;
        }

        if (rest)
            h2++;

        cout<<h2<<" "<<h1<<" "<<h3;
        newL;


        newL;
    }


    return 0;
}