#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
        string last= "11:59";
        for(int i =3;i<5;i++){
            if(s[i]=='?'){
                 s[i]=last[i];
            }
        }
        if ( s[0] == '0' && s[1] == '?' ) s[1] = '9';
        else if ( s[0] != '0' && s[1] == '?' ) s[1] = '1';

        if ( s[0] == '?' && ( s[1] == '0' || s[1] == '1'  )) s[0] = '1';
        else if ( s[0] == '?' ) s[0] = '0';
        return s;
    }
};