#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> letters = {
    {"one", 1}, {"two", 2}, {"six", 6},
    {"four", 4}, {"five", 5}, {"nine", 9},
    {"three", 3}, {"seven", 7}, {"eight", 8},
};

int solve() {
    ifstream file("a.txt");
    int ans = 0;
    for (string s; getline(file, s);) {
        int first = -1;
        int last;
        int n = s.size();
        for (int i=0 ; i<n ; i++) {
            if (isdigit(s[i])) {
                if (first == -1)
                    first = s[i]-'0';

                last = s[i]-'0';
            } else {
                for (auto &key:letters) {
                    int size = key.first.size();
                    string sub = s.substr(i, size);
                    if (sub == key.first) {
                        if (first == -1)
                            first = key.second;

                        last = key.second;
                    }
                }
            } 
            
        }

        if (first != -1)
            ans += first*10+last;
    }

    return ans;
    
}

int main() {
    cout<<solve();
    return 0;
}