int findMinimum(Node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	else if((root->left)== NULL)
	{
		return root->data;
	}
	return findMinimum(root->left);
}