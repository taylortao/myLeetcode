class Solution {
public:
    bool isValidSerialization(string preorder) {
		int len = preorder.length();
        if (len == 0 || preorder[len-1] != '#')
		{
			return false;
		}
		
		stack<char> stack;
		int s = 0, ind = preorder.find(",", s);
		while(ind != string::npos)
		{
			if (ind == s + 1 && preorder[s] == '#')
			{
				if (stack.empty())
				{
					return false;
				}
				else
				{
					stack.pop();
				}
			}
			else 
			{
				stack.push('a');
			}
			
			s = ind + 1;
			ind = preorder.find(',', s);
		}
		
		return stack.empty();
    }
};

/**
test cases:
#  true
1,#  false
1,#,#   true
1,1,#,#,#   true
1,2,4,#,#,#,3,#,5,#,#  true
1,2,4,#,#,#,3,#,#,#  false
**/