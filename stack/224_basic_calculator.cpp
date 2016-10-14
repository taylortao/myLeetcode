class Solution {
public:
    int calculate(string s) {
        int len = s.length();
		stack<int> numbers;
		stack<char> operators;
		operators.push('#');
		int value = 0;
		bool hasValue = false;
		for (int i = 0; i <= len; i ++)
		{
			char crtChar = i == len ? '#' : s[i];
			if (crtChar == ' ') continue;
			if(crtChar >= '0' && crtChar <= '9')
			{
				value = value * 10 + crtChar - '0';
				hasValue = true;
			}
			else
			{
				if (hasValue)
				{
					numbers.push(value);
					value = 0;				
					hasValue = false;
				}
				
				while (true)
				{
					char topChar = operators.top();
					int priority = isPrevGreater(topChar, crtChar);
					if (priority == 1)
					{
						// calculate
						int num1 = numbers.top();
						numbers.pop();
						int num2 = numbers.top();
						numbers.pop();						
						char op = operators.top();
						operators.pop();
						if (op == '+') numbers.push(num1 + num2);
						else if (op == '-') numbers.push(num2 - num1);
					}
					else if (priority == 0)
					{
						operators.pop();
						break;
					}
					else
					{
						operators.push(crtChar);
						break;
					}
				}				
			}
		}
		
		if (operators.empty() && !numbers.empty())
		{
			return numbers.top();
		}
		
		// invalid expression
		return 0;
    }
	
private:
	char operatorValue[5] = {'#', ')', '+', '-', '('};
	int priorityValue[5][5] = {{0,-1,-1,-1,-1}, {-2,-2,-2,-2,-2}, {1,1,1,1,-1}, {1,1,1,1,-1}, {-2,0,-1,-1,-1}};
	int isPrevGreater(char prev, char next) {
		int prevIndex = -1, nextIndex = -1;
		for(int i = sizeof(operatorValue) - 1; i >= 0; i--)
		{
			if (prevIndex < 0 && prev == operatorValue[i])
			{
				prevIndex = i;
			}
			
			if (nextIndex < 0 && next == operatorValue[i])
			{
				nextIndex = i;
			}
		}
		
		if (nextIndex >=0 && prevIndex >= 0)
		{
			return priorityValue[prevIndex][nextIndex];
		}
		
		return -1;
	}
};

/**
test cases:
"13"
"(12)"
"0+1 2 +3 34"
"1+3"
"1+(2+3) + (8 +   7)"
"(((1+2)+23)+23)-23"

**/