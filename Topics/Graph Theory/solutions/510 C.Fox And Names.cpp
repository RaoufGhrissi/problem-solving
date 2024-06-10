#include<bits/stdc++.h>

using namespace std;
int n;
string s;
vector<string> v;
vector<char> res;
vector<vector<int>> graph;
bool vis[26];
bool isAncestor[26];

bool isCyclic(int parent)
{
    vis[parent] = true;
    isAncestor[parent] = true;

    for (auto child:graph[parent])
    {
        if ((!vis[child] && isCyclic(child)) || isAncestor[child])
            return true;
    }

    isAncestor[parent] = false;
    res.push_back(parent + 'a');

    return false;
}

bool isGraphCyclic()
{
    memset(vis, false, sizeof(vis));
    memset(isAncestor, false, sizeof(isAncestor));
    for (int i=0; i<26 ; i++)
    {
        if (!vis[i] && isCyclic(i))
            return true;
    }

    return false;
}

int main(){
    graph.clear();
    graph.resize(26);
    cin>>n;
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }

    n=v.size();

    for (int i=0;i<n-1;i++)
    {
        string s1=v[i];
        int ss1=s1.size();
        string s2=v[i+1];
        int ss2=s2.size();
        bool isMatch = true;
        for (int j=0 ;j<min(ss1,ss2); j++)
        {
            if (s1[j] == s2[j])
                continue;

            isMatch = false;
            graph[s2[j]-'a'].push_back(s1[j]-'a');
            break;
        }
        if (isMatch && ss1>ss2)
        {
            cout<<"Impossible";
            return 0;
        }
    }

    if (isGraphCyclic())
    {
        cout<<"Impossible";
        return 0;
    }

    for (int i=0 ; i<26 ; i++)
            cout<<res[i];

return 0;

}
