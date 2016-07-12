class Solution {
public:
    int integerBreak(int n) {
		vector<int> v;
		if (n == 2)
		{	
			return 1;
		}
		
		if (n == 3)
		{
			return 2;
		}
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		for (int i=3; i<n-1; i++)
		{
			int v2 = 2 * v[i-2], v3 = 3 * v[i-3];
			int vm = v2 < v3 ? v3 : v2;
			v.push_back(vm);
		}
		
		return v[n-2];
    }
};

/*
test cases:
2
3
4
27
*/
