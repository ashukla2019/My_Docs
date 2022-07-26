ListNode *detectCycle(ListNode *head) 
{
	if (!head) return NULL;
	ListNode * slow = head, * fast = head;

	while (fast and fast -> next) 
	{
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) 
		{
			fast = fast;
			slow = head;

			while (slow != fast) 
			{
				slow = slow -> next;
				fast = fast -> next;
			}
		}
		return slow; //this is the point where loop starts....
		//we can count loop value by...while(slow != fast) {slow = slow->next; fast= fast->next}
	}
  return NULL;

}