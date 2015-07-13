#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;
//后缀表示（逆波兰式）：把运算符放在两个运算对象的后边
//Binary Tree Inorder Traversal
extern struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void inorder(TreeNode *root,vector<int>& tree)
{
	if (root == nullptr)
		return;
	inorder(root->left,tree);
	tree.push_back(root->val);
	inorder(root->right,tree);
}
vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> tree;
	inorder(root,tree);
	return tree;
}
vector<int> inorderTraversal_leetcode(TreeNode* root)
{
	vector<int> vector;
	if (!root)
		return vector;
	stack <TreeNode *>stack;
	stack.push(root);
	while (!stack.empty())
	{
		TreeNode *pNode = stack.top();
		if (pNode->left)
		{
			stack.push(pNode->left);
			pNode->left = nullptr;
		}
		else
		{
			vector.push_back(pNode->val);
			stack.pop();
			if (pNode->right)
				stack.push(pNode->right);
		}
	}
	return vector;
}
vector<int> inorderTraversal_leetcode1(TreeNode* root)
{
	vector<int> vector;
	stack<TreeNode *>stack;
	TreeNode *pCurrent = root;
	while (!stack.empty()||pCurrent)
	{
		if (pCurrent)
		{
			stack.push(pCurrent);
			pCurrent = pCurrent->left;
		}
		else
		{
			TreeNode *pNode = stack.top();
			vector.push_back(pNode->val);
			stack.pop();
			pCurrent = pNode->right;
		}
	}
	return vector;
}
vector<int> inorderTraversal_leetcode2(TreeNode *root)
{
	vector<int> res;
	if (root == nullptr)
		return res;
	TreeNode *pre = nullptr;
	while (root!=nullptr)
	{
		if (root->left == nullptr)
		{
			res.push_back(root->val);
			root = root->right;
		}
		else
		{
			pre = root->left;
			while (pre->right != nullptr&&pre->right != root)
				pre = pre->left;
			if (pre->right == nullptr)
			{
				pre->right = root;
				root = root->left;
			}
			else
			{
				pre->right = nullptr;
				res.push_back(root->val);
				root = root->right;
			}
		}
	}
	return res;
}
