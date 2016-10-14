class Solution {
public:
	vector<string> addOperators(string num, int target) {
		exps.clear();
		long value = 0, len = num.length();
		for (int i = 0; i < len; i++)
		{
			value = value * 10 + num[i] - '0';
			recurseFind(num, i + 1, len, target, value, 0, to_string(value));
			if (i == 0 && value == 0) break; // 03 is not valid, only 0 is valid
		}
		
		return exps;
	}

private:
	vector<string> exps;
	void recurseFind(const string& num, int startIndex, int len, long target, long lastNumber, long crtSum, string prefix) {
		if (startIndex == len)
		{
			if (crtSum + lastNumber == target)
			{
				exps.push_back(prefix);
			}
			
			return;
		}
		
		long value = 0;
		for (int i = startIndex; i < len; i++)
		{
			value = value * 10 + num[i] - '0';
			recurseFind(num, i + 1, len, target, value, crtSum + lastNumber, prefix + "+" + to_string(value)); // +
			recurseFind(num, i + 1, len, target, -value, crtSum + lastNumber, prefix + "-" + to_string(value)); // -
			recurseFind(num, i + 1, len, target, lastNumber * value, crtSum, prefix + "*" + to_string(value)); // *
			if (i == startIndex && value == 0) return; // 03 is not valid, only 0 is valid
		}
	}
};

/** 
test cases:
""
0
"123"
123
"222" 
8
"3258" 
46
"123"
6
"232"
8
"105"
5
"00"
0
"3456237490"
9191

this one is important: since it is related with whether a number can start with 0
"105"
5
"0105"
5
"00000"
0
"0000001"
1
"2147483647"
-2147483647
"2147483648"
-2147483648
**/