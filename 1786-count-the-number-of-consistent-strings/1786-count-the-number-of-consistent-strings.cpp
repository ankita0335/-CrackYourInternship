class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        unordered_set<char> st;   
        for(char c : allowed)
        {
            st.insert(c);
        }
        int c=words.size();
        for(string s: words)
        {
            int flag = true;
            for(char c : s)
            {
                if(st.find(c) == st.end())
                {
                    flag = false;
                }
            }
            if(!flag)
              c--;
        }
        return c;
    }
};