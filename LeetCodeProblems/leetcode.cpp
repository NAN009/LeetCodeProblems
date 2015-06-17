#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<time.h>
#include<stdlib.h>
#include <set>
#include "LinkedLIst.h"
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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
//Linked List Cycle
bool hasCycle(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return false;
	}
	ListNode *first = head, *second = head->next;
	while (second&&second->next)
	{
		if (first == second)
			return true;
		first = first->next;
		second = second->next->next;
	}
	return false;
}
//Remove Duplicates from Sorted List
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
ListNode *deleteDuplicates_leetcode(ListNode *head) //未使用额外空间
{
	ListNode *list = head;
	while (list != nullptr)
	{
		if (list->next=nullptr)
			break;
		if (list->val == list->next->val)
			list->next = list->next->next;
		else
			list = list->next;
	}
	return head;
}
//Swap Nodes in Pairs 
ListNode* swapPairs(ListNode* head) 
{
	if (head == nullptr||head->next == nullptr  )
		return head;
	ListNode *first = head;
	while (first&&first->next)
	{
		first->val = first->next->val + first->val;
		first->next->val = first->val - first->next->val;
		first->val = first->val - first->next->val;
		first = first->next->next;
	}
	return head;
}
//Merge Two Sorted Lists 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) //方法有误
{
	ListNode *l=nullptr, *cur1 = l1, *cur2 = l2,*cur=l;
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	while (cur1&&cur2)
	{
		l = cur2;
		l2 = cur2->next;
		l1 = cur1->next;
		cur1->next=cur2;
		l = cur1;
		cur2 = l2;
		cur1 = l1;
	}
	if (cur1)
		l = cur1;
	else
		l = cur2;
	return l;
}
ListNode *mergeTwoLists_leetcode(ListNode *l1, ListNode *l2)
{
	if (l1 == nullptr)
		return l2;
	if (l2 = nullptr)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l2->next, l1);
		return l2;
	}
}
//Reverse Linked List II
ListNode *reverseBetween1(ListNode *head, int m, int n)
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
//Reverse Linked List 
ListNode* reverseList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *pos = head->next, *cur = head;
	cur->next = NULL;
	while (pos)
	{
		head = pos;
		pos = pos->next;
		head->next = cur;
		cur = head;
	}
	return head;
}
//Remove Linked List Elements 
ListNode* removeElements(ListNode* head, int val)
{
	while (head != NULL&&head->val == val)//while (head->val == val&&head != NULL)如果改写为这样，就会出错。因为当head为空时，while 语句先判断head->val == val，但head->val不存在故报错
	{
		head = head->next;
	}
	if (head == NULL)
		return NULL;
	ListNode *cur=head->next, *prev = head;
	while (cur)
	{
		if (cur->val == val)
			prev->next = cur->next;
		else
			prev = prev->next;
		cur = cur->next;
	}
	return head;
}
ListNode* removeElements_leetcode(ListNode* head, int val)//递归
{
	if (head = NULL)
		return NULL;
	head->next = removeElements_leetcode(head->next, val);
	return head->val == val ? head->next : head;
}
//Linked List Cycle II 
//http://www.cnblogs.com/x1957/p/3406448.html
ListNode *detectCycle(ListNode *head) 
{
	if (head == NULL||head->next==NULL)
		return NULL;
	ListNode *s = head, *f = head; 
	bool isCycle = false;
	while (f&&s)
	{
		f = f->next;
		if (s->next == NULL)
			return NULL;
		s = s->next->next;
		if (f == s)
		{
			isCycle = true;
			break;
		}
	}
	if (!isCycle)
		return NULL;
	f = head;
	while (f!=s)
	{
		f = f->next;
		s = s->next;
	}
	return f;
}
//Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) //头插法
{
	ListNode *l = NULL;
	int carry=0;
	while (l1&&l2)
	{
		ListNode *head = new ListNode((l1->val + l2->val + carry) % 10);
		carry = (l1->val + l2->val + carry) / 10;
		head->next = l;
		l = head;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		ListNode *head = new ListNode((l1->val + carry) % 10);		
		carry = (l1->val + carry) / 10;
		head->next = l;
		l = head;
		l1 = l1->next;
	}
	while (l2)
	{
		ListNode *head = new ListNode((l2->val + carry) % 10);
		head->val = (l2->val + carry) % 10;
		carry = (l2->val + carry) / 10;
		head->next = l;
		l = head;
		l2 = l2->next;
	}
	if (carry)
	{
		ListNode *head = new ListNode( carry % 10);
		head->next = l;
		l = head;
	}
	return l;
}
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2)//error
{
	ListNode head(0),*cur=&head,*tmp=NULL;
	int carry = 0;
	while (l1&&l2)
	{
		cur->next = new ListNode((l1->val + l2->val + carry) % 10);
		carry = (l1->val + l2->val+carry) / 10;
		cur=cur->next;		
		l1 = l1->next;
		l2 = l2->next;
	}
	
	while (l1)
	{
		cur->next = new ListNode((tmp ? tmp->val : 0 + carry) % 10);
		carry = (tmp ? tmp->val : 0+carry) / 10;
		cur = cur->next;
		tmp = tmp ? tmp->next : tmp;
	}
	return head.next;
}
ListNode* addTwoNumbers_leetcode(ListNode* l1, ListNode* l2)//尾插法
{
	ListNode prehead(0), *p = &prehead;
	int carry = 0;
	while (l1 || l2 || carry)
	{
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		carry = sum / 10;
		p->next = new ListNode(sum % 10);
		p = p->next;
		l1 = l1 ? l1->next : l1;//?: 优先级大于=
		l2 = l2 ? l2->next : l2;
	}
	return prehead.next;
}
//Reverse Linked List II
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
		ListNode prehead(0), *l = &prehead, *p = NULL,*q=NULL;
		int count = 1;
		while (head)
		{
			if (count >= m&&count <= n)//头插法
			{
				p = new ListNode(head->val);
				p->next=q;
				q = p;
			}
			else 	//尾插法
			{			
				l->next = new ListNode(head->val);
				l = l->next;
			}
			while(count>=n&&q)
			{
				l->next = q;
				l = l->next;
				q = q->next;
			}		
			head = head->next;
			count++;
		}
		return prehead.next;	
}
//Insertion Sort List 
ListNode* insertionSortList(ListNode* head)
{
	if (head == NULL||head->next==NULL)
		return head;
	int miximal = 10000;
	ListNode *h = head;
	while (h)
	{
		if (h->val < miximal)
			miximal = h->val;
		h = h->next;
	}
	ListNode prehead(miximal);	
	while (head)
	{
		ListNode *cur = &prehead;
		while (cur->next)
		{
			if (head->val >= cur->val&&head->val<=cur->next->val)
			{
				ListNode *next = cur->next;
				cur->next = new ListNode(head->val);
				cur->next->next = next;
				break;
			}
			cur = cur->next;
		}
		if (cur->next == NULL)
		{
			if (head->val >= cur->val)
				cur->next = new ListNode(head->val);
		}
		head = head->next;
	}
	return  prehead.next;
}
//Rotate List
ListNode* rotateRight(ListNode* head, int k)
{
	if (head == NULL || head->next == NULL)
		return head;
	int count = 0;
	ListNode *p = head, prehead(0), *l = &prehead;
	while (p)
	{
		p = p->next;
		count++;
	}
	if (k > count)
		k = k%count;
	p = head;
	for (int i = 0; i < count; i++)
	{
		if (i >= count - k)
		{
			l->next = new ListNode(p->val);
			l = l->next;
		}
		p = p->next;
	}
	p = head;
	for (int i = 0; i < count-k; i++)
	{
		l->next = new ListNode(p->val);
		l = l->next;
		p = p->next;
	}
	return prehead.next;
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
//Implement strStr() 字符串匹配算法
//暴力破解
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
//kmp
static void compute_prefix(const char *pattern, int next[])
{
	int i;
	int j = -1;
	const int m = strlen(pattern);
	next[0] = j;
	for (i = 1; i < m; ++i)
	{
		while (j>-1 && pattern[j + 1] != pattern[j])
			j = next[j];
		if (pattern[i] == pattern[j + 1])
			j++;
		next[i] = j;
	}
}
static int kmp(const char *text, const char *pattern)
{
	int i, j = -1;
	const int n = strlen(text), m = strlen(pattern);
	if (n == 0 && m == 0)
		return 0;
	if (m == 0)
		return 0;
	int *next = new int[m];
	compute_prefix(pattern, next);
	for (i = 0; i < n; ++i)
	{
		while (j>-1 && pattern[j + 1] != text[i])
			j = next[j];
		if (text[i] == pattern[j + 1])
			j++;
		if (j == m - 1)
		{
			delete[]next;
			return i - j;
		}
	}
	delete[]next;
	return -1;
}
int strStrKmp(char *haystack, char *needle)
{
	int pos = kmp(haystack, needle);	
	return pos;
}
//sundary算法：首先将两个指针指向起始位置，当发现失配时，判断母串中子串后一位的对应位置的字符（k指向）在子串中是否存在。若存在，将该位置和子串中该字符对齐，然后从子串头部开始匹配。若不存在，将子串后移并和母串的k+1位置对齐，再进行匹配。重复上述操作至被遍历完
int position(string neddle, char c)
{
	int i = neddle.size() - 1;
	while (neddle[i])
	{
		if (neddle[i] == c)
			return i;
		i--;
	}
	return -1;
}
int sundary(string haystack, string neddle)
{
	int lenHaystack = haystack.size(),lenNeddle=neddle.size();
	int i = 0,j = 0, pos;
	while (j<lenHaystack)
	{
		i = 0;
		while(haystack[i + j] == neddle[i])
		{
			i++;
			continue;
		}
		if (neddle[i] == '\0')
			return j;
		pos = position(neddle, haystack[j + lenNeddle]);
		if (pos != -1)
			j += pos;
		else
			j += (lenNeddle + 1);
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
//Container With Most Water
//在距离减小时，只有比本身大的才有可能比本身大
int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1,area=0;
	while (left < right)
	{
		area = max(area, (right - left)*min(height[right], height[left]));
		height[left]>height[right] ? right-- : left++;
	}
	return area;
}
//Happy Number
int ret(int temp)
{
	int sum = 0;
	while (temp)
	{
		sum += (temp % 10) * (temp % 10);
		temp /= 10;
	}
	return sum;
}
bool isHappy(int n) {
	int temp = n;
	if (temp == 0)
		return false;
	while (temp!=1&&temp!=7)
	{
		if (temp > 1 && temp < 10)
			return false;
		temp = ret(temp);
	}
	return true;
}
//Rotate Array 
void rotate(vector<int>& nums, int k) 
{
	if (k <=0)return;
	if (k>nums.size() - 1)
		k %= nums.size();
	int len = nums.size() - k;
	for (int i = 0; i < len; ++i)
	{
		nums.push_back(nums[i]);
	}
	nums.erase(nums.begin(), nums.begin() + len);
}
void rotate1(int nums[], int n, int k) {
	k = k % n;
	reverse(nums, nums + n);	
	reverse(nums, nums + k);	
	reverse(nums + k, nums + n);	
}
//Trapping Rain Water 
//Find Peak Element  并非最大值，而是极大值，下面第一个是最大值，第二个是极大值
int findPeakElement(vector<int>& nums) {
	int index = 0, peakVal = nums[0];
	for (int i = 1; i < nums.size() - 1; ++i)
	{
		if (nums[i]>nums[i-1]&&nums[i]>nums[i+1])
		{
			if (nums[i] > peakVal)
			{
				index = i;
				peakVal = nums[i];
			}		
		}
	}
	if (nums[nums.size() - 1] > peakVal)
		return nums.size() - 1;
	return index;
}
int findPeakElement1(const vector<int> &num) 
{
	int low = 0, high = num.size() - 1;
	while (low < high - 1) {
		int mid = (low + high) / 2;
		if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1])
			return mid;
		else if (num[mid] > num[mid + 1])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return num[low] > num[high] ? low : high;
}
//Valid Palindrome
bool isPalinrome(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower); //transform 将某操作应用于指定范围的每个元素
	auto left = s.begin(), right = prev(s.end()); //prev(): Get iterator to previous element
	while (left < right)
	{
		if (!::isalnum(*left))
			++left;
		else if (!::isalnum(*right))
			--right;
		else if (*left != *right)
			return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;		
}
//Count and Say 
string countAndSay(int n) 
{
	int i = 3;
	if (n == 1)
		return "1";
	string s1,s="11";
	if (n == 2)
		return s;
	while (i <= n)
	{
		int count = 1;
		for (int j = 0; j < s.size(); ++j)
		{			
			if (s[j] != s[j + 1])
			{
				s1 += count+'0';
				s1 += s[j];
				count = 1;
			}
			if (s[j]==s[j+1])
				count++;			
		}
		s = s1;
		s1.clear();
		i++;
	}
	return s;
}
string countAndSay_leetcode(int n)
{
	if (0 == n)
		return "";
	if (1 == n)
		return "1";
	string res = "1";
	string s;
	for (int i = 1; i < n; ++i)
	{
		int len = res.size();
		for (int j = 0; j < len; ++j)
		{
			int count = 1;
			while ((j + 1 < len) && (res[j] == res[j+1]))
			{
				count++;
				j++;
			}
			s += to_string(count) + res[j];//Returns a string with the representation of val.
		}
		res = s;
		s.clear();
	}
	return res;
}
//Valid Number
bool isPositiveNumber(string s)
{
	int point_position= -1,count_digit=0,e_pisition=-1;
	if (!isdigit(s[0]))
		return false;
	for (int i = 1; i < s.size(); ++i)
	{			
		if (!isdigit(s[i]))
		{
			if (s[i] == '.')
			{
				if (point_position != -1)
					return false;
				point_position = i;
			}
			else if (s[i] == 'e')
			{
				if (i == s.size() - 1)
					return false;
				if (e_pisition != -1)
					return false;
				e_pisition = i;
			}
			else if (s[i] == '-')
			{
				if (!(s[i - 1] == 'e'&&isdigit(s[i+1])))
					return false;
			}
			else if (s[i] == '+')
			{
				if (!(s[i - 1] == 'e'&&isdigit(s[i + 1])))
					return false;
			}
			else
				return false;
		}				
	}
	if (e_pisition < point_position&&e_pisition!=-1)
		return false;
	return true;
}
bool isNumber(string s)
{
	if (s.empty())
		return false;
	if (s.size() == 1 && isdigit(s[0]))
		return true;
	int count_plus = 0,count_subtraction;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[0] == ' ')
		{
			s.erase(s.begin());
		}	
		else
			break;
	}
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if (s[s.size()-1] == ' ')
		{
			s.erase(s.end()-1);
		}
		else
			break;
	}
	if (s[0]=='-')
	{
		s.erase(s.begin());
		if (isPositiveNumber(s))
			return true;
	}
	if (s[0] == '+')
	{
		s.erase(s.begin());
		if (isPositiveNumber(s))
			return true;
	}
	if (isdigit(s[0]))
		return isPositiveNumber(s);
	int e_pisition = -1;
	if (s[0] == '.'&&s.size()>1)
	{
		if (!isdigit(s[1]))
			return false;
		for (int i = 2; i < s.size(); ++i)
		{
			if (!isdigit(s[i]))
			{
				if (s[i] == 'e')
				{
					if (i == s.size() - 1)
						return false;
					if (e_pisition != -1)
						return false;
					e_pisition = i;
				}
				else if (s[i] == '-')
				{
					if (!(s[i - 1] == 'e'&&isdigit(s[i + 1])))
						return false;
				}
				else if (s[i] == '+')
				{
					if (!(s[i - 1] == 'e'&&isdigit(s[i + 1])))
						return false;
				}
				else
					return false;
			}
		}
		return true;
	}
	return false;
}

