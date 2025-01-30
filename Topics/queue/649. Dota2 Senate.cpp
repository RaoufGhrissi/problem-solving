#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string s) {
        int r = 0, d = 0, totR = 0, totD = 0;

        queue<char> q; // hedha queue mkhobi 
        for (char &c:s) {
            q.push(c);
            totR += c == 'R';
            totD += c == 'D';
        }

        while(totR && totD) { // mezel fama m naw3in zouz
            if (q.front() == 'D') { // idha ena D
                if (d) { // banewni 
                    q.pop(); // alaho akber
                    d--; // nratah shabi men ban
                    totD--; // n9osna wehed
                } else { // manich mbani
                    q.push(q.front()); // nokhrej m saf
                    q.pop();  // narja3 mel ekher
                    r++; // nbani ena 
                }
            } else {
                if (r) {
                    q.pop();
                    r--;
                    totR--;    
                } else {
                    q.push(q.front());
                    q.pop();
                    d++;
                }
            }
        }  

        return totR ? "Radiant" : "Dire";
    }
};