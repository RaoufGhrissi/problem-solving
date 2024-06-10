#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        map<int, int> balls; // kol koura chnowa actual color
        map<int, int> cols; // kol color 9adecj men balls mlawnethom
        
        vector<int> ans;
        
        for (auto &qq:q) {
            int ball = qq[0];
            int col = qq[1];
            
            if (balls.count(ball)) { // mlawna deja wala
                cols[balls[ball]]--;
                if (!cols[balls[ball]]) // idha 0 fama ken l koura adhika eli mlawanha, donc na7ih loun
                    cols.erase(balls[ball]); // loun na7ih
            }
            
            balls[ball] = col;
            cols[col]++;
                
            ans.push_back(cols.size());
        }
        
        return ans;
    }
};