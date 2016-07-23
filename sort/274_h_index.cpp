class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
		int len = citations.size(), maxv = 0;
		for (int i=len-1; i>=0; i--)
		{
			if (len - i <= citations[i])
			{
				if (i==0 || citations[i-1] <= len - i)
				{
					maxv = max(maxv, len - i);
				}
			}
		}
		
		return maxv;
    }
};

/*
test cases:
[]
[34]
[0,0,0]
[0,0,82]
[21,3,45,32,4,45,32,45,43,32,32,45,6,3,5,6,3,0]
*/
