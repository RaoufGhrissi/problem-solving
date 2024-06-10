#include <bits/stdc++.h>
#define capacity 100100

using namespace std;
int a,b,c,d,n,m;
bool vis[capacity];
queue < int > q;

bool check(int x)
{
   return  !vis[x] && x>-1 && x<capacity; 
}
void append(int x)
{
        if(check(x+a)) { q.push(x+a); vis[x+a] = true ; }
        if(check(x-b)) { q.push(x-b); vis[x-b] = true ; }
        if(check(x*c)) { q.push(x*c); vis[x*c] = true ; }
        if(x%d==0 && d!=0)
        {
           if(check(x/d)) { q.push(x/d); vis[x/d] = true ; }
        }
}
void bfs(int i)
{
    q.push(i);
    vis[i] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if(v==m) break;
        append(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d>>n>>m;
    memset(vis,false,sizeof vis);
    bfs(n);
    while(!q.empty()) q.pop();
    cout<<vis[m];
    return 0 ;
}
