class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        map<vector<int>, int>mp; // unordered map mai aese vector nhi bn pata hai and iski jo time complexity hogi ordered map ki to search for a row (vector) vo log(n) hogi jbki unordered_map mai find ki t.c. o(1) hoti hai okayy :)
        int n= grid.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            mp[grid[i]]++;
        }
        for(int j=0;j<n;j++)
        {
            vector<int>tmp;
            for(int i=0;i<n;i++)
                tmp.push_back(grid[i][j]);
            c += mp[tmp];
        }
        return c;
    }
};