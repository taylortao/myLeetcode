class MedianFinder {
private:
	priority_queue<int, vector<int>> left; 
	priority_queue<int, vector<int>, greater<int>> right;
	
public:

    // Adds a number into the data structure.
    void addNum(int num) {
		if (left.empty() || num <= left.top())
		{
			left.push(num);
		}
		else
		{
			right.push(num);
		}
		
        int lsize = left.size(), rsize = right.size();
		if (lsize - rsize >= 2)
		{
			right.push(left.top());
			left.pop();
		}
		else if (rsize - lsize >= 2)
		{
			left.push(right.top());
			right.pop();
		}
    }

    // Returns the median of current data stream
    double findMedian() {
        int lsize = left.size(), rsize = right.size();
		if (lsize > rsize)
		{
			return left.top();
		}
		else if (lsize == rsize)
		{
			return (left.top() + right.top()) / 2.0;
		}
		else
		{
			return right.top();
		}
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();