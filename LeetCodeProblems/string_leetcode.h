#include <iostream>
#include <vector>
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
		if (*str!='\0')
			num=


	}
	
}
