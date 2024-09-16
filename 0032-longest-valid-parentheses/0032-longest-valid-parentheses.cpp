class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n= s.length();
        stack<int>st;
        st.push(-1);
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxi= max(maxi, i-st.top());
                }
            }
        }
        return maxi;
    }
};