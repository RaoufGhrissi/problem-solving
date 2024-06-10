#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int get(char a, char b) {
        if (a>b)
            swap(a, b);
        
        return min(b-a, a-'a' + 1 + 'z' - b);
    }

    string getSmallestString(string s, int k) {
        string t = "";
        for (auto &ss:s) {
            for (char c='a' ; c<='z' ; c++) {
                if (get(c, ss) <= k) {
                    k -= get(c, ss);
                    t += c;
                    break;
                }
            }
        }

        return t;
    }
};
