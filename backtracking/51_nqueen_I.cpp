class Solution {
private:
	vector<vector<string>> results;
	vector<int> solutions;
	void findSolutions(int rowId, int n)
	{
		if (rowId == n)
		{
			vector<string> oneResult;
			for (int i=0; i<n; i++)
			{
				int col = solutions[i];
				string ret = "";
				for (int j=0; j<n; j++)
				{
					if (col == j)
					{
						ret = ret + "Q";
					}
					else
					{
						ret = ret + ".";
					}
				}
				
				oneResult.push_back(ret);
			}
			
			results.push_back(oneResult);
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
    vector<vector<string>> solveNQueens(int n) {
        results.clear();
		solutions.clear();
		findSolutions(0, n);
		return results;
    }
};