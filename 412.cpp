#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> fizzBuzz(int n) {
//		vector<string> ret;
//		for (int i=1; i<=n; ++i)
//			ret.push_back(to_string(i));
//		for (int i=2; i<=n; i+=3)
//			ret[i]="Fizz";
//		for (int i=4; i<=n; i+=5)
//			ret[i]="Buzz";
//		for (int i=14; i<=n; i+=15)
//			ret[i]="FizzBuzz";
//		return ret;
vector<string> ret(n);
for (int i=1; i<=n; ++i) {
    if (i%3==0)ret[i-1]+="Fizz";
    if (i%5==0)ret[i-1]+="Buzz";
    if (ret[i-1].empty())ret[i-1]=to_string(i);
}
return ret;
	}
};
#include <iostream>
int main(int argc, char *argv[]) {
	int n;
	std::cin>>n;
	for (const auto& s:Solution().fizzBuzz(n))
		std::cout<<s<<"\n";
}