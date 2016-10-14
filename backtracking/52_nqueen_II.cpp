class Solution {
private:
	int num;
	vector<int> solutions;
	void findSolutions(int rowId, int n)
	{
		if (rowId == n)
		{
			num ++;
			return;
		}
		
		for (int i=0; i<n; i++)
		{
			int len = solutions.size();
			bool isValid = true;
			for (int j=0; j<len; j++)
			{
				int x = j, y = solutions[j];
				if (y == i || x + y == rowId + i || x - y == rowId - i)
				{
					isValid = false;
					break;
				}
			}
				
			if (isValid)
			{
				solutions.push_back(i);
				findSolutions(rowId + 1, n);
				solutions.pop_back(); 
			}
		}
	}
	
public:
    int totalNQueens(int n) {
        num = 0;
		solutions.clear();
		findSolutions(0, n);
		return num;
    }
};