#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pp pair<char,int>

class Compare {
    public:
       bool operator()(pp a, pp b){
           if(a.first == b.first){
               return a.second < b.second;
           }
           return a.first > b.first;
      }
};

class Solution {
public:
    string clearStars(string s) {
        set<int> deleted;
        priority_queue<pp, vector<pp>, Compare> small;

        string ans = "";
        int n = s.size();

        for (int i=0 ; i<n ; i++) {
            if (s[i] == '*') {
                deleted.insert(i);
                pp t = small.top();
                small.pop();
                deleted.insert(t.second);
            } else {
                small.push({s[i], i});
            }
        }

        for (int i=0 ; i<n ; i++) {
            if (deleted.count(i)) continue;
            ans += s[i];
        }

        return ans;
    }
};