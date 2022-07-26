
int findMaximum(Node* root)
{
	if(root == NULL)
	{
		return -1;
	}
	else if((root->right)== NULL)
	{
		return root->data;
	}
	return findMaximum(root->right);
}
