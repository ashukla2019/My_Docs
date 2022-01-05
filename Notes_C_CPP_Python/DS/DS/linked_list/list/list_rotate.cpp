//This file rotate linkedlist after index value =k


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
	temp->next = nullptr;
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

void rotate_list(struct node** head, int k)
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
	node* head = nullptr;
	add_node(&head, 5);
	add_node(&head, 10);
	add_node(&head, 15);
	add_node(&head, 20);
	add_node(&head, 25);
	add_node(&head, 30);
	display(&head);
	rotate_list(&head, 4);
	display(head);
	return 0;
}
