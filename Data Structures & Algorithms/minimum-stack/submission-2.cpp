class MinStack {
public:
    vector<int> my_stack;
    int min_el;
    int min_ind;

    MinStack() {
        min_el = INT_MAX;
        min_ind = -1;
    }
    
    void push(int val) {
        my_stack.push_back(val);
        
        if (val <= min_el) {
            min_el = val;
            min_ind = my_stack.size() - 1;
        }
    }
    
    void pop() {
        int val = my_stack[my_stack.size() - 1];
        my_stack.pop_back();
        if (min_el == val && min_ind == my_stack.size()) {
            min_el = INT_MAX;
            for (int i = 0; i < my_stack.size(); i++) {
                if (my_stack[i] <= min_el) {
                    min_el = my_stack[i];
                    min_ind = i;
                }
            }
        }
    }
    
    int top() {
        return my_stack[my_stack.size() - 1];
    }
    
    int getMin() {
        return min_el;
    }
};
