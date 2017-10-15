#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = count(nums.begin(), nums.end(), 0);
		copy_if(nums.begin(), nums.end(), nums.begin(), [](int n){return n!=0;});
		fill_n(nums.end() - n, n, 0);
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
int main() {
	auto nums = readList();
	Solution().moveZeroes(nums);
	writeList(nums);
}