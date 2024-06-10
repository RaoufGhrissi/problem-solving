#include <bits/stdc++.h>
using namespace std;

vector<string> dict;

int f(int n, string ch, int N)
{
    if (ch.size() == 0)
        return 1;
    else if (n == 0)
        return 0;
    else
    {
        int p = ch.rfind(dict[n-1]);
        if ( p != -1 && p == ch.size()-dict[n-1].size())
        {
            return f(N, ch.erase(p, dict[n-1].size())) + f(n-1, ch);
        }
        else
            return f(n-1, ch);
    }
}

int main() {
        int n;
        cin>>n;
        dict.clear();
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<f(n, line)<<"\n";
        return 0;
}

