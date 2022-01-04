//This file merges two sorted linkedlist.

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

void add_node(struct node** head, int data)
{
	node* temp = (struct node*)malloc(sizeof(node));
	temp->data = data;
	if(*head == nullptr)
	{
		*head = temp;
		temp->next = nullptr;
	}
	else
	{
		temp->next = *head;
		*head = temp;
	}
}
//How recursive call works:
/* stack is growing from down to up...once function returns null, then all pending calls will be resumed...
result = 600                         ---------->now stack will solve previous calls since function has returned with value 600...
result->next = merge_list(NULL, 600)
- - - - - - - - - - - - - - - - - - - - - - - - - - -- -
result = 300
result->next = merge_list(NULL, 600)  ---> this will take address 600 and assign to result->next
- - - - - - - - - - - - - - - - - - - - - - - - - - -- -
result = 500
result->next = merge_list(300, 600)  ---> this will take address 300 and assign to result->next
- - - - - - - - - - - - - - - - - - - - - - - - - - -- -
result = 200
result->next = merge_list(300, 500) ---> this will take address 500 and assign to result->next
- - - - - - - - - - - - - - - - - - - - - - - - - - -- - 
result = 400
result->next = merge_list(200, 500) ---> this will take address 200 and assign to result->next
- - - - - - - - - - - - - - - - - - - - - - - - - - -- - 
result = 100 -> value at address(5)
result->next = merge_list(200, 400) ---> this will take address 400 and assign to result->next
- - - - - - - - - - - - - - - - - - - - - - - - - - -- - 
main()->merge_list(100, 400) ---> this will take address 100 and assign to result->next

*/

node* merge_list(struct node* head_first, struct node* head_second)
{
	node* result = nullptr;
	if(head_first == nullptr)
	{
		return head_second;
	}
	if(head_second == nullptr)
	{
		return head_first;
	}
	if (head_first->data <= head_second->data) 
    { 
        result = head_first; 
        result->next = merge_list(head_first->next, head_second); 
    } 
    else
    { 
        result = head_second; 
        result->next = merge_list(head_first, head_second->next); 
    } 
    return(result); 
}

void display(struct node* head)
{
	node* temp;
	temp = head;
	while(temp != nullptr)
	{
		cout<<"Values:"<<temp->data<<endl;
		temp = temp->next;
	}
}

int main()
{
	node* head_first = nullptr, *head_second = nullptr, *head_result = nullptr;
	add_node(&head_first, 15); //address is 300
	add_node(&head_first, 10); //address is 200
	add_node(&head_first, 5); //address is 100
	add_node(&head_second, 16); //address is 600
	add_node(&head_second, 11); //address is 500
	add_node(&head_second, 6); //address is 400
	display(head_first);
	display(head_second);
	node* result = merge_list(head_first, head_second);
	display(result);
	return 0;
}