//Minimum Window Substring
string minWindow(string s, string t)
{
	
	return s;
}
//Multiply Strings
string add(string s1, string s2)
{
	string s;
	int carry = 0;
	if (s1.size() > s2.size())
		s2.swap(s1);
	for (int i = 0; i < s2.size(); ++i)
	{
		if (i < s1.size())
		{
			int x = s1[i] - '0' + s2[i] - '0' + carry;
			s.push_back(x % 10 + '0');
			carry = x / 10;
		}
		else
		{
			int x = s2[i] - '0' + carry;
			s.push_back(x % 10 + '0');
			carry = x / 10;
		}
	}
	if (carry!=0)
		s.push_back(carry + '0');
	return s;
}
string multiply(string num1, string num2)
{
	vector<string> mul(num1.size()+num2.size());
	string s1;
	for (int i = num1.size() - 1; i >= 0;i--)
	{
		int temp = 0;
		for (int k = 0; k < num1.size() - 1 - i; ++k)
			mul[i].push_back('0');
		for (int j = num2.size() - 1; j >= 0;j--)
		{
			int x = (num1[i]-'0') * (num2[j]-'0')+temp;	
			mul[i].push_back(x % 10 + '0');
			temp = x / 10;
		}
		if (temp!=0)
			mul[i].push_back(temp+'0');
	}
	s1 = mul[0];
	for (int i = 1; i < mul.size();i++)
	{	
		if (mul[i].empty())
			break;
		s1=add(s1, mul[i]);
	}
	reverse(s1.begin(), s1.end());
	while (s1.size()!=1)
	{
		if (s1[0] == '0')
			s1.erase(s1.begin());
		else 
			break;
	}			
	return s1;
}
string multiply_leetcode(string num1, string num2)
{
	string sum(num1.size() + num2.size(), '0');
	for (int i = num1.size() - 1; 0 <= i; --i)
	{
		int carry = 0;
		for (int j = num2.size() - 1; 0 <= j; --j)
		{
			int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
			sum[i + j + 1] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		sum[i] += carry;
	}
	size_t startpos = sum.find_first_not_of("0");
	if (string::npos != startpos)
		return sum.substr(startpos);
	return "0";
}
//Kth Largest Element in an Array
int findKthLargest(vector<int>& nums, int k) //囧
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}
int partition(vector<int> nums, int left, int right)
{
	int pivot = nums[left];
	int l = left + 1,r=right;
	while (l<=r)
	{
		if (nums[l]<pivot&&nums[r]>pivot)
			swap(nums[l++],nums[r--]);
		if (nums[l] >= pivot)l++;
		if (nums[r] <= pivot)r--;
	}
	swap(nums[left], nums[r]);
	return r;
}
int findKthLargest_leetcode(vector<int>& nums, int k)
{
	int left = 0, right = nums.size() - 1;
	while (true)
	{
		int pos = partition(nums, left, right);
		if (pos == k - 1)return nums[pos];
		if (pos > k - 1)return pos - 1;
		else 
			left = pos + 1;
	}
}
//Set Matrix Zeroes
void setZeroes(vector<vector<int>>& matrix) 
{

	vector<int> col(matrix[0].size(),0),row( matrix.size(), 0);
	for (int i = 0; i < matrix.size();++i)
	{
		for (int j = 0; j < matrix[0].size();++j)
		{
			if (matrix[i][j] == 0)
			{
				col[j] = 1;
				row[i] = 1;
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (row[i] != 0)
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < matrix[0].size(); ++i)
	{
		if (col[i] != 0)
		for (int j = 0; j < matrix.size(); ++j)
		{
			matrix[j][i] = 0;
		}
	}	
}
void setZeroes_leetcode(vector<vector<int>>& matrix)
{
	int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
	for (int i = 0; i < rows; i++)
	{
		if (matrix[i][0] == 0)col0 = 0;
		for (int j = 1; j < cols;++j)
		{
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
		}
	}
	for (int i = rows - 1; i >= 0; i--)
	{
		for (int j = cols - 1; j >= 1;j--)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
		if (col0 == 0)
			matrix[i][0] = 0;
	}
}

int main()
{
	int a[5] = {1,2,3,4,5};
	ListNode prehead(0),*p=&prehead;
	int m = 1, n = 2;
	for (int i = 0; i < 5; i++)
	{
	    p->next = new ListNode(a[i]);
		p = p->next;
	}
	p = rotateRight(prehead.next,n);
	
	
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