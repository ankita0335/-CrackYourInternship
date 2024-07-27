class Solution {
public:
    int count(int num)
    {
        int re=0;
        int ans=0;
        while(num!=0)
        {
            ans+=num%2;
            num=num/2;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int c=count(i);
            v.push_back(c);
        }
        return v;
    }
};