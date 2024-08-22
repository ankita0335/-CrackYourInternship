class Solution {
public:
    int findComplement(int n) {
        string s= "";
        while(n > 1)
        {
            s=to_string(n%2)+s;
            n=n/2;
        }
        if(n== 1 ) s=to_string(n)+s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                s[i]='1';
            }
            else
            {
                s[i]='0';
            }
        }
        cout<<s;
        int ans = 0;
        int a=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            ans += (s[i]-'0')*pow(2,a);
            a++;
        }
        return ans;
    }
};