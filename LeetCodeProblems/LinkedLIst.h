//��������Ա���Ա��� ��11�� ����
#include <iostream>
using namespace std;
//What is the output of the following piece of c++ code?
struct Item
{
	char c;
	Item *next;
};
Item *Routine1(Item *x)//��������
{
	Item *prev = nullptr, *curr = x;
	while (curr)
	{
		Item *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
void Routine2(Item *x)
{
	Item *curr = x;
	while (curr)
	{
		cout << curr->c;
		curr = curr->next;
	}
}




