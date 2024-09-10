class Solution {
public:
    bool isThree(int n) 
    {
        int c=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                if( i * j == n)
                    c++;
            }
        }    
        return c==3 ? true :false;
    }
};