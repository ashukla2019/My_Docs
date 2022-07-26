ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//Declare a list to store it's result and head pointer
	ListNode* head = new ListNode(0);
	ListNode* result = head;

	//Two variables one for carry and other for sum  
	int carry = 0;
	int sum = 0;

	//Run a loop while condition is true
	while(l1 != nullptr || l2 != nullptr || carry != 0) 
	{

		//For each iteration set the value of sum to zero
		sum = 0;

		//If linked list 1 is not empty
		if(l1 != nullptr) 
		{
			sum = sum + l1->val;
			l1 = l1->next;
		}

		//If linked list 2 is not empty
		if(l2 != nullptr) 
		{
			sum = sum + l2->val;
			l2 = l2->next;
		}

		sum = sum + carry;
		carry = sum/10;

		//Create a new node
		result->next = new ListNode(sum%10);
		result = result->next;
	}

	return head->next;
}