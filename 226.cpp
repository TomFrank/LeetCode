#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root==nullptr)return root;
		TreeNode* t = root->left;
		root->left = root->right;
		root->right = t;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};
void printTree(TreeNode* root) {
	if (root==nullptr)return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}
int main(int argc, char *argv[]) {
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
//	printTree(root);
	Solution().invertTree(root);
	printTree(root);
}