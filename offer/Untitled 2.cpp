#include "../lttools.cpp"

int findK(const vector<int>& nums) {
	int count = 0;
	int x;
	for(int i=0; i<nums.size(); ++i) {
		if (count == 0) {
			x = nums[i];
		}
		if (nums[i] == x) {
			count++;
		} else {
			count--;
		}
	}
	return x;
}

int main(int argc, char *argv[]) {
	cout<< findK({1,1,1,2,3}) << endl;
	cout<< findK({1,2,1,1,2}) << endl;
	cout<< findK({2,1,1,2,1}) << endl;
	cout<< findK({1,2,1,2,1}) << endl;
	cout<< findK({2,1,1,1,2}) << endl;
}