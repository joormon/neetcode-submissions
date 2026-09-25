class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()) return -1;
        int count=0;//shifting count;
        while(count<(q.size()-1)){
            q.push(q.front());
            q.pop();
            count++;
        }

        //front is pointing at the pop element;
        int pop_ele=q.front();
        q.pop();
        return pop_ele;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.back();
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