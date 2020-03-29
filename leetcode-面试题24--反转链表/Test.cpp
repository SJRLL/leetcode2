定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例 :

输入 : 1->2->3->4->5->NULL
输出 : 5->4->3->2->1->NULL

	 /**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};