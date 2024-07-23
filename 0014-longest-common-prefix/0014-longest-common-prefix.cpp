class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a=strs[0];
        int n=strs.size(); //vector does not have a length() method so used size()
        string c="";
        string b=strs[n-1];
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i])
            {
                c+=a[i];
            }
            else
                break;
        }
        return c;
    }
};