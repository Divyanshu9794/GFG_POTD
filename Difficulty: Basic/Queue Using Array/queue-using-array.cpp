class myQueue {
    int start ;
    int end ;
    int *q;
    int size;
    int currsize;
  public:
    myQueue(int n) {
        // Define Data Structures
        start =-1;
        end =-1;
        q = new int[n];
        size =n;
        currsize=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(currsize==0){
            return true;
        }
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(currsize==size){
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(!isFull()){
            if(isEmpty()){
                start =0;
                end =0;
            }
            else{
                end = (end+1)%size;
            }
            q[end]=x;
            currsize++;
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(!isEmpty()){
            int el = q[start];
            if(currsize==1){
                start=end =-1;
            }
            else{
                start = (start+1)%size;
            }
            currsize--;
            
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(!isEmpty()){
            return q[start];
        }
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if(!isEmpty()){
            return q[end];
        }
        return -1;
    }
};