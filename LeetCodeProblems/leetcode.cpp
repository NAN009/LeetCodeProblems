#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<time.h>
#include<stdlib.h>
#include <set>
using namespace std;
//顺时针旋转90度 Rotate Image
void retate(vector<vector<int> > &matrix)
{
	int len = matrix[0].size();
	vector<vector<int> > b(len);//二维vector 定义
	for (int i = 0; i<len; i++)// 二维vector初始化
	{
		for (int j = 0; j<len; j++)
		{
			b[i].push_back(matrix[i][j]);
		}
	}
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j<len; j++)
		{
			matrix[j][len-i-1] =b[i][j] ;
		}
	}
}
//Pascal's Triangle
vector<vector<int> >generate(int numRows)
{
	vector<vector<int > >matrix(numRows);
	if (numRows == 0)return matrix;
	matrix[0].push_back(1);
	if (numRows == 1)return matrix;
	matrix[1].push_back(1);
	matrix[1].push_back(1);
	if (numRows == 2)
		return matrix;
	else{
		for (int i = 2; i < numRows; i++)
		{
			matrix[i].push_back(1);
			for (int j = 1; j < i; j++)
			{
				matrix[i].push_back(matrix[i - 1][j] + matrix[i - 1][j - 1]);
			}
			matrix[i].push_back(1);
		}
		return matrix;
	}
}
//Pascal's Triangle II .
vector<int> getRow(int rowIndex)
{
	rowIndex += 1;
	vector<int> matrix; vector<int> matrix1;
	matrix.push_back(1); matrix1.push_back(1);
	if (rowIndex ==1)
		return matrix;
	matrix.push_back(1); matrix1.push_back(1);
	if (rowIndex ==2)
		return matrix;
	else
	{
		for (int i = 2; i < rowIndex; i++)
		{
			for (int j = 1; j < i; j++)
			{
				matrix[j] = matrix1[j - 1] + matrix1[j];
			}
			matrix.push_back(1); matrix1.push_back(1);
			for (int j = 0; j < matrix.size();j++)
				matrix1[j] = matrix[j];
		}
		return matrix;
	}
}
//Subsets
vector<vector<int> > subsets(vector<int> &S)
{
	int len;
	len = S.size();
	vector<vector<int> >set(len);
	//sort(S.begin(), S.end());
	for (int i = 0; ; i++)
	{
		set[i].push_back(S[i]);
	}
}
//Find Minimum in Rotated Sorted Array
int findMin(vector<int> &num)
{
	int t;
	sort(num.begin(), num.end());
	for (int i = 0; i<num.size()/2; i++)
	{
		t = num[i];
		num[i] = num[i + num.size() / 2];
		num[i + num.size() / 2] = t;
	}
	if (num.size() / 2 == 1)
	{
		num.insert(num.begin() + num.size() / 2, num[num.size() - 1]);
		num.pop_back();
	}
	return num[0];
}
//Remove Duplicates from Sorted List
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
ListNode *deleteDuplicates(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *l = head;
	while (l&&l->next)
	{
		ListNode *q;
		q = l->next;
		if (q == l)
		{
			l->next = l->next->next;
			free(q);
		}
		else
			l = l->next;
	}
	return head;
}
//Reverse Linked List II
ListNode *reverseBetween(ListNode *head, int m, int n)
{
	ListNode *q = head, *qm=q, *qn=q;
	int i = 1, data;
	while (q!=NULL)
	{
		if (i< m)
			qm = q;
		if (i < n)
		{
			qn = q;
		}
		q = q->next;
		i++;
	}
	data = qm->val;
	qm->val = qn->val;
	qn->val = data;
	return head;
}
//Remove Nth Node From End of List
ListNode *removeNthFromEnd(ListNode *head, int n)
{
	if (head->next == NULL&&n == 1)
		return NULL;
	ListNode *p = head, *q=head;
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	if (n == 1 && len == 2)
	{
		q = p->next;
		q->val = p->next->val;
		p->next = NULL;
		free(q);
		return head;
	}
	for (int i = 0; i<len; i++)
	{
		if (i == len - n - 1)
			break;
		p = p->next;
	}
	if (n == 1)
	{
		p->next = NULL;
	}
	else
		p->next = p->next->next;
	return head;
}
//Valid Number 
bool isNumber(const char *s)
{
	int len = strlen(s);
	
	for (int i = 1; i < len; i++)
	{
		if (!(isdigit(s[i])||s[i]=='e'||s[i]=='.'||s[i]=='E'))
				return false;
	}
	if (s[len - 1] == '.' || s[0] == '.')
		return false;
	for (int i = 1; i < len ; i++)
	{
		if (s[i] == 'e')
		if (len-i-1)
			return false;
	}
}
//Maximum Subarray 
int crossMaxSub(int A[], int low, int mid,int high)
{
	int clsum = -1000, crsum = -1000, sum = 0, i, j, clindex = 0,crindex=0;
	for (i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > clsum)
		{
			clsum = sum;
			clindex = i;
		}			
	}
	sum = 0;
	for (j = mid + 1; j < high; j++)
	{
		sum += A[i];
		if (sum>crsum)
		{
			crsum = sum;
			crindex = j;
		}		
	}
	return crsum + clsum;
}
int maxSub(int A[], int low, int high)
{
	if (low == high)return A[low];
	int mid = (low + high) / 2, lmax = 0,rmax=0,cmax=0,max=0;
	lmax=maxSub(A, low, mid);
	rmax=maxSub(A, mid + 1, high);
	cmax=crossMaxSub(A, low,mid, high);
	if (lmax > rmax&&lmax > cmax) max = lmax;
	else if (cmax > rmax&&cmax > lmax)max = cmax;
	else if (rmax > cmax&&rmax > lmax)max = rmax;
	return max;
}
int maxSubArray(int A[], int n)
{
	int max = 0;
	max=maxSub(A, 1, n);
	
	return max;
}
//Two Sum
vector<int> twoSum(vector<int> &numbers, int target)
{
	vector<int> two;
	sort(numbers.begin(),numbers.end());
	for (int i = 0; i<numbers.size(); i++)
	{
		for (int j = i + 1; j<numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == target)
			{
				two.push_back(i+1);
				two.push_back(j+1);
			}
		}
	}
	return two;
}
//Palindrome Number 
bool isPalindrome(int x)
{
	long long i, j, c=0;
	i = x;
	while (i!=0)
	{
		i = i / 10;
		c++;
	}
	int m = c;
	i = x / pow(10, m - 1);
	j = x % 10;
	for (int k = 0; k<c / 2; k++)
	{
		if (i != j)
			return false;

		x = x %(int) pow(10, m - 1);
		x = x / 10;
		m -= 2;
		i = x / pow(10, m - 1);
		j = x % 10;
	}
	return true;
}
//Add Binary 
string addBinary(string a, string b)
{
	int len_a = a.size(), len_b = b.size();
	if (len_a > len_b)
		a.swap(b);
	len_a = a.size();
	len_b = b.size();
	for (int i = len_a - 1, j = len_b - 1; j>=0; i--, j--)
	{
		if (i>=0)
			b[j] += a[i];
	}
	for (int i = b.size()-1;i>0; i--)
	{
		if (b[i] > '1')
		{
			b[i] = b[i] - '2';
			b[i - 1] += '1';
		}
	}
	if (b[0] > '1')
	{
		b[0] -= '2';
		b ="1"+b ;
	}
	return b;
}
//Length of Last Word 
int lengthOfLastWord(const char *s)
{

	int len = strlen(s), i;
	if (s[0] == ' '&&len == 1)
		return 0;
	for (i = len - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
			break;
	}
	if (i >= 0 && i<=len - 1)
		return len - i - 1;
	else return len;
}

