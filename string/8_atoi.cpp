class Solution {
public:
    int myAtoi(string str) {
		int sum = 0, len = str.length();
        if (len == 0)
		{
			return 0;
		}
		
		int si = str.find_first_not_of(' '), sign = 1, maxdivide10 = INT_MAX / 10;
		if (str[si] == '-')
		{
			si++;
			sign = -1;
		}
		else if (str[si] == '+')
		{
			si ++;
		}
		
		for (int i=si; i<len; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (sum < maxdivide10 || (sum == maxdivide10 && str[i] <= '7' ))
				{
					sum = sum * 10 + (str[i] - '0');
				}
				else
				{
					return sign > 0 ? INT_MAX : INT_MIN;
				}
			}
			else
			{
				break;
			}
		}
		
		return sum * sign;
    }
};


/*

test cases:

valid:
sign of number: -2, -19, +383
zero: 000000000
start with zero: 0000000000000982
overflow number: 999999999999999999, -22222222222222222222222222222222222   => INT_MAX, INT_MIN
with some leading space: space space space 0000283


invalid
with some other characters:  aaadd111abb
with space in the string: 9384 8383

edge case:
2147483647, -2147483648
2147483646,2147483648,-2147483647, -2147483649

note: "-2147483648" is processed as overflow, but they return the same value.
*/