#include "stdio.h"

int main()
{
	int i;
	printf("整数占用%d个字节\n",sizeof(int));
	for(i=5;i<50000000;i*=10)
		printf("i=%d,i*i=%d\n",i,i*i);
	return 0;
}