//math
//Pow(x, n)
double pow1(double x, int n)
{
	long double p, m;
	if (n == 0)
		return 1;
	if (n<0)
		return 1 / pow1(x, -n);
	double half = pow1(x, n >> 1);
	if (n % 2 == 0)
		return half*half;
	else return half*half*x;
	
}
//Sqrt(x) 
int sqrt1(int x)
{
	int i;
	if (x == 0)
		return 0;
	if (x == 1 || x == 2 || x == 3)
		return 1;
	if (x <= 100000000)
	{
		for (i = 1; i <= 10000; i++)
		{
			if (i*i <= x && (i + 1)*(i + 1)>x)
				return i;
		}
	}
	if (x<1000000000)
	{
		for (i = 10000; i<31630; i++)
		if (i*i <= x && (i + 1)*(i + 1)>x)
			return i;
	}
	if (x<2147395600)
	{
		for (i = 31600; i<46340; i++)
		if (i*i <= x && (i + 1)*(i + 1)>x)
			return i;
	}
	else return 46340;
}
//Permutation Sequence 
int fun(int f)
{
	if (f == 0)
		return 1;
	else 
		return f*fun(f - 1);
}
string getPermutation(int n, int k)
{
	string s;
	for (int i = n,j=0; i >0 ;j++, i--)
	{
		if (k%2==0)
			s.push_back(k / fun(i- 1) -1+48);
		else 
			s.push_back(k / fun(i - 1)+1 + 48);
		k = k%fun(i - 1);
	}
	return s;
}
//Implement strStr() 
int strStr(char *haystack, char *needle)
{
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
	if (len2 == 0)return 0;
	if (len2 == 1 && haystack[0] == needle[0])
		return 0;
	
	for (int i = 0; i<len1; i++)
	{
		bool b = false;
		if (haystack[i] == needle[0])
		{
			if (len1 - i<len2)return -1;
			for (int j = 1; j<len2; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					b = true;
					break;
				}
				
			}
			if (!b)
				return i;
		}
	}
	return -1;
}
//Roman to Integer
int romanToInt(string s) 
{
	int sum=0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'I')
		{
			sum += 1;
		}
		if (s[i] == 'V')
		{
			sum += 5;
			if (i!=0 && s[i - 1] == 'I')
			{
				i--;
				sum -= 1;						
			}		
		}
		if (s[i] == 'X')
		{
			sum += 10;
			if (i != 0 && s[i - 1] == 'I')
			{
				i--;
				sum -= 1;
			}
		}
		if (s[i] == 'L')
		{
			sum += 50;
			if (i != 0 && s[i - 1] == 'X')
			{
				i--;
				sum -= 10;
			}
		}
		if (s[i] == 'C')
		{
			sum += 100;
			if (i != 0 && s[i - 1] == 'X')
			{
				i--;
				sum -= 10;
			}
		}
		if (s[i] == 'D')
		{
			sum += 500;
			if (i != 0 && s[i - 1] == 'C')
			{
				i--;
				sum -= 100;
			}
		}
		if (s[i] == 'M')
		{
			sum += 1000;
			if (i != 0 && s[i - 1] == 'C')
			{
				i--;
				sum -= 100;
			}
		}
	}
	return sum;

}
//Integer to Roman
string char1(int tmp,char c1, char c2, char c3)
{
	string s;
	if (tmp % 10 == 1)
		s.push_back(c1);
	else if (tmp % 10 == 2)
	{
		s.push_back(c1);
		s.push_back(c1);
	}
	else if (tmp % 10 == 3)
	{
		s.push_back(c1);
		s.push_back(c1);
		s.push_back(c1);
	}
	else if (tmp % 10 == 4)
	{
		s.push_back(c1);
		s.push_back(c2);	
	}
	else if (tmp % 10 == 5)
	{
		s.push_back(c2);
	}
	else if (tmp % 10 == 6)
	{
		s.push_back(c2);
		s.push_back(c1);	
	}
	else if (tmp % 10 == 7)
	{
		s.push_back(c2);
		s.push_back(c1);
		s.push_back(c1);	
	}
	else if (tmp % 10 == 8)
	{
		s.push_back(c2);
		s.push_back(c1);
		s.push_back(c1);
		s.push_back(c1);	
	}
	else if (tmp % 10 == 9)
	{
		s.push_back(c1);
		s.push_back(c3);
	}
	return s;
}
string one2nine(int tmp)
{
	string s;
	s=char1(tmp, 'I', 'V', 'X');
	return s;
}
string one2h(int tmp)
{
	string s;
	if (tmp % 10 != 0)
	{
		s += one2nine(tmp % 10);
	}
	tmp = tmp / 10;
	s+=char1(tmp, 'X', 'L', 'C');
	return s;
}
string one2t(int tmp)
{
	string s;
	if (tmp % 100 != 0)
	{
		s += one2h(tmp % 100);
	}
	tmp /= 100;
	s+=char1(tmp, 'C', 'D', 'M');
	return s;
}
string one23999(int tmp)
{
	string s;
	if (tmp % 1000 != 0)
	{
		s += one2t(tmp % 1000);
	}
	tmp /= 1000;
	if (tmp % 10 == 1)
		s.push_back('M');
	else if (tmp % 10 == 2)
	{
		s.push_back('M');
		s.push_back('M');
	}
	else if (tmp % 10 == 3)
	{
		s.push_back('M');
		s.push_back('M');
		s.push_back('M');
	}
	return s;
}
string intToRoman(int num)
{
	string s, s1;
	string c1 = "C", c2 = "M";
	int tmp = num;
	if (tmp == 100)
		return c1;;
	if (tmp == 1000)
		return c2;
	if (tmp > 1000&& tmp<4000)
	{
		int x = tmp / 1000;
		if (x == 1)
			s.push_back('M');
		else if (x == 2)
		{
			s.push_back('M');
			s.push_back('M');
		}
		else if (x == 3)
		{
			s.push_back('M');
			s.push_back('M');
			s.push_back('M');
		}
		tmp = tmp % 1000;
	}
	if (tmp > 100 && tmp < 1000)
	{
		s += char1(tmp/100, 'C', 'D', 'M');
		tmp = tmp % 100;
	}
	if (tmp < 100&&tmp>9)
	{	
		s += char1(tmp/10, 'X', 'L', 'C');
		tmp = tmp % 10;
	}
	if (tmp < 10)
	{
		s += char1(tmp, 'I', 'V', 'X');
	}
	return s;
}
//Longest Common Prefix
string longestCommonPrefix(vector<string> &strs)
{
	
	//if (strs.size()>0)
	if (strs.empty())
		return "";
		sort(strs.begin(), strs.end());
		if (strs.size() == 1)
			return strs[0];
		string s, s1;
		int j = 0,i, k = 0;
		while (j < strs[0].size())
		{
			s.push_back(strs[k][j]);
			s1.push_back(strs[k][j]);
			for (i = 0; i < strs.size(); i++)
			{
				if (s[j] != strs[i][j])
					break;
			}
			if (s[j] != strs[i][j])
			{
				if (k==0)return s;
				else
				{
					s.pop_back();
					return s;
				}
				
			}
			k++;
			j++;
		}
		return s;
	
}
char *strStr1(char *haystack, char *needle)
{
	int i, j;
	for (i = j = 0; haystack[i] && needle[j];)
	{
		if (haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return needle[j] ? 0 : (haystack + i - j);
}

void NativeMatching(char Target[], char *Pattern)
{
	int PatLen = strlen(Pattern);
	for (int i = 0; i < strlen(Target); ++i)
	{
		int TmpTarLen = i;
		for (int j = 0; j < PatLen; ++j)
		{
			if (Target[TmpTarLen++] != Pattern[j])
				break;
			if (j == PatLen - 1)
				cout << "匹配起始位置" << i << " ";
		}
	}

}
void reverseWords(string &s)
{
	string s1;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != ' ')
		{
			s1 += s[i];
		}
		else
		{
			if (i == 0)
				continue;
			else
			{
				if (s[i - 1] != ' ')
					s1 += ' ';
			}
		}
	}
	s.clear();
	int j = 0;
	string tmp;
	while (j < s1.size())
	{
		if (s1[j] != ' ')
			tmp += s1[j];
		else
		{
			s.insert(0, tmp + ' ');
			tmp.clear();
		}
		if (j == s1.size() - 1)
			s.insert(0, tmp + ' ');
		j++;
	}
	if (s[s.size() - 1] == ' ')
		s.pop_back();
	if (s[0] == ' ')
	{
		s.erase(0, 1);
	}
}

