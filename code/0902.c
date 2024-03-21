#include <stdio.h>
void f1(int n)
{
	printf("%d\n",n);
	return;
}
void f2(int n)
{
	if(n<=0) return ;
	printf("%d\n",n);
	f2(n-1);
}
int main()
{
	int i,k=300000;
//	for(i=k;i>=1;i--)
//		f1(i);
	f2(k);
}
