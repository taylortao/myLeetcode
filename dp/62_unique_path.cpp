class Solution {
public:
    int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0)
		{
			return 0;
		}
		
        int maxV = max(m-1,n-1);
		long crtVal = 1, numerator = 1;
		for (int i=m+n-2, j=1; i>maxV; i--, j++)
		{
			crtVal *= i;
			numerator *= j;
		}
		
		return crtVal / numerator;
    }
};

/*
test cases:
-1 -1
0 0
1 1
10 1
10 10

notice: boundary of int
must use long!!!
*/