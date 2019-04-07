class Solution {
	public:
		int findComplement(int num) {
			int n = 0;
			int num2 = num;
			while (num2 > 0) {
				num2 >>= 1;
				++n;
			}
			num <<= sizeof(int)*8-n;
			num = ~num;
			num >>= sizeof(int)*8-n;
			return num;
		}
	};
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	std::cin>>n;
	std::cout<< Solution().findComplement(n) <<std::endl;
}