#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> frequencySort(const vector<int>& nums) {
	auto ans = nums;
	int fre[201]{};
	for_each(nums.begin(), nums.end(), [&](int a){
		++fre[a+100];
	});
	sort(ans.begin(), ans.end(), [&](int a, int b){
		if (fre[a+100] < fre[b+100]) {
			return true;
		} else if (fre[a+100] == fre[b+100]) {
			return a>b;
		} else return false;
	});
	return ans;
}

int main(int argc, char *argv[]) {
	auto ans = frequencySort({-1,1,-6,4,5,-6,1,4,1});
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, ","));
}