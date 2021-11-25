#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			vector<int> ret;
			for (int i=0; i<nums.size(); ++i) {
				if (nums[abs(nums[i])-1]>0)
				nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
			}
			for (int i=0; i<nums.size(); ++i) {
				if (nums[i]>0)ret.push_back(i+1);
			}
			return ret;
		}
	};
int main(int argc, char *argv[]) {
	getchar();
	vector<int> nums;
	int num;
	while (scanf("%d,", &num)==1) {
		nums.push_back(num);
	}
	for (auto& x:Solution().findDisappearedNumbers(nums))
	cout << x << ",";
}
//[4,3,2,7,8,2,3,1]
//4,3,2,-7,8,2,3,1
//4,3,-2,-7,8,2,3,1
//4,-3,-2,-7,8,2,3,1
//4,-3,-2,-7,8,2,-3,1
//4,-3,-2,-7,8,2,-3,-1
//4,-3,-2,-7,8,2,-3,-1
//4,-3,-2,-7,8,2,-3,-1
//-4,-3,-2,-7,8,2,-3,-1