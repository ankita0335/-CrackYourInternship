class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        priority_queue<pair<double, int>> pq;
        unordered_map<int, vector<pair<int, double>>> mp;
        for (int i = 0; i < edges.size(); i++) 
        {
            mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});    
        while (!pq.empty()) 
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();    
            if (node == end_node) return prob;
            for (auto& neighbor : mp[node]) 
            {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                if (maxProb[nextNode] < prob * edgeProb) 
                {
                    maxProb[nextNode] = prob * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }
        return 0.0;
    }
};
