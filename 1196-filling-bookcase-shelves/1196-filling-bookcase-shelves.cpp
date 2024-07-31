class Solution {
public:
    int helper(vector<vector<int>>& boxes, int shelf_width, int dp[][1001], int i, int width, int height)
    {
        if(width>shelf_width)
            return INT_MAX;
        if(i>=boxes.size())
            return height;
        if(dp[i][width]!=0)
            return dp[i][width];
        
        int a = height + helper(boxes, shelf_width, dp, i+1, boxes[i][0], boxes[i][1]);
        int b = helper(boxes, shelf_width,dp,  i+1, width+boxes[i][0], max(height,boxes[i][1]));
        dp[i][width] = min(a,b);
        return min(a,b);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
    {
        int m = books.size();
        int n = books[0].size();
        int dp[1001][1001] = {};
        
        return helper(books, shelf_width, dp, 0, 0, 0);
    }
};