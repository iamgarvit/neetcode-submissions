class MinStack {
public:
    stack<int> minStack;
    stack<int> minE;

    MinStack() { 

    }
    
    void push(int val) {
        minStack.push(val);
        if (minE.empty()) {
            minE.push(val);
        }
        else {
            if (val <= minE.top()) {
                minE.push(val);
            }
        }
    }
    
    void pop() {
        int temp = minStack.top();
        minStack.pop();
        if (temp == minE.top()) {
            minE.pop();
        }
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return minE.top();
    }
};
