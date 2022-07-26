/*
You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees
are overlapped while the others are not. You need to merge the two trees into a new
binary tree. The merge rule is that if two nodes overlap, then sum node values up
as the new value of the merged node. Otherwise, the NOT null node will be used as the node
of the new tree.

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

*/


TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) 
{
	//Base case:
	if(r1==NULL)return r2;
	if(r2==NULL)return r1;
	
	//add value of first list and second list
	r1->val = r1->val + r2->val;
	r1->left = mergeTrees(r1->left,r2->left);
	r1->right =  mergeTrees(r1->right,r2->right);
	return r1;
}