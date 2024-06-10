#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& v) {
        map<int,int> occ;
        
        for (auto &a:v) {
            occ[a]++;
            if (occ[a] > 2)
                return 0;
        }
        
            
        return 1;
    }
};