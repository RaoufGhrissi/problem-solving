#include<bits/stdc++.h>

using namespace std;
const int N=500;
char mat[N][N];
int n,m,k,si,sj,t=0;
bool stop = false;
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};

void bfs(int i, int j)
{
    mat[i][j]='1';
    t--;
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
            if (t==0)
                return;
            int dx=xi+di[c];
            int dy=xj+dj[c];
            if (dx>=n || dy>=m || dx<0 || dy<0)
                continue;
            if (mat[dx][dy] == '.')
            {
                qi.push(dx);
                qj.push(dy);
                mat[dx][dy]='1';
                t--;
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<m ; j++)
        {
            cin>>mat[i][j];
            if (mat[i][j] == '.')
            {
                t++;
                if (!stop){
                    si=i;
                    sj=j;
                    stop = true;
                }
            }
        }
    }
    t-=k;
    bfs(si,sj);
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<m ; j++)
        {
            if (mat[i][j]=='1')
                cout<<".";
            else if (mat[i][j]=='#')
                cout<<"#";
            else
                cout<<"X";
        }
        cout<<'\n';
    }
	return 0;
}
