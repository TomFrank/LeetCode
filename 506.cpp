#include <iostream>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

class Solution {
	public:
		vector<string> findRelativeRanks(vector<int>& nums) {
			vector<string> ret(nums.size());
			vector<int> rank(nums.size());
			iota(rank.begin(), rank.end(), 0);
			sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});
			if (nums.size() > 0)ret[rank[0]]="Gold Medal";
			if (nums.size() > 1)ret[rank[1]]="Silver Medal";
			if (nums.size() > 2)ret[rank[2]]="Bronze Medal";
			for (int i=3; i<rank.size(); ++i)
				ret[rank[i]]=to_string(i+1);
//			vector<int> ored(nums);
//			map<int,int> mp;
//			sort(ored.rbegin(), ored.rend());
//			for (int i=0; i<ored.size(); ++i)
//				mp[ored[i]]=i+1;
//			for (int i=0; i<nums.size(); ++i)
//				if (mp[nums[i]]==1)ret.push_back("Gold Medal");
//				else if (mp[nums[i]]==2)ret.push_back("Silver Medal");
//				else if (mp[nums[i]]==3)ret.push_back("Bronze Medal");
//				else ret.push_back(to_string(mp[nums[i]]));
			return ret;
		}
	};
int main(int argc, char *argv[]) {
	vector<int> nums;
	int g;
	getchar();
	while (scanf("%d,", &g)==1)
		nums.push_back(g);
	auto ans = Solution().findRelativeRanks(nums);
	cout << "[";
	for (int i=0; i<ans.size(); ++i) {
		cout << "\"" << ans[i] << "\"";
		if (i!=ans.size()-1)cout<<",";
	}
	cout << "]";
}