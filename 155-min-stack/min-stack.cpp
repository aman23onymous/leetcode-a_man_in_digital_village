class MinStack {
public:
    stack<int> s1,s2;

    MinStack() {
        
    }
    
    void push(int value) {
        s1.push(value);
        if(s2.size()) s2.push(min(s1.top(),s2.top()));
        else s2.push(value);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */