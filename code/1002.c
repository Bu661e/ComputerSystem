#include "stdio.h"

int main()
{
	int i;
	printf("浮点数占用%d个字节\n",sizeof(float));
	for(i=5;i<50000000;i*=10)
		printf("i=%f,i*i=%f\n",(float)i,(float)i*(float)i);
	return 0;
}
