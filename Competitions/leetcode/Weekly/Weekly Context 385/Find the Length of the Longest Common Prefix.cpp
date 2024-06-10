#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> v1;
        set<string> v2;
        int ans = 0;
        
        for (auto &a:arr1) {
            string s = "";
            string b = to_string(a);
            for (auto &c:b) {
                s += c;
                v1.insert(s);
            }
        }
            
        
        for (auto &a:arr2) {
            string s = "";
            string b = to_string(a);
            for (auto &c:b) {
                s += c;
                v2.insert(s);
            }
        }
          
        
        for (auto &a:v1) {
            string x = "";
            int l = 0;
            for (auto &c:a) {
                x += c;
                l++;
                if (v2.count(x))
                    ans = max(ans, l);
            }
        }
        
        for (auto &a:v2) {
            string x = "";
            int l = 0;
            for (auto &c:a) {
                x += c;
                l++;
                if (v1.count(x))
                    ans = max(ans, l);
            }
        }
        
        return ans;
    }
};