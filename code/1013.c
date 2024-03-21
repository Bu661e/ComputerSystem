#include <stdio.h>
int main()
{
	int i=1111;
	int *pi=&i;
	int **ppi=&pi;
	printf("变量i的值=%d,变量i的地址是=0x%X\n",i,&i);
	printf("指针pi中存放的值是＝0x%X，指针pi的地址是 ＝0x%X  \n",pi,&pi);
	printf("指向指针pi的指针ppi中存放的值是＝0x%X，指针ppi的地址是 ＝0x%X  \n",ppi,&ppi);
	
	short s=22;
	int *ps=&s;
	int **pps=&ps;
	
	printf("变量s的值=%d,变量s的地址是=0x%X\n",s,&s);
	printf("指针ps中存放的值是＝0x%X，指针ps的地址是 ＝0x%X  \n",ps,&ps);
	printf("指向指针ps的指针pps中存放的值是＝0x%X，指针pps的地址是 ＝0x%X  \n",pps,&pps);


return 0;
}

