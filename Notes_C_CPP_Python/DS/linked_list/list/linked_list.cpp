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

/* Function to detect and remove loop in linkedlist
 /* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;

    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }

    /* Return 0 to indicate that there is no loop*/
    return 0;
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1 = loop_node;
    struct Node* ptr2 = loop_node;

    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    // Fix one pointer to head
    ptr1 = head;

    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}

//Flattening the linkedlist:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Node* merge(Node* a, Node* b)
{    
    // If first linked list is empty 
    // then second is the answer
    if (a == NULL)
        return b;
  
    // If second linked list is empty 
    // then first is the result
    if (b == NULL)
        return a;
  
    // Compare the data members of the 
    // two linked lists and put the larger 
    // one in the result
    Node* result;
  
    if (a->data < b->data) 
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
  
    else 
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
  
Node* flatten(Node* root)
{    
    // Base Cases
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge(root, root->next);
	return root;
}

