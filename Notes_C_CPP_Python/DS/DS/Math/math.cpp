int MissingNumber(vector<int>& array, int n) 
{
    int sum = ((n * (n + 1)) / 2);
    for(int i = 0; i < n - 1; i++)
	{
            sum -= array[i];
    }
	return sum;
}

int trailingZeroes(int n) 
{
	int res = 0;
	int i = 5;
	while(n/i >0)
	{
		res = res + (n/i);
		i = i*5;
	}
	return res;
}