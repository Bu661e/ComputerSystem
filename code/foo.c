#include <stdio.h>
void foo()
{
	int a,*p;
	
	p=(int*)((int)&a+8);
	//p=(void*)((long)&a+16);
	*p+=12;//*p+=20
	
}

