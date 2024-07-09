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
ll t,n,m;

const int N = 1e6 + 5;

struct node{
    int r;
    int l;
    int d;
    int u;

    node()
    {
        r=0;l=0;d=0;u=0;
    }

    node(int _r,int _l, int _d,int _u)
    {
        r=_r;
        l=_l;
        d=_d;
        u=_u;
    }
};

node a[N];

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        string c;
        cin>>c;

        int rmax=0;
        int lmin=0;
        int umin=0;
        int dmax=0;

        int x,y;

        int xx=0,yy=0;
        for (int i=0 ; i<c.size() ; i++)
        {
            if (c[i]=='R')
                yy++;
            else if (c[i]=='L')
                yy--;

            rmax=max(rmax, yy);
            lmin=min(lmin, yy);

            if (c[i]=='D')
                xx++;
            else if (c[i]=='U')
                xx--;

            dmax=max(dmax, xx);
            umin=min(umin, xx);

            a[i]=node(rmax, lmin, dmax, umin);
        }

        int nn=c.size();


            // count y
            int qy=-1;

            //for (int i=0 ; i<m ; i++)
            {
                int l=0;
                int r=nn-1;
                while(l<r)
                {
                    int mid=(l+r+1)/2;
                    node qr = a[mid];
                    int rmax=qr.r;
                    int lmin=qr.l;

                    if (abs(lmin)+rmax<m)
                        l=mid;
                    else
                        r=mid-1;
                }
                if (abs(a[l].l)+a[l].r<m)
                    qy=max(qy, l);
            }

            // count x
            int qx=-1;

            //for (int i=0 ; i<n ; i++)
            {
                int l=0;
                int r=nn-1;
                while(l<r)
                {
                    int mid=(l+r+1)/2;
                    node qr = a[mid];
                    int dmax=qr.d;
                    int umin=qr.u;

                    if (abs(umin)+dmax<n)
                        l=mid;
                    else
                        r=mid-1;
                }
                if (abs(a[l].u)+a[l].d<n)
                    qx=l;
            }


        int qans = min(qy, qx);
        qans++;
        if (!qans)
        {
            cout<<1<<" "<<1;
            newL;
            continue;
        }

        node qr=a[qans-1];
        rmax=qr.r;
        lmin=qr.l;
        umin=qr.u;
        dmax=qr.d;
        y = m-rmax;
        x = n-dmax;
        cout<<x<<" "<<y;
        newL;
    }


    return 0;
}