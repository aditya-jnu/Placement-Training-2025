class MyStack {
public:
queue<int>  q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i=1;i<n;i++){
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */