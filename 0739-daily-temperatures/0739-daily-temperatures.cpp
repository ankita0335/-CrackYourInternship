class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n);
        stack<int> st; 
        for (int i=n-1;i>=0;--i) {
            // Pop elements from the stack if they are less than or equal to the current temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if(!st.empty()) 
            {
                answer[i]=st.top()-i;
            }
            else
                answer[i]=0;
            // Push the current index onto the stack
            st.push(i);
        }
        return answer;
    }
};
