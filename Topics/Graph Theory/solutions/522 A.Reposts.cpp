#include <bits/stdc++.h>

using namespace std;
unordered_map<string,bool> visited;
unordered_map<string,vector<string>> graph;
vector<string> roots;
vector<string> strings;
unordered_map<string,int> level;
unordered_map<string,int> maxLevel;
vector<string> a;
vector<string> b;

int n;
string s,ch;
int ans=1;

void dfs(string parent)
{
    visited[parent]=true;

    for (auto child:graph[parent])
    {
        level[child]=level[parent]+1;
        maxLevel[child]=max(maxLevel[child], level[child]);
        ans = max(ans,maxLevel[child]);

        if (!visited[child])
        {
            dfs(child);
        }
    }

    return;
}

int main()
{
cin>>n;
cin.ignore();

for (int i=0 ; i<n ; i++)
{
    getline(cin , s) ;
    strings.clear();
    ch="";
    for (int j=0 ; j<s.size() ; j++)
    {
        if (s[j]==' ')
        {
            strings.push_back(ch);
            ch="";
        }
        else
            ch+=toupper(s[j]);
    }

    graph[strings[0]].push_back(ch);
    a.push_back(strings[0]);
    b.push_back(ch);
    visited[strings[0]]=false;
    visited[ch]=false;
}

for (auto i:a)
{
    bool isRoot=true;
    for (auto j:b)
    {
        if (!j.compare(i))
        {
            isRoot=false;
            break;
        }
    }

    if (isRoot)
    {
        roots.push_back(i);
    }

}

for (auto i:roots)
{
    visited.clear();
    level[i]=1;
    dfs(i);
}

cout<<ans;

    return 0;
}
