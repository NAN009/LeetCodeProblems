#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//��̬�滮�����ƵĽ������
//1���������Ž�Ľ��
//2���ݹ鶨�����Ž��ֵ
//3�����Ե����ϵķ�ʽ�������Ž��ֵ
//4���ɼ�����Ľ������һ�����Ž�
//Minimum Path Sum
int minPathSum_leetcode(vector<vector<int>> &grid)
{
	if (!grid.size())
		return 0;
	const int rows = grid.size(), cols = grid[0].size();
	vector<int>r(cols, 0);
	int i, j;
	r[0] = grid[0][0];
	for (j = 1; j < cols; ++j)
		r[j] = grid[0][j] + r[j - 1];
	for (i = 1; i < rows;++i)
	{
		r[0] += grid[i][0];
		for (j = 1; j < cols; ++j)
			r[j] = min(r[j - 1], r[j]) + grid[i][j];
	}
	return r[cols - 1];
}
int minPathSum_leetcode2(vector<vector<int>> &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int m = grid.size(),n=grid[0].size();
	vector<int>dp(n + 1, INT_MAX);
	dp[1] = 0;
	for (int i = 0; i < m;++i)
		for (int j = 0; j < n; ++j)
			dp[j + i] = min(dp[j + 1], dp[j]) + grid[i][j];
	return dp.back();
}
//Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices) 
{
	if (prices.size() <= 1)
		return 0;
	int max=-1000, temp=0;
	for (int i = 1; i < prices.size(); ++i)
	{
		temp += prices[i] - prices[i - 1];
		if (temp>max)
		{
			max = temp;
		}
		if (temp < 0)
			temp = 0;
	}
	return max>0 ? max : 0;
}
int maxProfit_leetcode(vector<int> &prices)
{
	if (prices.size() <= 0)
		return 0;
	int max = 0, min = prices[0], profit = 0;
	for (int i = 1; i < prices.size();++i)
	{
		if (prices[i] < min)
			min = prices[i];
		else
		{
			if (prices[i] - min>profit)
				profit = prices[i] - min;
		}
	}
	return profit;
}
//Unique Paths 
int uniquePaths(int m, int n) 
{
	if (m == 1 || n == 1)
		return 1;
	return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}
int uniquePaths2(int m, int n)
{
	vector<vector<int>>path(m+1, vector<int>(n+1,0));
	for (int i = 0; i < m+1; i++)
		path[i][1] = 1;
	for (int i = 0; i < n+1; ++i)
		path[1][i] = 1;
	for (int i = 2; i < m+1; ++i)
	{
		for (int j = 2; j < n+1;++j)
		{
			path[i][j] = path[i - 1][j] + path[i][j - 1];
		}
	}
	return path[m][n];
}
int uniquePaths_leetcode(int m, int n)
{
	if (m <= 0 || n <= 0)
		return 0;
	long long res = 1;
	for (int i = n; i < m + n - 1; ++i)
		res = res*i / (i - n + 1);
	return (int)res;
}
//Unique Binary Search Trees
int numTrees(int n)
{
	vector<int> fn(n+1,0);
	fn[0] = 1, fn[1] = 1, fn[2] = 2;
	for (int j = 3; j <= n;++j)
	{
		int temp = 0;
		for (int i = 0; i < j; ++i)
		{
			temp+= fn[j-1-i] * fn[i];
		}
		fn[j] = temp;
	}
	return fn[n];
}