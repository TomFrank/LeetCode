#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> grayCode(const int n) {
	vector<int> res;
	
	for (int x=0; x<(1<<n); ++x) {
		res.push_back(x ^ (x >> 1));
	}
	
	return res;
}

int main(int argc, char *argv[]) {
	auto res = grayCode(4);
	copy(res.cbegin(), res.cend(), ostream_iterator<int>(cout, ","));
}