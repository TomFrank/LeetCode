#include "../lttools.cpp"

class Solution {
public:
	
	static
	TreeNode* help(const vector<int>& preorder, int pl, int pr, const vector<int>& inorder, int il, int ir) {
		if(pl>pr || il>ir) return nullptr;
		
		int rootVal = preorder[pl];
		
		int i;
		for(i=il; i<=ir; ++i)
			if(inorder[i] == rootVal) break;
			
		auto l = help(preorder, pl+1, pl+i-il, inorder, il, i-1);
		auto r = help(preorder, pl+i-il+1, pr, inorder, i+1, ir);
		auto node = new TreeNode(rootVal, l, r);
		return node;
	}
	
	static
	TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return nullptr;
		return help(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::buildTree);
	auto r = t.test("[3,9,20,15,7]"_arr, "[3,9,20,15,7]"_arr).lastResult();
	LT::print_inorder(r);
}