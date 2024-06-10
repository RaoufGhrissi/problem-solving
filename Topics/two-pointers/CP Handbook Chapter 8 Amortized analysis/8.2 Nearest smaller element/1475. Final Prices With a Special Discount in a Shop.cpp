class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<pair<int,int>> s;
        int n = v.size();
        for (int i=0 ; i<n ; i++)
        {
            while(!s.empty() && s.top().first >= v[i])
            {
                auto top = s.top();
                s.pop();
                int pos = top.second;
                v[pos] -= v[i];
            }
            
            s.push({v[i], i});
        }
        
        return v;
    }
};