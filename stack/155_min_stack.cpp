class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        normalStack.push(x);
		if (minStack.empty()) {
			minStack.push(x);
		}
		else {
			int minValue = min(x, minStack.top());
			minStack.push(minValue);
		}
    }
    
    void pop() {
		if (normalStack.empty() || minStack.empty()) {
			return;
		}
		
        normalStack.pop();
		minStack.pop();
    }
    
    int top() {
        return normalStack.empty() ? -1 : normalStack.top();
    }
    
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }

private:
	stack<int> normalStack;
	stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 
/**
Input:
["MinStack","push","push","push","getMin","pop","getMin"]
[[],[0],[1],[0],[],[],[]]
Output:
["constructor","null","null","null","0","null","-1"]
Expected:
["constructor","null","null","null","0","null","0"]
**/