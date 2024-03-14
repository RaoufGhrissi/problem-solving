#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

void get(int *i, int &j) {
  int a = 5;
}

#define ll long long
class Solution {
public:
    ll maximumStrength(vector<int>& v, int k) {
        int neg = k/2;
        int pos = k - neg;
        
        vector<int> vPos;
        vector<int> vNeg;
        
        ll ans = 0;
        for (auto &a:v) {
            if (a>0) {
                vPos.push_back(a);
            } else {
                vNeg.push_back(a);
            }
        }
        
        sort(vPos.begin(), vPos.end(), greater<int>());
        sort(vNeg.begin(), vNeg.end());
        
        while (vNeg.size() < neg) {
            int m = vPos[vPos.size()-1];
            vPos.pop_back();
            vNeg.push_back(m);           
        }
        
        while (vPos.size() < pos) {
            int m = vNeg[vNeg.size()-1];
            vNeg.pop_back();
            vPos.push_back(m);           
        }
        
        int p = vPos.size()-1;
        for (int i=1 ; i<=k ; i+=2) {
            ans += vPos[p--]*i; 
        }
        
        while(p>=0)
            ans += vPos[p--]*k;
        
        p = vNeg.size()-1;
        for (int i=2 ; i<k ; i+=2) {
            ans -= vNeg[p--]*(k-1); 
        }
        
        while(p>=0)
            ans += vNeg[p--]*neg;
        
        return ans;
    }
};


/*
    pos  =  1, 5,  7,   10,   20, 40
    neg   =  -100, -100, -60, -3, 0, 0
*/

int main() {
    int a = 5;
    int *p = &a;
    get(p, a);
    return 0;
}