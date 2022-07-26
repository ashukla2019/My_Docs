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
