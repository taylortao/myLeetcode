class Stack {
private:
    queue<int> q1;
    queue<int> q2;
    void moveQ1ElementToQ2Left1() {
        if (!q1.empty()) {
            int size = q1.size();
            size --;
            while (size --) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    void moveQ2ElementToQ1() {
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        moveQ1ElementToQ2Left1();
        q1.pop();
        moveQ2ElementToQ1();
    }

    // Get the top element.
    int top() {
        return q1.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};