#include "./lttools.cpp"

class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> v(num1.size()+num2.size(), 0);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i=0; i<num1.size(); ++i) {
			for (int j=0; j<num2.size(); ++j) {
				v[i+j] += (num1[i]-'0')*(num2[j]-'0');
			}
		}
		for (int i=0; i<v.size()-1; ++i) {
			v[i+1] += v[i]/10;
			v[i] %= 10;
		}
		string res;
		int i=v.size()-1;
		while (i > 0 && v[i] == 0) --i;
		for (; i>=0; --i) {
			res.push_back(v[i]+'0');
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	cout << Solution().multiply("100", "1000") << endl;
	cout << Solution().multiply("0", "1000") << endl;
	cout << Solution().multiply("9999", "0") << endl;
}