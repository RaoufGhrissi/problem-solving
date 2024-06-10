#include <bits/stdc++.h>
#define pp pair<int,int>
#define inf 1e9

using namespace std;

int dist[4096][4096];

int bfs(int s1, int s2, int &n) {
   queue<vector<int>> q;
   q.push({0, s1, s2});

   for (int i=0 ; i<4096 ; i++) {
      for (int j=0 ; j<4096 ; j++) {
         dist[i][j] = inf;
      }
   }

   dist[s1][s2] = 0;

   pp dest = {0, 0}; // stack 3 t3abet, S1 w s2 ferghou zouz

   while(!q.empty()) {
      vector<int> t = q.front();
      q.pop();
      int d = t[0];
      s1 = t[1];
      s2 = t[2];

      int s3 = -1;
      for (int i=0 ; i<n ; i++) {
         int mask = 1<<i;
         if (!(mask&s1) && !(mask&s2)) {
            s3 = i;
            break;
         }
      }

      int t1 = -1;
      for (int i=0 ; i<n ; i++) {
         int mask = 1<<i;
         if (mask&s1) {
            t1 = i;
            break;
         }
      }

      int t2 = -1;
      for (int i=0 ; i<n ; i++) {
         int mask = 1<<i;
         if (mask&s2) {
            t2 = i;
            break;
         }
      }
      // check children of node (s1, s2)
      if (s1 > 0) { // stack 1 mch fergha
         int l1 = 1<<t1;
         if (!s2 || t2 > t1) {
            if (d+1 < dist[s1^l1][s2|l1]) {
               dist[s1^l1][s2|l1] = d+1;
               q.push({dist[s1^l1][s2|l1], s1^l1, s2|l1});
            }
         }

         if (s3 == -1 || s3 > t1) {
            if (d+1 < dist[s1^l1][s2]) {
               dist[s1^l1][s2] = d+1;
               q.push({dist[s1^l1][s2], s1^l1, s2});
            }
         }
      }

      if (s2 > 0) { // stack 2 mch fergha
         int l1 = 1<<t2;
         if (!s1 || t1 > t2) {
            if (d+1 < dist[s1|l1][s2^l1]) {
               dist[s1|l1][s2^l1] = d+1;
               q.push({dist[s1|l1][s2^l1], s1|l1, s2^l1});
            }
         }

         if (s3 == -1 || s3 > t2) {
            if (d+1 < dist[s1][s2^l1]) {
               dist[s1][s2^l1] = d+1;
               q.push({dist[s1][s2^l1], s1, s2^l1});
            }
         }
      }

      if (s3 != -1) { // stack 3 mch fergha
         int l1 = 1<<s3;
         if (!s2 || t2 > s3) {
            if (d+1 < dist[s1][s2|l1]) {
               dist[s1][s2|l1] = d+1;
               q.push({dist[s1][s2|l1], s1, s2|l1});
            }
         }

         if (!s1 || t1 > s3) {
            if (d+1 < dist[s1|l1][s2]) {
               dist[s1|l1][s2] = d+1;
               q.push({dist[s1|l1][s2], s1|l1, s2});
            }
         }
      }
   }
   
   return dist[0][0];
}

int main() {
   int n = 4;
   //cin>>n;

   for (int i=3 ; i<13 ; i++) {
      cout<<bfs((1<<i)-1, 0, i)<<endl;
   }

   return 0;
}