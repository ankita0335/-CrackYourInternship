class Solution {
public:
    int calPoints(vector<string>& op) {
        int n=op.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(op[i]=="C")
            {
                st.pop();
            }
            else if(op[i]=="D")
            {
                int dd=2*st.top();
                st.push(dd);
            }
            else if(op[i]=="+")
            {
                int f=st.top();
                st.pop();
                int s=st.top();
                st.push(f);
                st.push(s+f);
            }
            else
                st.push(stoi(op[i]));
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
//["5","-2","4","C","D","9","+","+"]
//14 //27