#include "stdio.h"

int main()
{
	long long  i;
	printf("长整数占用%d个字节\n",sizeof(long long));
	for(i=5;i<50000000;i*=10)
		printf("i=%lld,i*i=%lld\n",i,i*i);
	return 0;
}
