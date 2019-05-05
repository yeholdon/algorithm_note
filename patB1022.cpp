#include "cstdio"
int main()
{
	int a, b, d, sum, ans[31], num = 0;
	scanf("%d%d%d", &a, &b, &d);
	sum = a+b;
	do{
		ans[num++] = sum%d;
		sum = sum/d;
	} while(sum!=0);
	
	for(int i = num-1; i>=0; i--)
	{
		printf("%d", ans[i]);
	}
	return 0;
}
	
