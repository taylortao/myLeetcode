class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.size() == 0) {
            return -1;
        }
        
        int s = 0, e = array.size() - 1;
        while (s + 1 < e) {
            int mid = s + ((e - s) >> 1);
            if (array[mid] >= target) {
                e = mid;
            }
            else {
                s = mid;
            }
        }
        
        if (array[s] == target) {
            return s;
        }
        else if (array[e] == target) {
            return e;
        }
        
        return -1;
    }
};