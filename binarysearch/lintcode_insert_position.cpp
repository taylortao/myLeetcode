class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) {
            return 0;
        }
        int s = 0, e = A.size() - 1;
        while (s + 1 < e) {
            int mid = s + ((e - s) >> 1);
            if (A[mid] <= target) {
                s = mid;
            }
            else {
                e = mid;
            }
        }
        
        if (A[s] >= target) {
            return s;
        }
        else if (A[e] >= target){
            return e;
        }
        return e + 1;
    }
};

/**
corner case
larger than the last one
larger than the first one

**/