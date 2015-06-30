#include<iostream>
#include <vector>
using namespace std;
//Search a 2D Matrix
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.size()==0||target<matrix[0][0] || target>matrix[matrix.size() - 1][matrix[0].size() - 1])
		return false;
	if (matrix.size() == 1)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (target == matrix[0][j])
				return true;
		}
		return false;
	}

	int i;
	for (i = 0; i < matrix.size()-1; ++i)
	{
		if (target>=matrix[i][0]&&target<matrix[i+1][0])
			break;
	}
	for (int j = 0; j < matrix[i].size();++j)
	{
		if (target == matrix[i][j])
			return true;
		if (target<matrix[i][j])
			break;
	}
	return false;
}
//Search in Rotated Sorted Array
int search(vector<int>& nums, int target) 
{
	if(find(nums.begin(), nums.end(), target)!=nums.end())
		return find(nums.begin(), nums.end(), target) - nums.begin();
	else return -1;
}
//Spiral Matrix 
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
 	vector<int> num ;
	if (matrix.empty())
		return num;
	int start = 0, row = matrix.size(), col = matrix[0].size();
	while (2*start<row&&2*start<col)
	{
		for (int i = start; i < col-start; ++i)
		{
			num.push_back(matrix[start][i]);
		}
		if(start+1<row-start)
		for (int j = start+1; j < row-start; ++j)
		{
			num.push_back(matrix[j][col - 1-start]);
		}
		if (start + 1<row - start&&col - start - 2>=start)
		for (int i = col - start - 2; i >=start; i--)
		{
			num.push_back(matrix[row - 1-start][i]);
		}
		if (start + 1<row - start&&col - start - 2>=start&&row - 2 - start>start)
		for (int i = row - 2 - start; i>start; i--)
		{
			num.push_back(matrix[i][start]);
		}
		start++;
	}
	return num;
}
//Spiral Matrix II
vector<vector<int>> generateMatrix(int n) 
{
	vector<vector<int>>num(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0)
				num[0].push_back(j + 1);
			else
				num[i].push_back(1);
		}	
	}
	int start = 0; bool t = true;
	while (2*start<n)
	{
		if (start!=0)
		for (int i = start; i < n - start; ++i)
		{
			num[start][i] = num[start][i - 1] + 1;
			if (num[start][i] == n*n)
			{
				t = false;
				break;
			}
		}
		if (!t)
			break;
		for (int i = start + 1; i < n - start; ++i)
		{
			num[i][n - 1 - start] = num[i - 1][n - 1 - start] + 1;
			if (num[i][n - 1 - start] == n*n)
			{
				t = false;
				break;
			}
		}	
		if (!t)
			break;
		for (int i = n - 2-start; i >= start; i--)
		{
			num[n - 1 - start][i] = num[n - 1 - start][i + 1] + 1;
			if (num[n - 1 - start][i] == n*n)
			{
				t = false;
				break;
			}
		}
		if (!t)
			break;
		for (int i = n - start - 2; i>start; i--)
		{
			num[i][start] = num[i + 1][start] + 1;
			if (num[i][start] == n*n)
			{
				t = false;
				break;
			}
		}			
		if (!t)
			break;
		start++;
	}	
	return num;
}
vector<vector<int>> generateMatrix_leetcode(int n)
{
	vector<vector<int>> ret(n, vector<int>(n));
	int k = 1, i = 0;
	while (k <= n*n)
	{
		int j = i;
		while (j < n - i)
			ret[i][j++] = k++;
		j = i + 1;
		while (j < n - i)
			ret[j++][n - i - 1] = k++;
		j = n - 2 - i;
		while (j>i)
			ret[n - i - 1][j--] = k++;
		j = n - i - 1;
		while (j>i)
			ret[j--][i] = k++;
		i++;	
	}
	return ret;
}
//Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) 
{
	if (nums.empty())
		return 0;
	sort(nums.begin(), nums.end());
	int maxcount = 1, start = 0, i = 1;
	for (i = 1; i < nums.size();++i)
	{
		if (!(nums[i] - nums[i - 1] == 1 || nums[i] - nums[i - 1] == 0))
		{
			if (nums[i - 1] - nums[start]+1 > maxcount)
				maxcount = nums[i - 1] - nums[start]+1;									
			start = i;
		}
	}
	return maxcount>nums[i - 1] - nums[start]+1 ? maxcount : nums[i - 1] - nums[start]+1;
}
//Rectangle Area 
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{		
	if (abs(A - C)*abs(D - B) == 0)
		return abs(G - E)*abs(F - H);
	if (abs(G - E)*abs(F - H) == 0)
		return abs(A - C)*abs(D - B);
	if (C <= E||G<=A)
		return (C - A)*(D - B) + (G - E)*(H - F);
	if ((A <= E&&C >= E&&F >= B&&F <= D) || (A <= E&&C >= E&&H >= B&&H <= D)
		|| (A <= G&&C >= G&&F >= B&&F <= D)||(A <= G&&C >= G&&H >= B&&H <= D))
		return (C - A)*(D - B) + (G - E)*(H - F) - (min(C, G)-max(A, E))*(min(D, H) - max(B, F));
}
//Jump Game
bool canJump(vector<int>& nums) 
{
	if (nums.size() == 1)
		return true;
	if (nums[0] == 0)
		return false;
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (nums[i] == 0)
		{
			for (int k = i - 1; k >= 0; --k)
			{
				if (nums[k] - nums[i] <= i - k)
					return false;
			}
		}
	}
}