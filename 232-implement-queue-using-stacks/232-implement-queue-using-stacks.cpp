class MyQueue {
public:
    stack<int> input, output;
    
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        input.push(x);
    }
    
    int pop() 
    {
        while(input.size()!= 1)
        {
            output.push(input.top());
            input.pop();
        }
        int ans= input.top();
        input.pop();
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return ans;
    }
    
    int peek() 
    {
        while(input.size()!= 1)
        {
            output.push(input.top());
            input.pop();
        }
        int ans= input.top();
        while(!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return ans;
    }
    
    bool empty() 
    {
        if(input.empty())
        {
            return true;
        }
        return false;
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