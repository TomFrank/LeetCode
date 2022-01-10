#include "../lttools.cpp"

class Solution {
public:
	static constexpr int m[] {31,28,31,30,31,30,31,31,30,31,30,31};
	static constexpr char const * s[] {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	bool isLeap(int year) {
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}
	
	string dayOfTheWeek(int day, int month, int year) {
		int c = 4;
		
		for (int i=1971; i<year; ++i)
			if (isLeap(i)) {
				c += 366;
			} else {
				c += 365;
			}
		
		if (isLeap(year) && month > 2)
			c += 1;
		
		for (int i=0; i<month-1; ++i)
			c += m[i];
		
		c += day;
		
		return s[c % 7];
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::dayOfTheWeek);
	t.test(31, 8, 2019).equals("Saturday");
	t.test(18, 7, 1999).equals("Sunday");
	t.test(15, 8, 1993).equals("Sunday");
	t.test(29, 2, 2016).equals("Monday");
}