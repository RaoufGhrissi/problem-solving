#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> ans;
    void backtrack(int &actual, int &n) {
        int start = !actual ? 1 : 0;
        for (int i=start ; i<10 ; i++) {
            actual *= 10;
            actual += i;
            if (actual <= n) {
                ans.push_back(actual);
                backtrack(actual, n);
            }
            
            actual -= i;
            actual /= 10;
        }
    }
    vector<int> lexicalOrder(int n) {
        int a = 0;
        backtrack(a, n);
        return ans;
    }
};