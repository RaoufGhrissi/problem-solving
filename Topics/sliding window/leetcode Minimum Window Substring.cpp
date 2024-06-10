#include <bits/stdc++.h>
//https://leetcode.com/problems/minimum-window-substring/
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = 0;
        map<char, int> occ, actual, counter;
        for (auto &c:t)
            occ[c]++; 

        int i=0;
        int j=0;
        int n=s.size();
        int fi=-1, fs=1e9;

        while(j<n) {
            actual[s[j]]++;
            if (occ.count(s[j]) && actual[s[j]] >= occ[s[j]])
                counter[s[j]]=1;
            j++;

            while(counter.size() == occ.size() && i<j) {
                if (fs > j-i) {
                    fs = j-i;
                    fi = i;
                }
                actual[s[i]]--;
                if (occ.count(s[i]) && actual[s[i]] < occ[s[i]]) {
                    counter.erase(s[i]);
                }

                i++;
            }
        }

        return fi == -1 ? "" : s.substr(fi, fs);
    }
};

int main() {
    cout<<Solution().minWindow("ADOBECODEBANC", "ABC");
}