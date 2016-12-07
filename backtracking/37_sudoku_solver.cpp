class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<bool> rowUsed(9, false);
    	vector<vector<bool>> used(27, rowUsed);
        for (int i=0; i<81; i++) {
    		int r = i/9, c = i%9;
    		char ch = board[r][c];
    		if (ch >= '1' && ch <= '9') {
    			used[r][ch-'1'] = true;
    			used[c+9][ch-'1'] = true;
    			used[c/3+(r/3)*3+18][ch-'1'] = true;
    		}
    	}
    	dfs(board, 0, used);
    }
    
    bool dfs(vector<vector<char>>& board, int ind, vector<vector<bool>>& used) {
    	if (ind == 81) {
    	    return true;
    	}
		for (int i=ind; i<81; i++) {
			int r = i/9, c = i%9;
			if (board[r][c] == '.') {
				for (int k=0; k<9; k++) {
				    int d1 = r;
				    int d2 = c+9;
					int d3 = c/3+(r/3)*3+18;
					if (!used[d1][k] && !used[d2][k] && !used[d3][k]) {
						used[d1][k] = true;
						used[d2][k] = true;
						used[d3][k] = true;
						board[r][c] = k + '1';
						if (dfs(board, i + 1, used)) {
						    return true;
						}
						board[r][c] = '.';
						used[d1][k] = false;
						used[d2][k] = false;
						used[d3][k] = false;
					}
				}
		        return false;
			}
		}
		return true;
    }
};