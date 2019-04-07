#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool isValid(string s) {
#define PR(a, b) (a)+1==(b)||(a)+2==(b)	
	stack<char> st;
	for (auto c:s) {
		if (st.empty() || c == '(' || c == '[' || c == '{') {
			st.push(c);
		} else {
			if (PR(st.top(), c))
				st.pop();
			else return false;
		}
	}
	if (st.empty())
		return true;
	else return false;
}

int main(int argc, char *argv[]) {
	cout << boolalpha
		 << isValid("()[]{}") << "\n"
		 << isValid("([)]") << "\n"
		 << isValid("([{}])") << "\n";
}