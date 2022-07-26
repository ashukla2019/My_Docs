/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node
down to the nearest leaf node.

*/

int minDepth(TreeNode* root) 
{
	//Base case:
	if(root == nullptr)
	{
		return 0;
	}
	//find min from both left subtree and right subtree
	int minLeft = minDepth(root->left);
	int minRight = minDepth(root->right);
	
	//handle skewed tree: either left subtree is null or right subtree is null
	if(minLeft ==0 || minRight == 0)
	{
		return 1+ max(minLeft, minRight);
	}
	return 1+ min(minLeft, minRight);
	
}