//Detect if cycle in linked list.... 
bool hasCycle(ListNode *head) 
{
	ListNode* slow = head, *fast = head;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			return 1;
		}
	}
	return 0;
}