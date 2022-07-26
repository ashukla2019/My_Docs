int treeHeight(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int ltreeHeight = treeHeight(root->left);
		int rtreeHeight = treeHeight(root->right);
		return max(ltreeHeight,rtreeHeight)+1;
	}
	
}