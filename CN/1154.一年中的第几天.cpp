#include "../lttools.cpp"

class Solution {
public:
	static constexpr int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dayOfYear(string date) {
		const int y = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
		const int m = (date[5]-'0')*10 + (date[6]-'0');
		const int d = (date[8]-'0')*10 + (date[9]-'0');
		const bool isLeepYear = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
		int res = d;
		res += (m > 2 && isLeepYear) ? 1 : 0;
		for (int mm=1; mm<m; ++mm) {
			res += days[mm-1];
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::dayOfYear);
	t.test("2019-01-09").equals(9);
	t.test("2019-02-10").equals(41);
	t.test("2003-03-01").equals(60);
	t.test("2004-03-01").equals(61);
	t.test("2016-02-09").equals(40);
}