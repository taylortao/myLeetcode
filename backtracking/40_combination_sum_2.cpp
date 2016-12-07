class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int cnt = candidates.size();
		sort(candidates.begin(), candidates.end());
		vector<int> initSolution;
		Dfs(candidates, initSolution, cnt, target, 0);
		return solution;
    }

private:
	vector<vector<int>> solution;
	void Dfs(const vector<int>& candidates, vector<int>& crtSolution, int cnt, int target, int index) {
		if (index >= cnt) { return; }
		int maxIndexCnt = 1;
		while (index + maxIndexCnt < cnt && candidates[index + maxIndexCnt] == candidates[index]) {
			maxIndexCnt ++;
		}
		for (int i=0; i<=maxIndexCnt; i++) {
			int targetLeft = target - (candidates[index] * i);
			for (int j=0; j<i; j++) {
				crtSolution.push_back(candidates[index]);
			}
			if (targetLeft == 0) {
				solution.push_back(crtSolution);
			}
			else if (targetLeft > 0) {
				Dfs(candidates, crtSolution, cnt, targetLeft, index + maxIndexCnt);
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int cnt = candidates.size();
		sort(candidates.begin(), candidates.end());
		vector<int> initSolution;
		Dfs(candidates, initSolution, cnt, target, 0);
		return solution;
    }

private:
	vector<vector<int>> solution;
	void Dfs(const vector<int>& candidates, vector<int>& crtSolution, int cnt, int target, int index) {
		if (target == 0) {
			solution.push_back(crtSolution);
		}
		if (index >= cnt) { return; }
		for (int i=index; i<cnt; i++) {
			if (i > 0 && candidates[i] == candidates[i-1] && i > index) continue; // remove duplicate
			if (target >= candidates[i]) {
				crtSolution.push_back(candidates[i]);
				Dfs(candidates, crtSolution, cnt, target-candidates[i], i + 1);
				crtSolution.pop_back();
			}
		}
	}
};