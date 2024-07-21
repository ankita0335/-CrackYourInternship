class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1);
        vector<int> order;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> que;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        while(!que.empty()) {
	        int u = que.front();
	        order.push_back(u);
	        que.pop();
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            if(indegree[v] == 0) {
	                que.push(v);
                    count++;
	            }       
	        }
	    }
        if (count != n) 
            return {}; 
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>orderRows=topoSort(rowConditions, k);
        vector<int>orderColumns=topoSort(colConditions, k);
        if (orderRows.empty() || orderColumns.empty())
            return {};
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }
};
