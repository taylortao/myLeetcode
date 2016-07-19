class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
		stack<char> stack;
		for (int i=0; i<len; i++)
		{
			char c = s[i];
			if (c == '(' || c == '[' || c == '{')
			{
				stack.push(c);
			}
			else
			{
				if (stack.empty())
				{
					return false;
				}
				
				char t = stack.top();
				if (c == ')' && t == '(')
				{
					stack.pop();
				}
				else if (c == ']' && t == '[')
				{
					stack.pop();
				}
				else if (c == '}' && t == '{')
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
		}
		
		return stack.empty();
    }
};

/**
test cases:
[[[[
[][][]
[[()(){[[]]}]]
[[]]]]
**/