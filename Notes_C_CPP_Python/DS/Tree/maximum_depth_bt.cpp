/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the 
root node down to the farthest leaf node.

Input: root = [3,9,20,null,null,15,7]
Output: 3

*/

int maxDepth(TreeNode* root) 
{
	if(!root) return 0;
	int maxLeft = maxDepth(root->left);
	int maxRight = maxDepth(root->right);
	return max(maxLeft, maxRight)+1;
}