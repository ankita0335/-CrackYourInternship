class Solution {
public:
    vector<int>presml(vector<int>&heights)
    {
        int n=heights.size();
        stack<int>st;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            int e=(st.empty())? -1 : st.top();
            a.push_back(e);
            st.push(i);
        }
        return a;
    } 
    vector<int>nxtsml(vector<int>&heights)
    {
        int n=heights.size();
        stack<int>st;
        vector<int>b;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            int e=(st.empty())? n : st.top();
            b.push_back(e);
            st.push(i);
        }
        reverse(b.begin(),b.end());
        return b;
    } 
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>v1=presml(heights);
        vector<int>v2=nxtsml(heights);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int area=(v2[i]-v1[i]-1)*heights[i];
            ans=max(ans,area);
        }
        return ans;
    }
};