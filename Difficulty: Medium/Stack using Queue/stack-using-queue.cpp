class myStack {
    queue<int> q;

  public:

    void push(int x) {
        
        q.push(x);
        int s =q.size();
        for(int i=0;i<s-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    void pop() {
        if (q.empty()) return ;
        q.pop();
    }
    
    int top() {
         if (q.empty()) return -1;
        return (q.front());
    }
    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
