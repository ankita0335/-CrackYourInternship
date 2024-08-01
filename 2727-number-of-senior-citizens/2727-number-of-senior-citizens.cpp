class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c=0;
        int n = details.size();
        string res="";
        for(int j = 0; j < n; j++)
        {
            res="";
            for(int i = 11 ; i < 13 ; i++)
            {
                res+=details[j][i];
            }
            cout<<res<<" ";
            if(stoi(res) > 60)
                c++;
        }
        return c;
    }
};