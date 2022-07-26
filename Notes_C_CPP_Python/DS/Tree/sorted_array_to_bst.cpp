/*
Given an integer array nums where the elements are sorted in ascending order, 
convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two 
subtrees of every node never differs by more than one.
*/


//Convert Sorted Array to Binary Search Tree:
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	int n = nums.size();
   
	return TreeCreator(nums, 0, n-1);
	
}
TreeNode* TreeCreator(vector<int>& nums ,int low, int n){
	if(low>n){
		return NULL;
	}
	int mid = (n+low)/2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = TreeCreator(nums, low, mid-1);
	root->right = TreeCreator(nums, mid+1, n);
	return root;
}
