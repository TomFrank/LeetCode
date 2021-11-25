#include "../lttools.cpp"

ListNode* reverseList(ListNode* head) {
	ListNode* i = nullptr;
	auto j = head;
	while (j != nullptr) {
		auto jn = j->next;
		j->next = i;
		i = j;
		j = jn;
	}
	return i;
}

int main(int argc, char *argv[]) {
	auto t = LT::Tester(reverseList);
	t.test("[1,2,3,4,5]"_list).equals("[5,4,3,2,1]"_list);
	t.test("[]"_list).equals("[]"_list);
	t.test("[1]"_list).equals("[1]"_list);
}