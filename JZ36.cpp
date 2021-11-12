#include "common.h"

struct ListNode
{
	int val;
	struct ListNode *next;
};

void createList(ListNode *head, int *num)
{
	ListNode *p = head;
	for (int i = 0; i < head->val; i++)
	{
		ListNode *t = new ListNode;
		t->val = *(num + i);
		t->next = p->next;
		p->next = t;
		p = t;
	}
}

class Solution
{
public:
	ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
	{
		ListNode *p1 = pHead1;
		while (p1 != NULL)
		{
			ListNode *p2 = pHead2;
			while (p2 != NULL)
			{
				if (p1->val == p2->val)
					return p1;
				else
					p2 = p2->next;
			}
			p1 = p1->next;
		}
		return NULL;
	}
};

int main()
{
	Solution S;
	ListNode *pHead1 = nullptr;
	pHead1 = new ListNode;
	pHead1->next = NULL;
	pHead1->val = 5;
	int num1[] = {8, 7, 3, 4, 6};
	createList(pHead1, num1);

	ListNode *pHead2 = nullptr;
	pHead2 = new ListNode;
	pHead2->next = NULL;
	pHead2->val = 6;
	int num2[] = {11, 12, 13, 4, 14};
	createList(pHead2, num2);

	ListNode *ans = S.FindFirstCommonNode(pHead1, pHead2);
	cout << ans->val << endl;
}
