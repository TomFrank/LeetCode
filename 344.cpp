#include <string>
#include <algorithm>
using namespace std;
class Solution {
	public:
		string reverseString(string s) {
			reverse(s.begin(), s.end());
			return s;
		}
	};
#include <iostream>
int main(int argc, char *argv[]) {
	string s;
	cin>>s;
	cout<<Solution().reverseString(s)<<endl;
}