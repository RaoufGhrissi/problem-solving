#include <bits/stdc++.h>

using namespace std;

const int N=50;
int vis[N][N];

int n,m;

int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};

bool canMove(int i, int j)
{
    return i>-1 && i<n && j>-1 && j<m;
}

void dfs(int i, int j)
{
    vis[i][j]=true;
    for (int c=0 ; c<4 ; c++)
    {
        int ci=i+di[c];
        int cj=j+dj[c];

        if (!vis[ci][cj] && canMove(ci,cj))
            dfs(ci,cj);
    }
}

int main(){

    return 0;
}
