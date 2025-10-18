#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

int query(int i) {
    int ans;
    cout<<"? "<<i+1<<endl;
    cin>>ans;

    return ans;
}

void out(int a = -1, int b = -1) {
    if (a!=-1)
        cout<<"! "<<a<<" "<<b<<endl;
    else
        cout<<"! -1"<<endl;

    fflush(stdout);
}

void solve() {
#ifndef ONLINE_JUDGE
    //freopen("a.txt", "r", stdin);
#endif    
    int t;
    cin>>t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;

        if (n == 2*k) {
            out(k, k);
            continue;
        }   

        vector<int> a(k), b(k);
		for(int i = 0; i < k; i++)
		{
			a[i]=query(i);
			b[((n-i-1)%k)] = query(n-i-1);
		}

        int id = 0;
        while(id < k) {
            if (a[id] != b[id]) {
                break;
            }
            
            id++;
        }

        if (id==k) {
            out();
            continue;
        }

        int i = 0;
        int j = n;

        while(i<j) {
            int mid = (i+j+1)/2;

            int index = k*mid + id;
            if (index >= n-k) {
                j = mid-1;
            } else if (query(index) == a[id]) {
                i = mid;
            } else {
                j = mid-1;
            }
        }

        int lastA = max(k-1, k*i + id);

        bool unique = 1;
        vector<char> s = {'a'};
        int sz = 1;

        int aa = lastA;

        for (int i=lastA+1 ; i<min(lastA+1+k, n-k) ; i++) {
            sz = s.size();
            if (a[i%k] == b[i%k]) {
                if (s[sz-1] != 'u')
                    s.push_back('u');
            } else if (query(i) == a[i%k]) {
                if (s[sz-1] != 'a')
                    s.push_back('a');
                aa = i;
            } else {
                if (s[sz-1] != 'b')
                    s.push_back('b');
            }
        }

        s.push_back('b');

        for (int i=1 ; i<s.size()-1 ; i++) {
            if (s[i] == 'u' && s[i-1] != s[i+1]) {
                unique = 0;
                break;
            }
        }

        if (!unique) {
            out();
        } else {
            out(aa+1, n-(aa+1));
        }
        fflush(stdout);
    }
}

int main() {
    solve();
    return 0;
}