#include "../lttools.cpp"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	bool isEvenOddTree(TreeNode* root) {
		queue<TreeNode*> q;
		int h = 0;
		q.push(root);
		int c = 1;
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			int pre = t->val;
			for (;!q.empty() && c>0; --c) {
				TreeNode* t = q.front();
				q.pop();
				if (h % 2 == 0) {
					if (t->val < pre) {
						return false;
					} else {
						pre = t->val;
					}
				} else {
					if (t->val > pre) {
						return false;
					} else {
						pre = t->val;
					}
				}
				if (t->left != nullptr) {
					q.push(t->left);
					++c;
				}   
				if (t->right != nullptr) {
					q.push(t->right);
					++c;
				}
			}
			if (t->left != nullptr) {
				q.push(t->left);
				++c;
			}   
			if (t->right != nullptr) {
				q.push(t->right);
				++c;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::isEvenOddTree);
	t.test()
}