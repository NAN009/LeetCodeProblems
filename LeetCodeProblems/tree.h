#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
//Balanced Binary Tree 
int treeDepth(TreeNode *root)
{
	if (nullptr == root)
		return 0;
	return max(treeDepth(root->left), treeDepth(root->right))+1;
}
bool isBalanced(TreeNode* root) 
{	
	if (nullptr == root)
		return true;
	int left = treeDepth(root->left), right = treeDepth(root->right);		
	return abs(left-right)<=1&&isBalanced(root->left) && isBalanced(root->right);
}
int dfsHeight(TreeNode *root)
{
	if (nullptr == root)
		return 0;
	int leftHeight = dfsHeight(root->left);
	if (-1 == leftHeight)
		return -1;
	int rightHeight = dfsHeight(root->right);
	if (-1 == rightHeight)
		return -1;
	if (abs(leftHeight - rightHeight) > 1)
		return -1;
	return max(leftHeight, rightHeight) + 1;
}
bool isBalanced_leetcode(TreeNode *root)
{
	return dfsHeight(root) != -1;
}
//Symmetric Tree
bool helper(TreeNode *p, TreeNode *q)
{
	if (!p&&!q)
		return true;
	else if (!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return helper(p->left, q->right) && helper(p->right, q->left);
}
bool isSymmetric(TreeNode* root)
{
	if (nullptr == root)
		return true;
	return helper(root->left, root->right);
}
//Convert Sorted Array to Binary Search Tree 
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	if (nums.size() == 0)
		return nullptr;

	TreeNode *root(nullptr);
	root->val = nums[nums.size() / 2];
	int n = nums.size()/2;
	while (n <nums.size())
	{
		root->right = new TreeNode(nums[nums.size() - n / 2]);
	}
}
//Path Sum 
bool hasPathSum(TreeNode* root, int sum) 
{
	if (root->left == nullptr&&nullptr == root->right&&sum - root->val == 0)
		return true;
	if (nullptr == root)
		return false;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
bool hasPathSumPostorder(TreeNode *root, int sum)
{
	stack<TreeNode *> s;
	TreeNode *pre = nullptr, *cur = root;
	int SUM = 0;
	while (cur||!s.empty())
	{
		while (cur)
		{
			s.push(cur);
			SUM+=cur->val;
			cur = cur->left;
		}
		cur = s.top();
		if (cur->left == nullptr&&cur->right == nullptr&&SUM == sum)
			return true;
		if (cur->right&&pre != cur->right)
			cur = cur->right;
		else
		{
			pre = cur;
			s.pop();
			SUM -= cur->val;
			cur = nullptr;
		}
	}
	return false;
}
//Minimum Depth of Binary Tree
int minDepth(TreeNode* root) 
{
	if (nullptr == root)
		return 0;
	if (root->left == nullptr&&root->right == nullptr)
		return 1;
	else
	{
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		int min = left > right ? right : left;
		return  min == 0 ? max(left, right) + 1 : min + 1;
	}
}