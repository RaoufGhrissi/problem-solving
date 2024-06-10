class Solution {
public:
    bool vow(char d)
    {
        if (!isalpha(d))
            return 0;
        
        char c = tolower(d);
        return c == 'a' || c == 'e' || c =='o' || c == 'u' || c == 'i';
    }
    
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(i<j && !vow(s[i]))
                i++;
            
            while(i<j && !vow(s[j]))
                j--;
            
            if (i>=j)
                break;
            
            swap(s[i], s[j]);
                
            i++;
            j--;
        }
        
        return s;
    }
};