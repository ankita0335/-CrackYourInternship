class Solution {
public:
    bool isPal(string &s,int i,int j)
    {
        int n=s.length();
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxl=0,st=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPal(s,i,j))
                {
                    if((j-i+1)>maxl)
                    {
                        maxl=(j-i+1);
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxl);
    }
};