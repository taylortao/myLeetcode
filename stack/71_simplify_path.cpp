class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
		if (path.length() == 0 || path[0] != '/')
		{
			return "";
		}
		
		int s = 1, ind = 1, len = path.length();
		while (s < len)
		{
			ind = path.find_first_of('/', s);
			if (ind == string::npos)
			{
				ind = len;
			}
			
			if (ind - s > 0)
			{
				string segment = path.substr(s, ind - s);
				if (segment == ".")
				{
				}
				else if (segment == "..")
				{
					if (!stack.empty())
					{
						stack.pop();
					}
				}
				else
				{
					stack.push(segment);
				}
			}
			
			s = ind + 1;			
		}
		
		if (stack.empty())
		{
			return "/";
		}
		
		string result = "";
		while (!stack.empty())
		{
			result = "/" + stack.top() + result;
			stack.pop();
		}
		
		return result;
    }
};

/**
test cases:
/
////
//a
/a/../../..
/../
/a/b/c/d/.././e/../..///

**/