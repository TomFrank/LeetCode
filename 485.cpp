#include <vector>
using namespace std;
class Solution {
	public:
		int findMaxConsecutiveOnes(vector<int>& nums) {
			int l = nums.size();
			int n = 0, ret = 0;
			n = ret = nums[0];
			for (int i=1; i<l; ++i) {
				if (nums[i]==1&&nums[i-1]==1)++n;
				else if (nums[i]==0&&nums[i-1]==1)n=1;
				else if (nums[i]==1&&nums[i-1]==0)n=1;
				ret = max(ret, n);
			}
			return ret;
		}
	};
#include <iostream>
int main(int argc, char *argv[]) {
	vector<int> nums;
	int num;
	getchar();
	while (scanf("%d,", &num)==1)
		nums.push_back(num);
	cout << Solution().findMaxConsecutiveOnes(nums) << endl;
}