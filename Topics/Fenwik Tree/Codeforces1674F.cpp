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

int n,m;
const int N = 1e6 +7;
int tree[N];

void update(int x, int val)
{
    while(x<=N)
    {
        tree[x]+=val;
        x+=(x)&(-x);
    }
}

int get_sum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=tree[x];
        x-=(x)&(-x);
    }

    return res;
}

int matrix_to_array(int i, int j)
{
    return j*n + i;
}

int main()
{
    int t,q;
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--)
    {
        cin>>n>>m>>q;
        char mat[n][m];
        int etoiles=0;
        int index;
        for (int i=0 ; i<n ; i++)
        {
            string s;
            cin>>s;
            for (int j=0 ; j<m ; j++)
                mat[i][j]=s[j];
        }

        memset(tree, 0, sizeof(tree));
        for (int j=0 ; j<m ; j++)
        {
            for (int i=0 ; i<n ; i++)
            {
                index=matrix_to_array(i,j)+1;
                //cout<<index<<endl;
                if (mat[i][j]=='.')
                    continue;
                else
                {
                    etoiles++;
                    update(index,1);
                }
            }
        }

        int a,b;
        while(q--)
        {
            cin>>a>>b;
            a--;b--;
            index = matrix_to_array(a,b)+1;
            if (mat[a][b]=='.')
            {
                mat[a][b]='*';
                etoiles++;
                update(index,1);
            }
            else
            {
                mat[a][b]='.';
                etoiles--;
                update(index,-1);
            }
            int g = get_sum(etoiles);
            cout<<etoiles-get_sum(etoiles);
            newL;
        }
    }


    return 0;
}