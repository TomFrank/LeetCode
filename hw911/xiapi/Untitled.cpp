#include <iostream>
#include <map>

using namespace std;

struct TreeNode {	
	int val;	
	struct TreeNode *left;	
	struct TreeNode *right;	
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
	
public:
	/**
	* Note: 类名、方法名、参数名已经指定，请勿修改
	*
	* 
	* 给予二叉树的头结点，请返回小偷依据上述原则，能偷到的最多的钱为何？
	* @param node TreeNode类 头结点
	* @return int整型
	*/
	
	int getMaxMoney(TreeNode* node, bool selected = true) {
		if (node == nullptr) {
			return 0;
		}
		if (selected) {
			return max(node->val + getMaxMoney(node->left, false) + getMaxMoney(node->right, false),
				getMaxMoney(node->left, true) + getMaxMoney(node->right, true)
			);
		} else {
			return getMaxMoney(node->left, true) + getMaxMoney(node->right, true);
		}
	}
};


int main(int argc, char *argv[]) {
	
}