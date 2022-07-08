//Fibnoci series: 0,1,1,2,3,5,8,13,21.... T(n) = O(n)
int fib(int n)
{
	if(n<=1)
		return n;
	int result;
	int prev1 =0, prev2 =1;
	for(int i=2;i<=n;++i)
	{
		result = prev1+prev2;
		prev1 = prev2;
		prev2 = result;
	}
	return result;
}
