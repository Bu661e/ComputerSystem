#include <stdio.h>

void foo()
{
	int a;
	static int *p;
	p=(int*)((int)&a+8);
	*p+=12;
}
int main()
{
	foo();
	printf("Print 1\n");
	printf("Print 2\n");
	printf("Print 3\n");
	printf("Print 4\n");
	return 0;
}
