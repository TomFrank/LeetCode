#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
	public:
		int missingNumber(vector<int>& nums) {
			return nums.size() * (nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
		}
	};
vector<int> readList() {
	vector<int> ret;
	getchar();
	int t;
	char c;
	while (cin >> t >> c) {
		ret.push_back(t);
		if (c == ']')break;
	}
	getchar();
	return ret;
}
void writeList(const vector<int>& v) {
	cout << "[";
	for (int i=0; i<v.size(); ++i) {
		cout << v[i];
		if (i!=v.size()-1)cout << ",";
	}
	cout << "]";
}
int main(int argc, char *argv[]) {
	auto n = readList();
	cout << Solution().missingNumber(n);
}