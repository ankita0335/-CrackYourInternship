class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int start=0;
        int n=height.size();
        int end=n-1;
        int area=0;
        while(start<end)
        {
            area=min(height[start],height[end])*(end-start);
            if(area>maxarea)
                maxarea=area;
            if(min(height[start],height[end])==height[start])
                start++;
            else    end--;
        }
        return maxarea;
    }
};
