#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int> nums) {
            int l = 0, r = 0, currSum = 0, n = nums.size(), res = INT_MAX;

            while(r < n) {
                if (currSum + nums[r] < target) {
                    currSum += nums[r];
                    r++;
                } else {
                    res = min(res, r - l + 1);
                    currSum -= nums[l];
                    l++;
                }
            }
            return res == INT_MAX ? 0 : res;
        }
};

int main() {
    vector<int> v = {2,3,1,2,4,3};
    cout<<Solution().minSubArrayLen(7, v);
}