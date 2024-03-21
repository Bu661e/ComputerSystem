#include <stdio.h>
int i=8;
int k=6;
int main()
{
	//(1)地址与指针
	//(2)指针＋1
	//(3)数据的查看
	//(4)指针与数组
	int *pi;
	pi=&i;
	printf("%d,0x%x\n",*pi,pi);
	pi+=1;
	int arr[10];
	printf("%d,0x%x\n",*pi,pi);
	int j;
	j=i*19;
	return 0;
}
