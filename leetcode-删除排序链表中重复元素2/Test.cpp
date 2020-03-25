struct ListNode
{
	int val;
	ListNode* head;
	ListNode* next;
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* tmp = new ListNode(-1);
		ListNode* slow = tmp;
		ListNode* fast = head;
		tmp->next = head;

		while (fast && fast->next)
		{
			if (fast->val != fast->next->val)
			{
				if (slow ->next== fast)
				{
					slow = fast;
				}
				else
				{
					slow->next = fast->next;
				}
				
			}
			fast = fast->next;
		}
		if (slow->next != fast)   //遇到[1,1]这种情况
		{
			slow->next = fast->next;
		}
		return tmp->next;
	}
};