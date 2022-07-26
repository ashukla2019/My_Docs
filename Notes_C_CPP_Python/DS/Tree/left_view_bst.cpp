//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
	if(!root) 
	{
		return {};
	}
	vector<int> v; //store values of nodes in the rightmost
	queue<Node*> Q; //store node type values in queue 
	Q.push(root); //push root
	while(!Q.empty()) 
	{ //repeat steps until queue is not empty

		int size = Q.size();  // current size of queue
		for(int i = 0; i < size; i++) 
		{
			Node* t = Q.front(); //declare a temp node and put front node of queue
			Q.pop(); 
			if(i==0) 
			{   //if node is rightmost 
				v.push_back(t->data); //push the value of rightmost node into vector
			}
			if(t->left) 
			{   //if temp->left != NULL then push into queue
				Q.push(t->left);
			}
			if(t->right) 
			{ 
				//if temp->right != NULL then push into queue
				Q.push(t->right);
			}
		}
	}		
}
return v; //finally we have all values
    
}