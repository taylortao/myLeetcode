class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		// int is enough since it will less than 10^10
        vector<int> num;
		num.push_back(1);
		num.push_back(10);
		int cum = 9;
		for (int i = 2; i < 11; i ++)
		{
			cum = cum * (11 - i);
			num.push_back(num[i-1] + cum);
		}
		
		if (n > 10)
		{
			return num[10];
		}
		else
		{
			return num[n];
		}
    }
};

/*
test cases:
0
1-10
greater than 10

we could calculate it in advance and store them in an array.
*/