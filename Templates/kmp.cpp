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

        vector<int> kmp(string text,string pattern)
        {
            vector<int> ans;
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
                    ans.push_back(current - (pattern.length() -1 ));
                    matched_pos = pie[matched_pos-1];
                }
            }

            return ans;
        }
};