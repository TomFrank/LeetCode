#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

class Solution0 {
public:
	
	map<vector<int>, bool> mem;
	vector<int> a;
	int n,k,avg;
	
	bool dfs(vector<int>& st, int i) {
		if (i >= n)
			return all_of(st.cbegin(), st.cend(), [&](int s){
				return  s == avg;
			});
		
		if (mem.count(st) > 0)
			return mem[st];
		
		for (int j=0; j<k; ++j) {
			if (st[j] + a[i] <= avg) {
				st[j] += a[i];
				bool res = dfs(st, i+1);
				st[j] -= a[i];
				if (res) {
					mem[st] = true;
					return true;
				}
			} else continue;
		}
		
		mem[st] = false;
		return false;
	}
	
	bool canPartitionKSubsets(const vector<int>& nums, int k) {
		this->a = nums;
		this->k = k;
		this->n = nums.size();
		int sm = accumulate(a.cbegin(), a.cend(), 0);
		if (sm % k != 0) return false;
		this->avg = sm / k;
		sort(a.begin(), a.end(), greater<>());
		//for (int x:a)cout<<x<<", ";cout<<endl;
		vector<int> s(a.begin(), a.begin()+k-1);
		s.push_back(0);
		return dfs(s, k-1);
	}
};

class Solution {
public:
	vector<int> a;
	int n,k,avg;
	vector<bool> used;
	
	bool dfs(int c, int sum, int g) {
		if (g == k) return true;
		
		if (sum == avg)
			return dfs(0, 0, g+1);
		
		for (int i=c; i<n; ++i) {
			if (!used[i] && sum + a[i] <= avg) {
				used[i] = true;
				bool res = dfs(i+1, sum + a[i], g);
				used[i] = false;
				if (res) return true;
			}
		}
		
		return false;
	}
	
	bool canPartitionKSubsets(const vector<int>& nums, const int k) {
		this->a = nums;
		this->k = k;
		this->n = nums.size();
		int sm = accumulate(a.cbegin(), a.cend(), 0);
		if (sm % k != 0) return false;
		this->avg = sm / k;
		sort(a.begin(), a.end(), greater<>());
		used = vector<bool>(n, false);
		return dfs(0, 0, 0);
	}
};


int main(int argc, char *argv[]) {
	cout << Solution().canPartitionKSubsets({4, 3, 2, 3, 5, 2, 1}, 4) << endl;
	cout << Solution().canPartitionKSubsets({1,3,7,4,1,7,1,5,2,7,2,7,1,7,7,5}, 4) << endl;
	cout << Solution().canPartitionKSubsets({730,580,401,659,5524,405,1601,3,383,4391,4485,1024,1175,1100,2299,3908}, 4) << endl;
	cout << Solution().canPartitionKSubsets({85,35,40,64,86,45,63,16,5364,110,5653,97,95}, 7) << endl;
}