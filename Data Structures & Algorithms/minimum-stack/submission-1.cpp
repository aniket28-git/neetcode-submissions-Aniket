class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> min_stk;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        val = min(val, min_stk.empty() ? val : min_stk.top());
        min_stk.push(val);
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
