#include <stdio.h>
void f(int m,int n)
{
	printf("第一个参数=%d,第二个参数=%d\n",m,n);
	return;
}
int main()
{
	int a=3;
	f(a,a++);
	return 0;
}
