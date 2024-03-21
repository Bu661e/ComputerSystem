#include<stdio.h>


int main()
{
	// 	I miss HNU.\0
	
//	int k=5590600;//0x00554e48
	// 内存中：48 4e 55 00
	// H  N U \0
//	printf("%d\n",k);
//	printf("%s\n",&k);
	//I mi
	//49 20 6d 69
	int k=0x696d2049;
	//ss H
	//73 73 20 48
	int j=0x48207373;
	//NU.
	int l=0x002e554e;
//	printf("%x\n",k);
//	int arr[3];
//	printf("%s\n",arr);
	printf("%s\n",&k);
	return 0;
}
