void reverse_list(ListNode** head)
{
	ListNode *prev = NULL;
	ListNode *temp = NULL;
	ListNode *current = *head;
	while(current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	*head = prev;
}