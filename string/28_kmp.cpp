class Solution {
private:
	void CalculateNextArray(string substr, vector<int> &next) {
		int len = substr.length();
		next.push_back(-1);
		for (int i = 1; i < len; i++) {
			int val = -1;
			int k = i - 1;
			while (k >= 0){
				if (substr[i] == substr[next[k] + 1]) {
					val = next[k] + 1;
					break;
				}
				
				k = next[k];
			}
			
			next.push_back(val);
		}
	}

public:
    int strStr(string haystack, string needle) {
        int len = haystack.length(), sublen = needle.length();
		if (sublen <= 0) {
			return 0;
		}
		
		vector<int> next;
		CalculateNextArray(needle, next);
		int i = 0, j = 0;
		while (i < len) {
			if (haystack[i] == needle[j]) {
				i ++;
				j ++;
				if (j == sublen) {
					break;
				}
			}
			else {
				if (j == 0)
				{
					i ++;
				}
				else
				{
					j = next[j - 1] + 1;
				}
			}			
		}
		
		if (j == sublen) {
			return i - sublen;
		}
		else {
			return -1;
		}
    }
};

/**
test cases:
""
""
"aaaaaaaaa"
"ab"
"aaaaaabbbadsafsaaa"
"abbb"
""
"a"
"a"
""
**/
