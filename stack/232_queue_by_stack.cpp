class Queue {
private:
    stack<int> s1;
    stack<int> s2;
    void moveFromS1ToS2() {
        if (s2.empty())
        {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        moveFromS1ToS2();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        moveFromS1ToS2();
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};

/**
note: when move all to s2 when s2 is empty, otherwise, it is wrong.
**/