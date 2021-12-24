#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int> nums;
	int total = 0;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 100);
	
	for (int i=1;i<100000;++i) {
		
		while (true) {
			int rand_n = distrib(gen);
			bool found = false;
			for (auto n: nums) {
				if (max(n, rand_n) % min(n, rand_n) == 0) {
					found = true;
					break;
				}
			}
			if (found) {
				total += nums.size();
				double avg = double(total) / i;
				cout << avg << "\n";
				nums.clear();
				break;
			} else {
				nums.push_back(rand_n);
			}
		}
		
	}
}