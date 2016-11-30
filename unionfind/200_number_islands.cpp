class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) { return 0; }
        int n = grid[0].size();
        if (n == 0) { return 0; }
        int mn = m * n;
        vector<int> rootSet(mn, -1);
        vector<int> rankSet(mn, 0);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '0') { continue; }
                int ind = i * n + j;
                rootSet[ind] = ind;
                if (ind >= n && rootSet[ind-n] >= 0) {
                    mergeSet(rootSet, rankSet, ind, ind-n);
                }
                if (ind%n > 0 && rootSet[ind-1] >= 0) {
                    mergeSet(rootSet, rankSet, ind, ind-1);
                }
            }
        }
        int count = 0;
        for (int i=0; i<mn; i++) {
            if (rootSet[i] == i) {
                count ++;
            }
        }
        return count;
    }
    
    void mergeSet(vector<int>& rootSet, vector<int>& rankSet, int d1, int d2) {
        int r1 = findRoot(rootSet, d1);
        int r2 = findRoot(rootSet, d2);
        if (r1 != r2) {
            if (rankSet[r1] == rankSet[r2]) {
                rootSet[r2] = r1;
                rankSet[r1] ++;
            }
            else if (rankSet[r1] > rankSet[r2]) {
                rootSet[r2] = r1;
            }
            else if (rankSet[r1] < rankSet[r2]) {
                rootSet[r1] = r2;
            }
        }
    }
    
    int findRoot(vector<int>& rootSet, int d) {
        if (d == rootSet[d]) { return d; }
        rootSet[d] = findRoot(rootSet, rootSet[d]);
        return rootSet[d];
    }
};