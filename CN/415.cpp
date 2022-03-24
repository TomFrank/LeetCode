#include "../lttools.cpp"

class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.size() < num2.size())
			return addStrings(num2, num1);
		
		vector<int> v;
		transform(num1.rbegin(), num1.rend(), back_inserter(v), [](auto c){ return c - '0';});
		
		reverse(num2.begin(), num2.end());
		
		for (int i=0; i<num2.size(); ++i) {
			v[i] += num2[i] - '0';
		}
		
		v.push_back(0);
		for (int i=0; i<num1.size(); ++i) {
			if (v[i] > 9) {
				v[i] -= 10;
				++v[i+1];
			}
		}
		if (v.back() == 0)
			v.pop_back();
		
		string res;
		transform(v.rbegin(), v.rend(), back_inserter(res), [](auto d){
			return d + '0';
		});
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::addStrings);
	t.test("123","11").equals("134");
	t.test("0","0").equals("0");
	t.test("1","9").equals("10");
	t.test("9","99").equals("108");
	t.test("99","99").equals("198");
}