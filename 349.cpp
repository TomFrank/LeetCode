#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		vector<int> ret;
//		set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(ret));
//		auto p = unique(ret.begin(), ret.end());
//		ret.erase(p, ret.end());
//		return ret;
		unordered_set<int> s(nums1.begin(), nums1.end());
		vector<int> ret;
		for (int n:nums2)
			if (s.count(n)) {
				ret.push_back(n);
				s.erase(n);
			}
		return ret;
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
	auto num1 = readList();
	auto num2 = readList();
	auto ans = Solution().intersection(num1, num2);
	writeList(ans);
}