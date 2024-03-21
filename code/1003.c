#include "stdio.h"

int main()
{
	char c=-128;
	char d=-c;
	printf("c=%d,d=%d\n",(int)c,(int)d);
	return 0;
}
