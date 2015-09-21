#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Restore IP Addresses
vector<string> restoreIpAddresses(string s) 
{
	vector<string> str;
	if (s.size()<3 || s.size()>12)
		return str;
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
	
}
//atoi
int atoi(string str)
{
	if (str.empty())
		return 0;
	if (str[0] == '\0')
		return 0;
	bool isPositive = true;
	int value=0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (i==0&&(str[i]=='+'||str[0]=='-'))
		{
			if (str[i] == '-')
				isPositive = false;
			continue;
		}
		if (str[i]<'0'||str[i]>'0')
			break;
		value = 10 * value + str[i] - '0';
	}
	value = isPositive == true ? value : value*(-1);
	if (value < INT_MIN)
		return INT_MIN;
	if (value>INT_MAX)
		return INT_MAX;
} 
enum status
{
	kValid=0,
	kInValid
};
int g_nStatus = kValid;
long long strToIntCore(const char *digit, bool minus)
{
	long long num = 0;
	while (*digit!='\0')
	{
		if (*digit >= '0'&&*digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*digit-'0');
			if ((!minus&&num > 0x7fffffff) || (minus&&num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
		g_nStatus = kValid;
	return num;
}
int atoi_Offer(const char* str)
{
	g_nStatus = kInValid;
	long long num = 0;
	if (str != nullptr&&*str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
			num = strToIntCore(str, minus);		
	}
	return (int)num;
}
int myAtoi(string str)
{	
	if (str.empty())
		return 0;
	if (str[0] == '\0')
		return 0;
	bool ispositive = true;
 	long long num = 0,i,begin=-1;
	for (i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			if (begin + 1 != i)
				break;
			begin = i;
			continue;
		}		
		if (i==begin+1&&(str[i] == '+' || str[i] == '-'))
		{
			if (str[i] == '-')
				ispositive = false;
			continue;
		}
		if (str[i] >= '0'&&str[i] <= '9')
		{
			int flag = ispositive ? 1 : -1;
			num = num * 10 + flag*(str[i] - '0');
			if (num > INT_MAX)
				return INT_MAX;
			if (num < INT_MIN)
				return INT_MIN;
		}	
		else
			break;
	}
	return (int)num;
}
//Distinct Subsequences 

//Valid Parentheses
bool isValid(string s) 
{
	stack<char> sta;
	if (s.empty())
		return true;
	for (int i = 0; i < s.size();++i)
	{
		if (s[i]=='('||s[i]=='['||s[i]=='{')
		{
			sta.push(s[i]);
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (i == 0)
				return false;
			char c = sta.top();
			if (s[i] == ')'&&c != '(')
				return false;
			if (s[i] == ']'&&c != '[')
				return false;
			if (s[i] == '}'&&c != '{')
				return false;
			sta.push(s[i]);
		}
		
	}
	return true;
}
//Valid Palindrome  时间复杂度O(n) 空间复杂度O(1)
bool isPalindrome(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	auto left = s.begin(), right = prev(s.end());
	while (left<right)
	{
		if (!::isalnum(*left))++left;
		else if (!::isalnum(*right))--right;
		else if (*left != *right)return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;
}
//Add binary
string addBinary(string a, string b)
{
	string result;
	const size_t n = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (size_t i = 0; i < n;++i)
	{
		const int ai = i < a.size() ? a[i] - '0' : 0;
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int val = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.insert(result.begin(), val + '0');
	}
	if (carry == 1)
		result.insert(result.begin(), '0');
	return result;
}
