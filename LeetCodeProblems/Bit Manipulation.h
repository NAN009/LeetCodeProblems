#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//Missing Number 
int missingNumber(vector<int>& nums) 
{
	int data=0,max=INT_MIN;
	for (int i = 0; i < nums.size();++i)
	{
		data ^= nums[i];
		data ^= i;
		if (nums[i]>max)
			max = nums[i];
	}
	return (data^nums.size()) == 0 ? max : (data^nums.size());
}
int firstMissingPositive(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	vector<int>num;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] <= 1)
			num.push_back(nums[i]);
	}
	return missingNumber(num);
}