class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int cnt = candidates.size();
		vector<int> initSolution;
		Dfs(candidates, initSolution, cnt, target, 0);
		return solution;
    }

private:
	vector<vector<int>> solution;
	void Dfs(const vector<int>& candidates, vector<int>& crtSolution, int cnt, int target, int index) {
		if (index >= cnt) { return; }
		for (int i=target/candidates[index]; i>=0; i--) {
			int targetLeft = target - (candidates[index] * i);
			for (int j=0; j<i; j++) {
				crtSolution.push_back(candidates[index]);
			}			
			if (targetLeft > 0) {
				Dfs(candidates, crtSolution, cnt, targetLeft, index + 1);
			}
			else if (targetLeft == 0) {
				solution.push_back(crtSolution);
			}
			for (int j=0; j<i; j++) {
				crtSolution.pop_back();
			}
		}
	}
};

/***  another ***/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int cnt = candidates.size();
		vector<int> initSolution;
		Dfs(candidates, initSolution, cnt, target, 0);
		return solution;
    }

private:
	vector<vector<int>> solution;
	void Dfs(const vector<int>& candidates, vector<int>& crtSolution, int cnt, int target, int index) {
		if (index >= cnt) { return; }
		if (target == 0) {
			solution.push_back(crtSolution);
		}
		for (int i=index; i<cnt; i++) {			
			if (target >= candidates[i]) {
				crtSolution.push_back(candidates[i]);
				Dfs(candidates, crtSolution, cnt, target-candidates[i], i);
				crtSolution.pop_back();
			}
		}
	}
};


