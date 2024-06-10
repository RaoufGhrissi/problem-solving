class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int n = v.size();
        double sm = 0;
        double ans = 0;
        for (int i=0 ; i<k ; i++)
            sm += v[i];
        
        ans = sm/k;
        
        int i=0;
        while(i+k<n)
        {
            sm -= v[i];
            sm += v[i+k];
            ans = max(ans, sm/k);
            i++;
        }
        
        return ans;
    }
};