#include <iostream>
#include <list>
#include <vector>
using namespace std;
//Permutation Sequence ееап
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
string getPermutation_leetcode1(int n, int k)
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