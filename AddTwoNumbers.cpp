#include "stdafx.h"

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a, b, r, c = 0;
		ListNode *p1 = l1, *p2 = l2;
		ListNode *re = NULL;
		ListNode *cur = NULL;
		while (p1 || p2 || c)
		{
			a = p1 ? p1->val : 0;
			b = p2 ? p2->val : 0;
			r = a + b + c;
			c = r / 10;
			r = r % 10;
			//form result
			if (cur == NULL)
			{
				re = cur = new ListNode(r);
			}
			else
			{
				cur->next = new ListNode(r);
				cur = cur->next;
			}
			//judge
			if(p1) p1 = p1->next;
			if(p2) p2 = p2->next;
		}
		return re;

	}
};