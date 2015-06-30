#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//动态规划：递推的解决问题
//1、描述最优解的结果
//2、递归定义最优解的值
//3、按自底向上的方式计算最优解的值
//4、由计算出的结果构造一个最优解
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