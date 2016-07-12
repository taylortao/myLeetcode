class Solution {
public:
    int romanToInt(string s) {
        char characters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
		int values[] = {1, 5, 10, 50, 100, 500, 1000};
		char prevChracters[] = {' ', 'I', 'I', 'X', 'X', 'C', 'C'};
		int prevValues[] = {0, 1, 1, 10, 10, 100, 100};
		int sum = 0, index = 0;
		for (int i=s.length() - 1; i >= 0; )
		{
			if (s[i] == characters[index])
			{
				sum += values[index];
				i--;
			}
			else if (s[i] == prevChracters[index])
			{
				sum -= prevValues[index];
				i--;
			}
			else 
			{
				index ++;
			}
		}
		
		return sum;
	}
};

/*
Many invalid cases, we do need to consider.

if we need to check if a Roman string is valid, we may need state machine as a more direct way.
*/