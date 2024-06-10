#include <bits/stdc++.h>

using namespace std;

const int N=50;
int vis[N][N];

int n,m;

int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};

void bfs(int i, int j)
{
    queue<int> qi;
    queue<int> qj;
    qi.push(i);
    qj.push(j);
    while(!qi.empty())
    {
        int xi=qi.front();
        qi.pop();
        int xj=qj.front();
        qj.pop();
        for (int c=0;c<4;c++)
        {
            int x=xi+di[c];
            int y=xj+dj[c];
            if (x>=n || y>=m || x<0 || y<0)
                continue;

            if (!vis[x][y])
            {
                qi.push(x);
                qj.push(y);
            }
        }
    }
}

int main(){

    return 0;
}
