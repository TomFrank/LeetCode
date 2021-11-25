#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			int i = 0;
			int j = numbers.size()-1;
			while (numbers[i] + numbers[j] != target) {
				if (numbers[i] + numbers[j] < target)++i;
				else --j;
			}
			return {i+1, j+1};
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
int readInt() {
	int n;
	cin >> n;
	return n;
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
	auto tar = readInt();
	writeList(Solution().twoSum(nums, tar));
}