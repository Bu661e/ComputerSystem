#include <stdio.h>
void main()
{
	int a;
	scanf("%d",&a);
	int b,c;
	c=0;
	for(b=a;b>0;b--)
	{
		c=c+b;
	}
	printf("%d\n",c);
}
