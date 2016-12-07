class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> solution;
		Dfs(solution, num, 9, 0, 0);
		return solution;
    }
	
private:
	void Dfs(vector<string>& solution, int numLeft, int nextDigit, int hour, int minute) {
		if (numLeft == 0) {
			if (hour < 12 && minute < 60) {
				solution.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
			}
		}
		if(numLeft > 0 && nextDigit >= 0) {
			int deltaHour = 0, deltaMinute = 0;
			if (nextDigit >= 6) {
				deltaHour = 1 << (nextDigit - 6);
			}
			else {
				deltaMinute = 1 << nextDigit;
			}
			
			Dfs(solution, numLeft - 1, nextDigit - 1, hour + deltaHour, minute + deltaMinute);
			Dfs(solution, numLeft, nextDigit - 1, hour, minute);
		}		
	}
};

/*
test cases:
0
1
9
10

notice the valid range of hours and minutes
*/