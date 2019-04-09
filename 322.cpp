#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void bck(vector<int>& coins, int p, int amount, int n, int& ans) {
//		cout << n << " ";
		if(amount == 0) {
			ans = min(ans, n);
			return;
		}
		for(int i=p;i<coins.size();++i) {
			if(amount >= coins[i] && long(coins[i]) * (ans - n) >= amount)
				bck(coins, i, amount-coins[i], n+1, ans);
		}
	}
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end(), greater<int>());
		//copy(coins.begin(), coins.end(), ostream_iterator<int>(cout, " "));
		const int amax = INT_MAX;// == ? INT_MAX : amount / coins.back() + 1;
		int ans = amax;
		bck(coins, 0, amount, 0, ans);
		if(ans != amax)
		    return ans;
		else
			return -1;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> coins = stringToIntegerVector(line);
		getline(cin, line);
		int amount = stringToInteger(line);
		
		int ret = Solution().coinChange(coins, amount);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}