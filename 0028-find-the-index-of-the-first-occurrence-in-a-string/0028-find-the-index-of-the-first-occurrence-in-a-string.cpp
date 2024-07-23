class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int ans,flag=0;
        int j;
        for(int i=0;i<n;i++)
        {
            for(j=0;j<needle.length();j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    break;
                }
                if(j==needle.size()-1)  
                    return i;
            }
        }
        return -1;
    }
};