#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;
void writeList(const vector<int>& v);

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		unordered_map<int,int> mp;
		for (int i=0; i<nums.size(); ++i)
			mp[nums[i]]=i;
		vector<int> ret;	
		for (int n:findNums) {
			for (int i=mp[n]; i<nums.size(); ++i) {
				if (nums[i] > n) {
					ret.push_back(nums[i]);
					break;
				}
				if (i==nums.size()-1) {
					ret.push_back(-1);
				}
			}
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
	writeList(Solution().nextGreaterElement(num1, num2));
}