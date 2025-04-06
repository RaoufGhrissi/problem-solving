#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& v) {
        int s=0;
        int e=1e9;

        while(s<e) {
            int mid = (s+e)/2;
            multiset<int> st(v.begin(), v.end());

            int diff = *st.rbegin() - *st.begin();
            while(diff > mid) {
                auto start = *st.begin();
                auto end = *st.rbegin();

                if ((start&1) && !(end&1)) {
                    int diff1 = start*2 ;
                } else if {

                } else if {

                } else {

                }

                int x = *it;
                if (!(x&1)) {
                    st.erase(x);
                    st.insert(x/2);
                } else {
                    auto it1 = st.begin();
                    int x = *it1;

                    if (x&1) {
                        st.erase(x);
                        st.insert(x*2);
                    }

                    diff = *st.rbegin() - *st.begin();
                }

                diff = *st.rbegin() - *st.begin();
            }

            if (diff > mid) {
                s = mid+1;
            } else {
                e = mid;
            }
        }

        return s;
    }
};

int main() {
    vector<int> v = {1,2,3,4};
    cout<<Solution().minimumDeviation(v);
}