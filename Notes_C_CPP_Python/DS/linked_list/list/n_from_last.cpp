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

//By recursion....
int findKthNode(struct node* node, int k)
{
    // base case
    if (node == NULL) {
        return 0;
    }
    int count = findKthNode(node->next, k)+1;  //this function will be called 6 times in below way: stack is grwoing from below to top...
    //<---- After finihing all calls(when it gets last node null, it returs and start executing pendinf calls for recursive calls)
    //findKthNode(5, 4)+1  it will return count which is 0 + 1 = 1 and then will execute remaining steps(if(count == K))
    //findKthNode(10, 4)+1 it will return count which is 1 + 1 = 2
    //findKthNode(15, 4)+1 it will return count which is 2 + 1 = 3
    //findKthNode(20, 4)+1 it will return count which is 3 + 1 = 4
    //findKthNode(25, 4)+1 it will return count which is 4 + 1 = 5
    //findKthNode(30, 4)+1 it will return count which is 5 + 1 = 6
    if (count == k) {
        printf("k'th node from the end is %d", node->data);
    }
 
    return count;
}

//by using two pointers...
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

int main()
{
	node* head = nullptr;
	add_node(&head, 5);
	add_node(&head, 10);
	add_node(&head, 15);
	add_node(&head, 20);
	add_node(&head, 25);
	add_node(&head, 30);
	//display(head);
	int data = findKthNode(head, 4);
	return 0;
	
}
