#include <bits/stdc++.h>

using namespace std;

bool isV(char c)
{
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int main(){

freopen("a.txt","r",stdin);
freopen("a.out","w",stdout);

int n;
string s;
cin>>n;
for (int cas=1 ; cas<=n ; cas++)
{
    cin>>s;
    int maxV=0,tV=0,maxC=0,tC=0;
    int tab[26];
    memset(tab, 0, sizeof(tab));
    for (int i=0 ; i<s.size() ; i++)
    {
        tab[s[i]-'A']++;
    }

    for (int i=0 ; i<26 ; i++)
    {
        if (isV(i+'A'))
        {
            maxV = max(maxV, tab[i]);
            tV+=tab[i];
        }
        else
        {
            maxC = max(maxC, tab[i]);
            tC+=tab[i];
        }
    }

    cout<<"Case #"<<cas<<": "<<min((tV-maxV)*2+tC, (tC-maxC)*2+tV)<<'\n';
}

    return 0;
}
