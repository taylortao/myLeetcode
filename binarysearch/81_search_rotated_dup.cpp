class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
		int s = 0, e = n - 1;
		while(s<e)
		{
			int mid = s + ((e-s)>>1);
			if (nums[mid] == nums[e])
			{
				if (nums[e-1] <= nums[e])
				{
					e --;
				}
				else
				{
					s = e;
				}
			}
			else if (nums[mid] >= nums[s] && nums[mid] > nums[e])
			{
				s = mid + 1;
			}
			else
			{
				e = mid;
			}
		}
		
		e = s + n - 1;
		while (s <= e)
		{
			int mid = s + ((e-s)>>1);
			int realIndex = mid % n;
			if (nums[realIndex] == target)
			{
				return true;
			}
			else if (nums[realIndex] < target)
			{
				s = mid + 1;
			}
			else 
			{
				e = mid - 1;
			}
		}
		
		return false;
    }
};

/*
[2,2,2,0,2,2]
0

[1,3,5]
5

[1,2,2,2,0,1,1]
0

[1,1,1,1,3]
3
*/


/** another **/
class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) { return false; }
        int s=0, e=A.size()-1;
        while (s+1<e) {
            int m = s + ((e-s)>>1);
            if (A[m]>A[s]){
                if (target >= A[s] && target <= A[m]) {
                    e = m;
                }
                else {
                    s = m;
                }
            }
            else if (A[m]<A[s]) {
                if (target >= A[m] && target <= A[e]) {
                    s = m;
                }
                else {
                    e = m;
                }
            }
            else {
                s ++;
            }
        }
        if (A[s] == target) {
            return true;
        }
        else if (A[e] == target) {
            return true;
        }
        return false;
    }
};