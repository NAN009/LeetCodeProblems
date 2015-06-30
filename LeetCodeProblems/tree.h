#include <iostream>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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