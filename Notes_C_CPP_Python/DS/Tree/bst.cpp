#include<iostream>
#include<queue>
using namespace std;
class Node 
{
	public:
	int data;
	Node *left;
	Node *right;
};
//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) 
	{
		root = root->left;
	}
	return root;
}

// Function to search a delete a value from tree.
Node* Delete(Node *root, int data) 
{
	if(root == NULL)
	{		
		return root; 
	}
	else if(data < root->data)
	{
		root->left = Delete(root->left,data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right,data);
	}
	else 
	{
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) 
		{ 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) 
		{
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else 
		{ 
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root) 
{
	if(root == NULL)
	{
		return;
	}
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Preorder
void Preorder(Node *root) 
{
	if(root == NULL)
	{
		return;
	}
 
	//Visit left subtree
	printf("%d ",root->data);  //Print data
	Preorder(root->left);  
	Preorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(Node *root) 
{
	if(root == NULL)
	{
		return;
	}
 
	Postorder(root->left);       //Visit left subtree
	Postorder(root->right);      // Visit right subtree
	printf("%d ",root->data);    //Print data
}
 
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) 
{
	if(root == NULL) 
	{
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left,data);
	}
	else 
	{
		root->right = Insert(root->right,data);
	}
	return root;
}

//To search an element in BST, returns true if element is found
bool Search(Node* root,int data) 
{
	if(root == NULL) 
	{
		return false;
	}
	else if(root->data == data) 
	{
		return true;
	}
	else if(data <= root->data) 
	{
		return Search(root->left,data);
	}
	else 
	{
		return Search(root->right,data);
	}
}

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
	return findMinimum(root->right);
}

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

//check if tree is bst
bool isValidBST(Node* root, long min = LONG_MIN, long max = LONG_MAX) 
{
    if (root == NULL) 
	{
		return true;
	}
    if (root->val <= min || root->val >= max)
	{		
		return false;
	}
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}
    
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

//Check if BST is symmetric
bool solve(Node * r1, Node * r2)
    {    
        if(r1 == NULL && r2 == NULL)
            return true; 
		
        else if(r1 == NULL || r2 == NULL || r1->val != r2->val)
            return false; 
        
        return solve(r1->left, r2->right) && solve(r1->right, r2->left);
    }
    
    bool isSymmetric(Node* root) 
    {
        return solve(root->left, root->right);     
    }

//Convert Sorted Array to Binary Search Tree:
Node* sortedArrayToBST(vector<int>& nums)
{

	return createBST(nums, 0, nums.size()-1); // (array, min, max)

}

Node* createBST(vector<int>& nums, int start, int end)
{
	if(start > end)
	{
		return nullptr;
	}
	int mid = (start + end)/2;
	Node* node = new Node(nums[mid]);
	node->left = createBST(nums, start, mid-1);
	node->right = createBST(nums, mid+1, end);
	return node;
}

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

int main() 
{
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);
	//level order traversal
	//bfs(root);
	// Deleting node with value 5, change this value to test other cases
	//root = Delete(root,5);
	
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true)
	{
		cout<<"Found\n";
	}
	else
	{
		cout<<"Not Found\n";
	}
	int min_val = findMinimum(root);
	cout<<"minimum value in tree "<<min_val<<endl;
	int max_val = findMaximum(root);
	cout<<"maximum value in tree "<<max_val<<endl;
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	int height = treeHeight(root);
	cout<<"tree height"<<height<<endl;
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"Postorder: ";
	Postorder(root);
	cout<<"\n";
}
