#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        for (int i=30 ; i>-1 ; i--) {
            if (n&(1<<i)) {
                return (1<<(i+1)) - 1;
            }
        }

        return 1;
    }
};