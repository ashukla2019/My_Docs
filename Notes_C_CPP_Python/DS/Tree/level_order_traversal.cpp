//Level order traversal
void bfs(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		queue<Node*>Q;
		Q.push(root);
		while(!Q.empty())
		{
			Node* current  = Q.front();
			cout<<current->data<<endl;
			if(current->left != NULL)
			{
				Q.push(current->left);
			}
			if(current->right != NULL)
			{
				Q.push(current->right);
			}
			Q.pop();
		}
	}
}
