#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pp pair<ll, string>

using namespace std;

int main() {
    ll t,n;
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> employeeTickets(n);
        vector<string> employeeTag(n);
        vector<string> employeeName(n);
        map<string,ll> tagTickets;
        map<string, int> idByName;

        for (int i=0 ; i<n ; i++)
            cin>>employeeTickets[i];

        for (int i=0 ; i<n ; i++) {
            cin>>employeeName[i];
            idByName[employeeName[i]] = i;
        }

        for (int i=0 ; i<n ; i++)
            cin>>employeeTag[i];

        for (int i=0 ; i<m ; i++) {
            string tag;
            ll cnt;

            cin>>tag>>cnt;
            tagTickets[tag] = cnt;
        }

        map<string, priority_queue<pp, vector<pp>, greater<pp>>> heapPerTag;
        map<string, ll> mxTicketsPerTag;
        for (int i=0 ; i<n ; i++) {
            heapPerTag[employeeTag[i]].push({employeeTickets[i], employeeName[i]});
            mxTicketsPerTag[employeeTag[i]] = max(mxTicketsPerTag[employeeTag[i]], employeeTickets[i]);
        }

        for (auto e:tagTickets) {
            string tag = e.first;
            
            if (!heapPerTag.count(tag)) // no employees available for this tag
                continue;

            ll cnt = e.second;
            ll mx = mxTicketsPerTag[tag];
            priority_queue<pp, vector<pp>, greater<pp>> &heap = heapPerTag[tag];
            
            while(cnt > 0 && heap.top().first < mx) {
                pp tp = heap.top();
                heap.pop();
                heap.push({tp.first+1, tp.second});
                cnt--;
            }

            if (cnt == 0) continue;

            ll q = cnt/heap.size();
            ll r = cnt%heap.size();

            if (q > 0) {
                int updates = heap.size(); // update all employees
                while (updates--) {
                    pp tp = heap.top();
                    heap.pop();
                    heap.push({tp.first+q, tp.second});
                }
            }

            if (r > 0) {
                // heap is already sorted by name if all values are equal, give the 1 to the first r employees
                while (r--) {
                    pp tp = heap.top();
                    heap.pop();
                    heap.push({tp.first+1, tp.second});
                }
            }

            while(!heap.empty()) {
                employeeTickets[idByName[heap.top().second]] = heap.top().first;
                heap.pop();
            }
        }

        for (int i=0 ; i<n ; i++) {
            cout<<employeeTickets[i]<<" ";
        }
    }

    return 0;
}