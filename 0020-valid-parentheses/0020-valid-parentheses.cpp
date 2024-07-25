class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char a=s[i];
            if(a=='(' || a=='{' || a=='[')
            {
                st.push(a);
            }
            else if(!st.empty())
            {
                if((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') ||(st.top()=='[' && s[i]==']'))
                {
                    st.pop();
                }
                else
                    return false;
            }
            else
                return false;
        }
        return (!st.empty()) ? false : true;
    }
};