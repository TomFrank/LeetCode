#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
	public:
		int minMoves(vector<int>& nums) {
//			int ret = 0;
//			make_heap(nums.begin(), nums.end());
//			while (adjacent_find(nums.begin(), nums.end(), [](int a, int b){return a!=b;}) != nums.end()) {
//				pop_heap(nums.begin(), nums.end());
//				int a = nums.back();
//				nums.pop_back();
//				for_each(nums.begin(), nums.end(), [](int& n){++n;});
//				nums.push_back(a);
//				push_heap(nums.begin(), nums.end());
//				++ret;
//			}
//			return ret;
			int mn = *min_element(nums.begin(), nums.end());
			return accumulate(nums.begin(), nums.end(), 0) - nums.size() * mn;
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
	cout << Solution().minMoves(nums);
}