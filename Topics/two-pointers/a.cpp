#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, string &s) {
        while(i<j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return 0;
            }
        } 

        return 1;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        bool used = 0;
        int i = 0;
        int j = n-1;

        while(i<j) {
            if (s[i] != s[j]) {
                return isValid(i+1, j, s) | isValid(i, j-1, s);
            } else {
                i++;
                j--;
            }
        }

        return 1;
    }
};

int main() {
    Solution sol;
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    cout << sol.validPalindrome(s) << endl;
    return 0;
}