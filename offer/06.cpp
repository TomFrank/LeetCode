#include "../lttools.cpp"

class Solution {
public:
	static
	void help(ListNode* p, vector<int>& res) {
		if(p == nullptr) return;
		help(p->next, res);
		res.push_back(p->val);
	}
	
	static
	vector<int> reversePrint(ListNode* head) {
		vector<int> res;
		help(head, res);
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::reversePrint);;
	t.test("[1,3,2]"_list).equals("[2,3,1]"_arr);
	
}