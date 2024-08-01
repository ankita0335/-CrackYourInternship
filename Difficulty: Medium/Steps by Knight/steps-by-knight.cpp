//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int i, int j, int n, vector<vector<bool>>&vis)
    {
        if(i < 0 || j >= n || j < 0 || i >= n || vis[i][j] == true)
            return false;
        return true;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int kx = KnightPos[0]-1 , ky = KnightPos[1]-1;
	    if(kx==tx && ky == ty)
            return 0;
        vector<vector<bool>>vis(N, vector<bool>(N,false));
        queue<pair<int,int>>q;
        int ans=0;
        q.push({kx,ky});
        vis[kx][ky]=true;
        while(!q.empty())
        {
            int size= q.size();
            ans++;
            while(size!=0)
            {
                pair<int,int>p= q.front();
                q.pop();
                int x1= p.first;
                int y1 = p.second;
                int ax[8] = {1, 1, -1, -1, 2 , -2 , 2, -2};
                int ay[8] = {2, -2, 2, -2, 1, 1 , -1, -1};
                for(int i = 0; i < 8 ; i++)
                {
                    int nx = x1 + ax[i];
                    int ny = y1 + ay[i];
                    if(nx == tx && ny == ty)
                        return ans;
                    if(isValid(nx,ny,N,vis))
                    {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            size--;
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends