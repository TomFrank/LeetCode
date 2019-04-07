#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
using namespace std;
void writeList(const vector<int>& v);
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		srand(time(0));
		int n = nums.size();
		while (true) {
			int m = nums[rand() % n];
			if (count(nums.begin(), nums.end(), m) > n / 2)
				return m;
		}
//		unordered_map<int, int> m;
//		for (int n:nums)
//			if (m[n] >= nums.size()/2)return n;
//			else ++m[n];
//		return 0;
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
	auto nums = readList();
	cout << Solution().majorityElement(nums);
}