//Number of 1 Bits
vector<int> binary(32, 0);
void int2binary(int n)
{
	int i = 31;
	while (n)
	{
		binary[i--] = n % 2;
		n /= 2;
	}
}
int hammingWeight(unsigned int n) 
{
	int count = 0;
	int2binary(n);
	for (int i = 0; i < 32;++i)
		if (binary[i] == 1)
			count++;
	return count;
}

//Contains Duplicate
bool containsDuplicate(vector<int>& nums) 
{
	
	return nums.size()>set<int> (nums.begin(), nums.end()).size();
}
int main()
{
	int n = 4;
	cout<<n<<" "<<hammingWeight(n);
	
	//Integer to Roman
	/*int num = 101;
	cout<<intToRoman(num);*/
	//Roman to Integer
	/*string s = "XI";
	cout << romanToInt(s);*/
	//Implement strStr() 
	/*char s1[20] = "mississippi", s2[20] = "issip";
	cout<<strStr(s1, s2);*/
	//math
	//Permutation Sequence 
	/*int n = 9, k=40322;
	string str = getPermutation(n, k);
	cout << str;*/
	//Sqrt(x)	
	/*int x = 65535;	
	x = sqrt1(x);
	cout << x;*/
	//Pow(x, n)
	/*int n=123546;
	long double x = 8.88023,r;
	r = pow1(x, n);
	cout << r;*/
	//Remove Nth Node From End of List
	/*ListNode *p,*head=NULL;
	int a;
	int  n = 1;
	for (int i = 0; i < 2; i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		cin >> a;
		p->val = a;
		p->next = head;
		head = p;
	}

	*p=*removeNthFromEnd(head, n);
	for (int i = 0; i < 2; i++)
	{
		cout << p->val << endl;
		p = p->next;
	}*/
	//Length of Last Word 
	/*const char s[100] = "       ";
	int l;
	l = lengthOfLastWord(s);
	cout << l;*/
	//Add Binary 	
	//Palindrome Number
	/*long long x = 234565432;
	bool b = isPalindrome(x);
	cout << b;*/
	//Two Sum
	/*vector<int> number,two;
	int target=9;
	number.push_back(2);
	number.push_back(7);
	number.push_back(11);
	number.push_back(15);
	two=twoSum(number, target);
	cout << two[0] << " " << two[1];*/
	//Maximum Subarray 
	/*int A[] = {-2,1,-3,4,-1,2,1,-5,4},n=9;
	cout<<maxSubArray(A, n);*/
	//Reverse Linked List II
	/*int a;
	ListNode *p;
	int m = 1, n = 2;
	for (int i = 0; i < 3; i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		cin >> a;
		p->val = a;
		p = p->next;
	}
	*reverseBetween(p, m, n);*/

	//Remove Duplicates from Sorted List
	/*int a;
	ListNode *p;
	for (int i = 0; i < 2; i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		cin>>a;
		p->val=a;
		p = p->next;
	}
	*deleteDuplicates(p);*/
	
	//Pascal's Triangle II 
	/*vector<int> matrix;
	matrix=getRow(6);
	for (int i = 0; i < 6; i++)
		cout << matrix[i] << " ";*/
	//Pascal's Triangle 
	/*vector<vector<int > >matrix;
	matrix=generate(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}*/
	//Unique Paths 
	/*unsigned long m, n;
	long long  v1 = 1, v2 = 1;
	m = 10; n = 10;
	for (int i = m; i<m + n - 1; i++)
	{
		v1 *= i;
	}
	cout << v1<<" ";
	for (int i = 1; i<n; i++)
	{
		v2 *= i;
	}
	cout << v1 / v2;*/
	//Rotate Image  顺时针转90度
	/*int b[][3] = { 1, 2, 3, 6,5,4,7,8,9 };
	vector<vector<int> > a(3);
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			a[i].push_back(b[i][j]);
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	retate(a);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}*/
	system("pause");
	return 0;
}