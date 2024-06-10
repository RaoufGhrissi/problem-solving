#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a,b;

int query(int l,int r)
{
    int opening = 0;
    int ans=0;

    for (int i=l ; i<=r ; i++)
    {
        if (s[i]=='(')
            opening++;
        else
        {
            if (opening == 0)
                continue;

            opening--;
            ans+=2;
        }
    }

    return ans;
}

int main()
{
    //freopen("a.txt", "r", stdin);
    cin>>s>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<query(--a,--b)<<'\n';
    }

    return 0;
}
