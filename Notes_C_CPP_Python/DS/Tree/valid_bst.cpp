bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) 
{
	//Base case:
	if (root == NULL) 
	{
		return true;
	}
	//return false, if root->val is less than infinity or greater than infinity.
	if (root->val <= min || root->val >= max)
	{		
		return false;
	}
	//leftsubtree value is b/w -∞ and root. right sub tree value is b/w root and ∞.
	return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val,         max);
}