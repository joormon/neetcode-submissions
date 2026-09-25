class MyStack {
    queue<int> q1, helper;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) return -1;
        while(q1.size()>1){
            helper.push(q1.front());
            q1.pop();
        }

        int pop_ele=q1.front();
        q1.pop();
        
        while(!helper.empty()){
            q1.push(helper.front());
            helper.pop();
        }
        return pop_ele;
        
    }
    
    int top() {
        if(q1.empty()) return -1;
        return  q1.back();
    }
    
    bool empty() {
        return q1.empty();
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