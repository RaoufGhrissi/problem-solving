#include<bits/stdc++.h>
using namespace std;

const int N = 50;
bool vis[N][N];
int n,m;
char tab[N][N];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool dfs(int i, int j, int pi, int pj)
{
    vis[i][j]=true;
    for (int c=0 ; c<4 ; c++)
    {
        int di=i+dx[c];
        int dj=j+dy[c];

        if (di>n || di<0 || dj>m || dj<0)
            continue;

        if (tab[di][dj] != tab[i][j])
            continue;

        if (vis[di][dj] && (di!=pi || dj!=pj))
            return true;

        if (!vis[di][dj] && dfs(di,dj,i,j))
            return true;
    }
    return false;
}

bool isCycle()
{
    memset(vis,false,sizeof(vis));
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<m ; j++)
            {
                if (!vis[i][j])
                {
                    if(dfs(i,j,-1,-1))
                        return true;
                }
            }
    }

    return false;
}

int main(){
cin>>n>>m;

for (int i=0 ; i<n ; i++)
{
    for (int j=0 ; j<m ; j++)
        cin>>tab[i][j];
}
    if (isCycle())
        cout<<"Yes";
    else
        cout<<"No";
}
