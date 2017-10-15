#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			int ret = 0;
			for (auto& n:nums)
				ret ^= n;
			return ret;
		}
	};

int main(int argc, char *argv[]) {
	getchar();
	vector<int> nums;
	int num;
	while (scanf("%d,", &num)==1)
		nums.push_back(num);
	cout << Solution().singleNumber(nums) << endl;	
}