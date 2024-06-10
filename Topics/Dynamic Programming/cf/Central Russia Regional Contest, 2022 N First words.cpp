#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

class KMP {
    public:
        int *pre_kmp(string pattern)
        {
            int size = pattern.size();
            int *pie=new int [size];
            pie[0] = 0;
            int k=0;
            for(int i=1;i<size;i++)
            {
                while(k>0 && pattern[k] != pattern[i] )
                {
                    k=pie[k-1];
                }
                if( pattern[k] == pattern[i] )
                {
                    k=k+1;
                }
                pie[i]=k;
            }
            
            return pie;
        }

        void kmp(string text, string pattern, map<int, vector<int>> &mp)
        {
            int* pie=pre_kmp(pattern);
            int matched_pos=0;
            for(int current=0; current< text.length(); current++)
            {
                while (matched_pos > 0 && pattern[matched_pos] != text[current] )
                    matched_pos = pie[matched_pos-1];
                    
                if(pattern[matched_pos] == text[current])
                    matched_pos = matched_pos+1;
                    
                if( matched_pos == (pattern.length()) )
                {
                    int index = current - (pattern.length() -1 );
                    mp[index].push_back(pattern.size());
                    matched_pos = pie[matched_pos-1];
                }
            }
        }
};

const int N = 1e5 + 7;
int dp[N];

bool rec(int i, int &n, map<int, vector<int>> &mp) {
    if (i == n)
        return 1;

    if (!mp.count(i))
        return 0;

    if (dp[i] != -1) return dp[i];

    dp[i] = 0;

    for (auto &l:mp[i]) {
        dp[i] |= rec(i + l, n, mp);
    }

    return dp[i];
}

void solve() {
    int n;
    cin>>n;

    memset(dp, -1, sizeof dp);

    KMP kmp = KMP();
   
    vector<string> v(n);
    for (int i=0 ; i<n ; i++) {
        cin>>v[i];
    }

    string s;
    cin>>s;

    map<int, vector<int>> mp;
    for (int i=0 ; i<n ; i++)
        kmp.kmp(s, v[i], mp);

    int m = s.size();
    if (rec(0, m, mp)) {
        cout<<"YES";
    } else
        cout<<"NO";
}

int main() {
    solve();
    return 0;
}