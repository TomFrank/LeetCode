#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, vector<string>> n2a {
	{'1', {}},
	{'2', {"a","b","c"}},
	{'3', {"d","e","f"}},
	{'4', {"g","h","i"}},
	{'5', {"j","k","l"}},
	{'6', {"m","n","o"}},
	{'7', {"p","q","r","s"}},
	{'8', {"t","u","v"}},
	{'9', {"w","x","y","z"}},
	{'0', {" "}}
};

vector<string> operator*(const vector<string>& a, const vector<string>& b) {
	vector<string> ret;
	for (const auto& x : a)
		for (const auto& y : b)
			ret.push_back(x + y);
	return ret;
}

ostream& operator<<(ostream& os, const vector<string>& v) {
	copy(v.begin(), v.end(), ostream_iterator<string>(os, " "));
	return os;
}

vector<string> letterCombinations(string digits) {
	vector<string> ret{""};
	for (auto c : digits)
		ret = ret * n2a[c];
	return ret;
}

int main(int argc, char *argv[]) {
	auto ans = letterCombinations("23");
	cout << ans;
}