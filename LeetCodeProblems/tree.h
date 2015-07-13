#include <iostream>
#include <vector>
#include <stack>
#include "Stack1.h"
using namespace std;
extern struct TreeNode;

//Invert Binary Tree
TreeNode* invertTree(TreeNode* root)
{
	if (!root)
		return nullptr;
	TreeNode *temp;
	if (root->left&&root->right)
	{
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	if(root->left)
		invertTree(root->left);
	if(root->right)
		invertTree(root->right);

}
//preorder traversal
vector<int> preorderTraversal_leetcode(TreeNode* root) {
	if (nullptr == root)
		return vector<int>();
	vector<int >result;
	stack<TreeNode* > treeStack;
	treeStack.push(root);
	
	while (!treeStack.empty())
	{
		TreeNode *p = treeStack.top();
		result.push_back(p->val);
		treeStack.pop();
		if (p->right != nullptr)
			treeStack.push(p->right);
		if (p->left != nullptr)
			treeStack.push(p->left);
	}
	return result;
}
//postorder traversal
vector<int> postorderTraversal_leetcode(TreeNode *root)
{
	stack<TreeNode *> nodeStack;
	vector<int> result;
	if (nullptr == root)
		return result;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		TreeNode *node = nodeStack.top();
		result.push_back(node->val);
		nodeStack.pop();
		if (node->left)
			nodeStack.push(node->left);
		if (node->right)
			nodeStack.push(node->right);
	}
	reverse(result.begin(), result.end());
	return result;
}
vector<int> postorderTraversal_leetcode2(TreeNode *root)
{
	vector<int> v;
	if (nullptr == root)
		return v;
	stack<TreeNode*> s;
	s.push(root);
	TreeNode *p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		v.insert(v.begin(), p->val);
		if (p->left)
			s.push(p->left);
		if (p->right)
			s.push(p->right);

	}
	return v;
}
//Invert Binary Tree 
TreeNode* invertTree(TreeNode* root) 
{
	if (nullptr == root)
		return root;	
	if (root->left||root->right)
	{
		TreeNode *temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	invertTree(root->left);
	invertTree(root->right);
	return root;
}
TreeNode* invertTree_leetcode(TreeNode* root)
{
	stack<TreeNode*> stack;
	stack.push(root);
	while (!stack.empty())
	{
		TreeNode *p = stack.top();
		stack.pop;
		if (p)
		{
			stack.push(p->left);
			stack.push(p->right);
			swap(p->left, p->right);
		}
	}
	return root;
}
//Validate Binary Search Tree 
void inorder1(TreeNode *root, vector<int> &vect)
{
	if (nullptr == root)
		return ;
	inorder1(root->left,vect);
	vect.push_back(root->val);
	inorder1(root->right,vect);
}
bool isValidBST(TreeNode* root) 
{
	if (nullptr == root)
		return true;
	vector<int > vect;
	inorder1(root, vect);
	for (int i = 1; i < vect.size(); ++i)
	{
		if (vect[i - 1] >= vect[i])
			return false;
	}
	return true;
}