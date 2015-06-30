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