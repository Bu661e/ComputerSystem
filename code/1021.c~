#include<stdio.h>

int main(int argc, char **argv)
{
	int k;
	//数据类型
   	k=sizeof(int);//4
	k=sizeof(long double);//12,0xc
	//变量或常量
	char* s;
	k=sizeof(s);//4
	k=sizeof("hello");//6
	k=sizeof('h');//4
	//union
	union//2
	{
		short s;
		char c;
	}un,*pun;
	k=sizeof(un);//2
	k=sizeof(pun);//4
	//struct
	struct 
	{
		int i;//4 
		int j;//4 
	}sc,*psc;
	k=sizeof(sc);//8
	k=sizeof(psc);//4
	char a[10]="hello";
	k=sizeof(a);//4
   	printf("%d\n",k);
  
    return 0;
}
