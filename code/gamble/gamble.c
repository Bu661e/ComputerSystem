/*
使用如下命令进行编译
gcc -c readfile.c -o 1.o
gcc -c random.c -o 2.o
gcc -c showmessage.c -o 3.o
gcc -c writefile.c -o 4.o
gcc -c gamble.c -o 5.o
gcc -o 2016 1.o 2.o 3.o 4.o 5.o

使用objdump -d 2016查看 


*/

#include <stdio.h>

int main()
{
	int i=readfile();	//获取点数，readfile.c
	printf("您还有%d点!\n",i);
	int r=randomint();	//生成一个大于0小于等于10的整数， random.c
	int k;
	printf("请输入您的幸运数字!\n");
	scanf("%d",&k);
//	showmessage();		//显示一条提示信息,showmessage.c
	if(k==r)
	{
		printf("恭喜！增加8点!");
		i=i+8;
	}
	else
	{
		printf("Sorry，你答错了，幸运数字是%d,扣除2点!",r);
		i=i-2;
	}
	printf("您还有%d点!\n",i);
	writefile(i);		//将点数写回，writefile.c
	//printf("%d\n",r);
	return 0;
}
