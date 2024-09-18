class Solution {
public:
    static bool comp(string a,string b)
    {
        return a+b >b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),comp);
        if(v[0]=="0")
            return "0";
        string ans="";
        for(string x: v)
        {
            ans+=x;
        }
        return ans;
    }
};