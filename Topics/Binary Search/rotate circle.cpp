#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {270, 301, 301, 302, 50, 70, 100};

    int n = v.size();

    int ans = 1e9;

    sort(v.begin(), v.end());

    vector<int> cum = v;

    for (int i=1 ; i<n ; i++)
        cum[i] += cum[i-1];

    for (int val=0 ; val<360 ; val++) {
        int i = 0;
        int j = n-1;

        while(i<j) {
            int mid = (i+j+1)/2;

            if (v[mid] >= val) {
                j = mid-1;
                continue;
            }

            int inc = val - v[mid];
            int dec = v[mid] + 360 - val;

            if (inc > dec) {
                i = mid;
            } else {
                j = mid-1;
            }
        }

        int l = -1;

        // ynajem ykoun ntal3ouh ahsen
        int inc = val - v[i];
        int dec = v[i] + 360 - val;

        if (inc > dec)
            l = i;

        i = 0;
        j = n-1;

        while(i<j) {
            int mid = (i+j)/2;

            if (val > v[mid]) {
                i = mid+1;
                continue;
            }

            int inc = 360 - v[mid] + val;
            int dec = v[mid] - val;

            if (inc < dec) {
                j = mid;
            } else {
                i = mid+1;
            }
        }

        int r = -1;

        inc = 360 - v[i] + val;
        dec = v[i] - val;

        if (inc < dec) 
            r = i;

        
        int tot = 0;

        // eli 3al isar w lezem yesgharou 

        if (l != -1) {
            tot += cum[l] + (360 - val)*(l+1);
        }

        // eli 3al imin w lezem yekbarou
        if (r != -1) {
            int p = cum[n-1];
            if (r)
                p -= cum[r-1];

            int cnt = n-r;
            tot += cnt*360 - p;
            tot += cnt*val;
        }

        int i1 = l != 1 ? l+1 : 0;
        int j1 = r != -1 ? r-1 : n-1;

        i = i1;
        j = j1;

        int cnt = j-i+1;
        if (v[i] > val) {
            //lezem kol yahbtou
            int res = cum[j];
            if (i)
                res -= cum[i-1];

            tot += res - cnt*val;
            ans = min(ans, tot);
            continue; 
        } else if (v[j] < val) {
            // eli lezem yekbarou
            int res = cum[j];
            if (i)
                res -= cum[i-1];

            tot += cnt*val - res;
            ans = min(ans, tot);
            continue;
        }

        while(i<j) {
            int mid = (i+j+1)/2;

            if (v[mid] < val)
                i = mid;
            else
                j = mid-1;
        }

        //eli lezem yesgharou
        cnt = j1 - i;
        int res = cum[j1] - cum[i];
        tot += res - cnt*val;
        
        // eli lezem yekbarou
        res = cum[i];
        cnt = i-i1+1;
        if (i1)
            res -= cum[i1-1];

        tot += cnt*val - res;
        ans = min(ans, tot);
    }

    cout<<ans<<endl;

    return 0;
}