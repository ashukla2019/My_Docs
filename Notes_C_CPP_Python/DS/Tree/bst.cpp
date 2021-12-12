/*Binary search tress is non linear data structure, which can have atmost 2 children.

	            5   ----> root
			   / \
			  3   10 ---> children of root(5). 3 and 10 are sibling
			 / \   \
			1   4   11 ----> 1, 4 are children of 3 and 11 is children of 10. 1,4 and 11 are leaf node.

depth of node: path from root to that node. ex: depth of(3, 10) = 1
depth of(1, 4, 11) = 2

height of node: path from that node to longest leaf node.
height of 5 = 2
*/

#include<iostream>
#include<queue>

using namespace std;
class Node 
{
	public:
	int data;
	struct Node *left;
	struct Node *right;
};
//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct Node* Delete(struct Node *root, int data) 
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
 
 bool isBinarySearchtree(Node* root)
 {
 	
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
	bfs(root);
	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);
	
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
	cout<<"\n";
}
