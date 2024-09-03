class Solution {
public:
    int getLucky(string s, int k) 
    {
        string num = "" ;
        int sum=0;
        int n =0;
        for(int i=0;i<s.length();i++)
        {
            num+= to_string(s[i]-'a'+1);
        } 
        //cout<<num<<" ";   
        for(auto i : num)
        {
            n += i - '0';
        }
        k--;  // ( as one time sum of digits already done above)
        //cout<<n;
        int rem =0;
        while(k>0)
        {
            int sum = 0;
            while(n>0)
            {
                sum += n % 10;
                n /= 10;
            }
            n = sum;
            k--;
        }
        return n;
    }
};

