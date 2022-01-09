//Delete Node in a Linked List:
void deleteNode(ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}

//Add two numers represented by Linked list:

//Get middle node of linked list
int getMiddle(Node *head)
    {
         if(head==nullptr){
            return 0;
        }
        Node* slow=head;
        Node*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
   
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

//Rotate the linked list 
//void rotate_list(struct node** head, int k)
{
	if (k == 0)
        return;
 
    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    node* current = *head;
 
    // Traverse till the end.
    while (current->next != NULL)
        current = current->next;
 
    current->next = *head;
    current = *head;
 
    // traverse the linked list to k-1 position which
    // will be last element for rotated array.
    for (int i = 0; i < k - 1; i++)
        current = current->next;
 
    // update the head_ref and last element pointer to NULL
    *head = current->next;
    current->next = NULL;
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
