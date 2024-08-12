class KthLargest {
public:
    int a;
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums)
    {
        a = k;
        for (auto i:nums) 
        {
            pq.push(i);
            if (pq.size() > a) 
            {
                pq.pop();
            }
        }
    } 
    int add(int val) 
    {
        pq.push(val);
        if (pq.size() > a) 
        {
            pq.pop();
        }
        return pq.top();
    }
};
