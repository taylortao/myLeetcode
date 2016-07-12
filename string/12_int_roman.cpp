class Solution {
public:
    string intToRoman(int num) {
        string result = nTimesChar(num / 1000, "M");
		int hundred = (num / 100) % 10;
		if (hundred > 0)
		{
			result += getSingleBitRoman(hundred, "C", "D", "M");
		}
		
		int ten = (num / 10) % 10;
		if (ten > 0)
		{
			result += getSingleBitRoman(ten, "X", "L", "C");
		}
		
		int one = num % 10;
		if (one > 0)
		{
			result += getSingleBitRoman(one, "I", "V", "X");
		}
		
		return result;
    }

private:
	string getSingleBitRoman(int digit, string c1, string c5, string c10) {
		if (digit < 4 && digit > 0)
		{
			return nTimesChar(digit, c1);
		}
		else if (digit == 4)
		{
			return c1 + c5;
		}
		else if (digit >= 5 && digit < 9)
		{
			return c5 + nTimesChar(digit - 5, c1);
		}
		else if (digit == 9)
		{
			return c1 + c10;
		}
		
		return "";
	}
	
	string nTimesChar(int times, string c) {
		string result = "";
		while (times --)
		{
			result += c;
		}
		
		return result;
	}
};

/*
test case: range 1 - 3999
3999
3111
3911
// the Roman seven symbols:
// I(1), V(5), X(10), L(50), C(100), D(500), M(1000)

other better solution:
class Solution {
public:
    string intToRoman(int num) {
        vector<int> i = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> r = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans;
        for(int j = 0; j < i.size(); ++j){
            while(num >= i[j]){
                ans += r[j];
                num -= i[j];
            }
        }
        return ans;
    }
};


*/