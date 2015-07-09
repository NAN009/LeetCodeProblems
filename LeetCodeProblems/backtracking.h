#include <iostream>
#include <list>
#include <vector>
using namespace std;
//Permutation   dfs [1,2,3]
//思路：首先生成[2,3]的全排列[2,3]、[3,2]，然后再把1加上去生成【1，2，3】、【1，3，2】
void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &result)
{
	if (begin >= nums.size())
	{
		result.push_back(nums);
		return;
	}
	for (int i = begin; i < nums.size();++i)
	{
		swap(nums[begin], nums[i]); 
		permuteRecursive(nums, begin + 1, result);
		swap(nums[begin],nums[i]);
	}
}
vector<vector<int>> permute_leetcode1(vector<int>& nums) 
{
	vector<vector<int>> result;
	permuteRecursive(nums, 0, result);
	return result;
}
vector<vector<int>>permute_leetcode2(vector<int> &nums)
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	ans.push_back(nums);
	while (next_permutation(nums.begin(), nums.end()))
		ans.push_back(nums);
	return ans;
}

//Permutation Sequence 排列
string getPermutation_leetcode1(int n, int k) 
{
	int i, j, f = 1;
	//left part of s is partially formed permutation,right part is the leftover chars
	string s(n, '0');
	for (i = 1; i <= n; i++)
	{
		f *= i;
		s[i - 1]+=i;//make s become 1234...n
	}
	for (i = 0, k--; i < n;i++)
	{
		f /= n - i;
		j = i + k/f;		//calculate index of char to put at s[i]
		char c = s[j];
		for (; j>i; j--)
			s[j] = s[j - 1];
		k %= f;
		s[i] = c;
	}
	return s;
}
string getPermutation_leetcode2(int n, int k)
{
	list<int >num;
	for (int i = 1; i <= n; i++)
		num.push_back(i);
	
	int fact = 1;
	for (int i = 1; i < n; i++)
		fact *= i;
	string s;
	for (k--; n>0;n--)
	{
		fact /= n;
		//s.append(list.remove(k / fact));
		k %= fact;
	}
	return s;
}