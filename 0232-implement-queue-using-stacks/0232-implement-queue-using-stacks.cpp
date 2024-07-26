class MyQueue {
public:
    stack<int>ip;
    stack<int>op;
    int peekk=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(ip.empty()) //phla element
            peekk=x;
        ip.push(x);
    }
    
    int pop() {
        if(op.empty())
        {
            //ip->op  O(n)
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
        }
        int val=op.top(); //O(1) Amortize 
        op.pop();
        return val;
    }
    
    int peek() {
        if(op.empty())
            return peekk;
        return op.top();
    }
    
    bool empty() {
        return (ip.empty() && op.empty())? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */