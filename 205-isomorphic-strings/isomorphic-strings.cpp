class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        if( s.length() != t.length() ) return false;
        int shash[256]={0}, thash[256]={0};
        for(int i=0;i<s.length();i++)
        {
            if((shash[s[i]] != 0 || thash[t[i]] != 0) && (shash[s[i]] != t[i]+1 || thash[t[i]] != s[i]+1)) return false;
            shash[s[i]] = t[i]+1;
            thash[t[i]] = s[i]+1;
        }
        return true;
    }
};