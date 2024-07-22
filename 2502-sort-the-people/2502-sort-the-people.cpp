class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>v;
        priority_queue<pair<int,string>>pq;
        for(int i=0;i<names.size();i++)
        {
            pq.push({heights[i],names[i]}); 
        } //Since the priority queue is a max-heap by default,
        //it will sort the elements based on height in descending order. 
        //agr name phle dalti to name k acc. sort ho jata
        while(pq.size())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};