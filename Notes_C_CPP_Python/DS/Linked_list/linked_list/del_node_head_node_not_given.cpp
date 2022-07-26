//Delete Node in a Linked List, when head of linked list is not given.
//approach: we can not go back, we will make current node(to be deleted) to next node 
//and will delete next node.
void deleteNode(ListNode* node) 
{
	node->val = node->next->val;
	node->next = node->next->next;
}