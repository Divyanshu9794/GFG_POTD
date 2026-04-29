class myStack {
    int top =-1;
    int *st;
    int size;
  public:
    myStack(int n) {
        // Define Data Structures
        top =-1;
        st = new int[n];
        size =n;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==-1){
            return true;
        }
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top==size-1){
            return true;
        }
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()){
            top++;
            st[top]=x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(!isEmpty()){
            top--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(!isEmpty()){
            return st[top];
        }
        return -1;
    }
};