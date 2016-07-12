class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits;
		bits.push_back(0);
		for (int i=1; i<=num; i++)
		{
			int lastbit = i & 1;
			bits.push_back(bits[i>>1] + lastbit);
		}
		
		return bits;
    }
};

/*
test cases:
0
5
483
*/