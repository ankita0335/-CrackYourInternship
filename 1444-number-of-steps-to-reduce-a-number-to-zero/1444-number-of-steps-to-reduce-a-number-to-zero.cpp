class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num>0)
        {
            if(num%2==0)
            {
                num/=2;
            }
            else
            {
                num-=1;
            }
            c++;
        }
        return c;
    }
};