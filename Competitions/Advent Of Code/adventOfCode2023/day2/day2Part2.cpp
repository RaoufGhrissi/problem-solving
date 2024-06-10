#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delimiter){
    vector<string> list;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

unordered_map<string, int> mx = {
    {"red", 0},
    {"green", 0},
    {"blue", 0},
};

int solve() {
    ifstream file("a.txt");
    int ans = 0;
    for (string s; getline(file, s);) {
        vector<string> game = split(s, ": ");
        int id = stoi(split(game[0], " ")[1]);

        game = split(game[1], "; ");
        int n = game.size();
        unordered_map<string, int> mx;
        for (int i=0 ; i<n ; i++) {
            vector<string> parts = split(game[i], ", ");
            
            for (auto &part:parts) {
                vector<string> x = split(part, " ");
                int cnt = stoi(x[0]);
                string color = x[1];

                mx[color] = max(mx[color], cnt);
            }
        }

        int res = 1;
        for (auto &c:mx)
            res *= c.second;

        ans += res;
    }

    return ans;
    
}

int main() {
    cout<<solve();
    return 0;
}