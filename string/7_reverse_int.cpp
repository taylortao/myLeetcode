class Solution {
public:
    int reverse(int x) {
        int num = 0, sign = 1, maxdivide10 = INT_MAX / 10, tailNum = 7;
		if (x < 0)
		{
			sign = -1;
			tailNum = 8;
			x *= -1;
		}
		
		while (x > 0)
		{
			if ( num < maxdivide10 || (num == maxdivide10 && x % 10 <= tailNum))
			{
				num = num * 10 + x % 10;
				x = x / 10;
			}
			else
			{
				return 0;
			}
		}
		
		return num * sign;
    }
};

/*
test cases:
sign charactor: -3283
overflow: 1111111888, -1110222888  => 0
last digit is 0: 100000000000

corner cases:
2147483647, -2147483648
not invalid input: 7463847412, -8463847412, ignore...
*/