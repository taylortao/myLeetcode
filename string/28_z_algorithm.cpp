class Solution {
public:
    int strStr(string haystack, string needle) {
		if (haystack.length() < needle.length()) {
			return -1;
		}
		if (needle.length() == 0) {
			return 0;
		}	
        vector<int> z;
		z.push_back(0);
		string mix = needle + "$" + haystack;
		int left = 0, right = 0, j, mixLength = mix.length(), needleLength = needle.length();
		for (int i = 1; i < mixLength; i++) {
			if (right < i) {
				left = right = i;
				j = 0;
				while (right < mixLength && mix[right] == mix[j]) {
					right ++;
					j ++;
				}
				z.push_back(j);
				right --;
			}
			else {
				if (z[i-left] + i <= right) {
					z.push_back(z[i-left]);
				}
				else {
					right ++;
					j = right - i;
					while (right < mixLength && mix[right] == mix[j]) {
						right ++;
						j ++;
					}
					z.push_back(j);
					left = i;
					right--;
				}
			}			
			if (z[i] == needleLength) {
				return i - needleLength - 1;
			}
		}
			
		return -1;
    }
};

/*
""
""
"aaaaab"
"ab"
"aaacccc"
"d"
"a"
"a"
""
"a"
"a"
""
"mississippi"
"issip"
*/
