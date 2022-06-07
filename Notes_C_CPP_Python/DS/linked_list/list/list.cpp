//This file is for all basic linked list operations

#include <iostream>
#include <cstring>
using namespace std;

class ListNode
{
	public:
		int val;
		ListNode* next;
};
	
void add_data_end(ListNode** head, int data)
{
	ListNode *temp = new ListNode();
	temp->val = data;
	temp->next = NULL;
	if(NULL == *head)
	{
		*head = temp;
	}
	else
	{
		ListNode* t = *head;
		while(t->next != nullptr)
		{
			t = t->next;
		}
		t->next = temp;
	}
}

void delete_data_end(ListNode** head)
{
	ListNode* temp, *q;
	temp = *head;
	while(temp->next->next !=nullptr)
	{
		//q = temp;
		temp = temp->next;
	}
	temp->next = NULL;
	//free(temp);
}

void add_data_beg(ListNode** head, int item)
{
	ListNode* temp = new ListNode();
	temp->val = item;
	temp->next = *head;
	*head = temp;
}

void delete_data_beg(ListNode** head)
{
	ListNode* temp;
	temp = *head;
	*head = temp->next;
	free(temp);
	
}

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
void show_data(ListNode* head)
{
	ListNode *temp;
	temp = head;
	while(temp !=NULL)
	{
		cout<<"data values:"<<temp->val<<endl;
		temp = temp->next;
	}
}

int main(int argc, char* argv[])
{
	ListNode* head = nullptr; 
	add_data_end(&head,10); 
	add_data_end(&head,20);
	show_data(head);
	reverse_list(&head);
	cout<<"After reversing:"<<endl;
	show_data(head);
	add_data_beg(&head, 5);	
	cout<<"After adding at begin"<<endl;
	show_data(head);
	delete_data_beg(&head);
	cout<<"After deleting at begin"<<endl;
	show_data(head);
	delete_data_end(&head);
	cout<<"After deleting at end"<<endl;
	show_data(head);
	add_data_end(&head,30);
	cout<<"After adding data at end"<<endl;
	show_data(head);
	return 0;
}

//Delete Node in a Linked List, when head of linked list is not given.
//approach: we can not go back, we will make current node(to be deleted) to next node 
//and will delete next node.
void deleteNode(ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}

//Add two numbers represented by Linked list:

//Get middle node of linked list: Time complexity o(n/2) because we traverse only half nodes => o(n)
//tortoise and hare approach: Hare will move 2 steps and tortoise will move 1 step.
int getMiddle(ListNode *head)
    {
         if(head==nullptr){
            return 0;
        }
        ListNode* hare=head;
        ListNode*tortoise=head;
        while(hare!=nullptr && hare->next!=nullptr){
            tortoise=tortoise->next;
            hare=hare->next->next;
        }
        return tortoise->val;
   
    }

//Get the nth node from the end of linked list:
//difference b/w last node and nth node will be n-1. this difference can be covered first for
//first pointer and then difference b/w first and second will be n-1. then e can move
//both pointer one step and once first reaches last node, will find desired node pointed by second.
int getNthFromLast(ListNode* head, int k)
{
	ListNode* first = head;
	for(int i =1; i < k; i++)
	{
		first = first->next;
	}
	ListNode* second = head;
	while(first->next != nullptr)
	{
 		first = first->next;
		second = second->next;
	}
	return second->val;
}

//Rotate the linked list 
void rotate_list(ListNode** head, int k)
{
	if (k == 0)
        return;
 
    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    ListNode* current = *head;
 
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

//Palindrome: Check palindrome of linked list of numbers.
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
 This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(ListNode* loop_node, ListNode* head)
{
    ListNode* ptr1 = loop_node;
    ListNode* ptr2 = loop_node;

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
  
int detectAndRemoveLoop(ListNode* list)
{
    ListNode *slow_p = list, *fast_p = list;

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

/*
//Flattening the linked list:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8           50   40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
*/
ListNode* merge(ListNode* a, ListNode* b)
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
    ListNode* result;
  
    if (a->val < b->val) 
    {
        result = a;
        //result->bottom = merge(a->bottom, b);
    }
  
    else 
    {
        result = b;
        //result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
  
ListNode* flatten(ListNode* root)
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

//understand recursion used in flatten function():
//main()
//flatten(5)
//5->next = flatten(10)
//10->next = flatten(19)
//19->next = flatten(28)
//now since 28->next = null, recursion will stop here and root which has value 28 will be
//returned to caller(19->next = flatten(28)) => 19->next = 28
//will call merge(19, 28) and returned merged list will be assigned to root.
// root(19->head) will be assigned to next caller(10->next = flatten(19) => merged list with head 19
//merge(10,19) will be done now same way, merged returned list will be assigned to next caller
//(5->next = 10)....

