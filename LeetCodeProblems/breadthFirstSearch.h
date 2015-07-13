#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//Binary Tree Level Order Traversal 
extern struct TreeNode; 
vector<vector<int>> vec;
void buildVector(TreeNode *root, int depth)
{
	if (root == NULL)
		return;
	if (vec.size() == depth)
		vec.push_back(vector<int>());
	vec[depth].push_back(root->val);
	buildVector(root->left, depth + 1);
	buildVector(root->right, depth + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) 
{
	buildVector(root, 0);
	return vec;
}