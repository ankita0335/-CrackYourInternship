class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        string s1;
        string s2;
        int c=0;
        while(start!= 0)
        {
            s1 += (start%2);
            start /= 2;
        }    
        while(goal!=0)
        {
            s2 += (goal% 2);
            goal /= 2;
        }
        while(s1.length()> s2.length())
            s2 += '0';
        while(s1.length()< s2.length())
        {
            s1 += '0';
        }
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!= s2[i])
                c++;
        }
        return c;
    }
};