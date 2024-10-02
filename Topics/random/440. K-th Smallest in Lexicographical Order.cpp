#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getPosition(string &str, int &n) {
        int ans = 0;
        int s = 1, r = 0;
        int sz = str.size();
        int index = 0;

        while(s <= n) {
            if (index < sz-1) {
                r = r*10 + (str[index]-'0');
            } else if (index == sz-1) {
                r = stoi(str)-1;
                if (r < s) break;
            } else {
                r = r*10 + 9;
            }

            index++;
            ans += min(r, n)-s+1;
            s *= 10;
        }

        return ans;
    }

    int findKthNumber(int nb, int k) {
        string ans = "";
        k--;

        while(1) {
            int s = ans.empty() ? 1 : 0;
            for (int i=s ; i<10 ; i++) {
                string cpy = ans + char(i + '0');
                
                int res = getPosition(cpy, nb);
                if (res == k)
                    return stoi(cpy);
                else if (res > k) {
                    ans += char(i-1+'0');
                    break;
                }
            }
        }
        
        return stoi(ans);
    }
};

int main() {
    int n = 1000;
    string s = "999";
    cout<<Solution().getPosition(s, n);
    cout<<Solution().findKthNumber(1000, 1000);
}