#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

int numSub(string s) {
	const int md = 1e9+7;
	int cnt=0;
	vector<int> cs;
	for (int i=0; i<s.size(); ++i)
		if (s[i]=='0') {
			if (cnt>0) {
				cs.push_back(cnt);
				cnt=0;
			}
		} else ++cnt;
	if (cnt>0) cs.push_back(cnt);
	return accumulate(cs.begin(), cs.end(), 0, [](int r, int c){
		return (r+c*(c+1)/2)%md;
	});
}

int main(int argc, char *argv[]) {
	cout << numSub("1111111111011010011") << endl;
	cout << numSub("1111111111011010011") << endl;
	cout << numSub("111111") << endl;
	cout << numSub("101") << endl;
	cout << numSub("000") << endl;
}