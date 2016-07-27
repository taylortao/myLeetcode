class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> uglys;
		uglys.push_back(1);
        int size = primes.size();
		vector<int> index(size, 0);
		for (int i=1; i<n; i++)
		{
			int minv = INT_MAX;
			for (int i=0; i<size; i++)
			{
				minv = min(minv, primes[i] * uglys[index[i]]);
			}
			
			for (int i=0; i<size; i++)
			{
				if(minv == primes[i] * uglys[index[i]])
				{
					index[i] ++;
				}
			}
			
			uglys.push_back(minv);
		}
		
		return uglys[n-1];
    }
};

/**
test cases:
[2,3,5] 7

**/