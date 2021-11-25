#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//			unordered_map<int, int> m;
//			for (int n:nums1)++m[n];
//			vector<int> ret;
//			for (int n:nums2)
//				if (m[n] > 0) {
//					ret.push_back(n);
//					--m[n];
//				}
//			return ret;
			sort(nums1.begin(), nums1.end());
			sort(nums2.begin(), nums2.end());
			vector<int> ret;
			set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(ret));
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
	auto n1 = readList();
	auto n2 = readList();
	auto ans = Solution().intersect(n1, n2);
	writeList(ans);
}