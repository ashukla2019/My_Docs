//Delete Node in a Linked List:
void deleteNode(ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}

//Get the nth node from the end of linked list
int getNthFromLast(struct node* head, int k)
{
	node* first = head;
	for(int i =1; i < k; i++)
	{
		first = first->next;
	}
	node* second = head;
	while(first->next != nullptr)
	{
 		first = first->next;
		second = second->next;
	}
	return second->data;
}

//Palindrome:
bool isPalindrome(ListNode* head) 
{
	ListNode *node = head;
	string s;
	while(node)
	{
		int temp = node -> val;
		s += to_string(temp);
		node = node -> next;
	}

	string newS = string(s.rbegin(),s.rend());

	return s == newS ? true : false;
}

//Reverse linked list:
ListNode* reverseList(ListNode* head) 
{
	ListNode *prev = NULL;
	ListNode *temp = NULL;
	ListNode *current = head;
	while(current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
	return head;
}

//Merge linked list:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
	ListNode* result = nullptr;
	if(list1 == nullptr)
	{
		return list2;
	}
	if(list2 == nullptr)
	{
		return list1;
	}
	if (list1->val <= list2->val) 
	{ 
		result = list1; 
		result->next = mergeTwoLists(list1->next, list2); 
	} 
	else
	{ 
		result = list2; 
		result->next = mergeTwoLists(list1, list2->next); 
	} 
	return(result); 
}

//Detect cycle/loop in linkedlist:
bool hasCycle(ListNode *head) 
{
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast !=nullptr && fast->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
		{
			return true;
		}
	 }
	return false;
}
