// Generic Solution that work for any size

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        if (n<3)
            return 0;
        
        int occ[26] = {0};
        int diff = 0;
        
        for (int i=0 ; i<3 ; i++)
        {
            occ[s[i]-'a']++;
            if (occ[s[i]-'a']==1)
                diff++;
        }   
        
        int ans = diff==3;
        
        int i=0;      
        while(i+3<n)
        {
            occ[s[i]-'a']--;
            if (!occ[s[i]-'a'])
                diff--;
            
            occ[s[i+3]-'a']++;
            if (occ[s[i+3]-'a']==1)
                diff++;
            
            ans += diff==3;
            i++;
        }
        
        return ans;
    }
};

// Easy solution but not generic (works only for size = 3)
class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length() < 3) return 0;
        int count = 0;
        for(int i = 0; i<s.length()-2; i++){
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i+2] != s[i]){
                count++;
            }
        }
        return count;
    }
};