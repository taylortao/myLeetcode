class Solution {
public:
    int mySqrt(int x) {
		if (x < 0)
		{
			return INT_MIN;
		}
		
        if (x <= 1)
		{
			return x;
		}
		
		long x1 = x, cnt = 0;
		while(x1 > 0)
		{
			x1 = x1 >> 1;
			cnt ++;
		}
		
		// narrow down the range
		long cnt1 = (cnt - 1) >> 1, s = 1, e = 2;
		while (cnt1 --)
		{
			s <<= 1;
			e <<= 1;
		}
		
		long xl = x;
		while (s <= e)
		{
			long esqr = e*e;
			if (esqr <= xl)
			{
				return e;
			}
			
			long mid = s + ((e-s-1) >> 1) + 1;
			long midVal = mid * mid;
			if (midVal > xl)
			{
				e = mid - 1;
			}
			else if (midVal == xl)
			{
				return mid;
			}
			else
			{
				s = mid;
			}
		}
		
		return -1;
    }
};

/*
test cases:
-10
0
1
19
2147395599 (must consider int overflow problem)
*/