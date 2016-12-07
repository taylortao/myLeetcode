class Solution {
public:
    int minDistance(string word1, string word2) {
        int cnt1 = word1.length(), cnt2 = word2.length();
		if (cnt1 == 0) { return cnt2; }
		if (cnt2 == 0) { return cnt1; }
		vector<int> v1(cnt2, INT_MAX);
		vector<vector<int>> dp(cnt1, v1);
		for (int i = 0; i < cnt1; i++) {
			for (int j = 0; j < cnt2; j++) {
				dp[i][j] = max(i, j) + 1;
				if (i > 0) {
					dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
				}
				if (j > 0) {
					dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
				}
				if (i > 0 && j > 0) {
					dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
				}
				if (word1[i] == word2[j]) {
					if (i > 0 && j > 0) {
						dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
					}
					else {
						dp[i][j] = min(dp[i][j], max(i, j));
					}
				}
			}
		}
		
		return dp[cnt1-1][cnt2-1];
    }
};

/**
test cases:
""
"ddd"
"ddd"
""
"aaaaa"
"aa"
"asdfg"
"as"
"asdf"
"hjkl"
**/