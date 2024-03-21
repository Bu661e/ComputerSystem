/*
由于GCC编译时会打开缓冲区溢出保护，因此需要使用如下命令编译：

gcc -fno-stack-protector -z execstack -o a.out testoverflow.c
 

使用objdump -d a.out来查看返回地址，并修改outputs函数中参数的最后四个字节内容
*/
#include <stdio.h>
#include "string.h"

void outputs(char *str)
{
	char buffer[16];
	strcpy(buffer,str);//str to buffer
	printf("%s \n",buffer);
}

void hacker(void)
{
	printf("being hacked\n");
}

int main(int argc,char *argv[])
{
	char * str;	
	scanf("%s",str);
	outputs(str);
//	outputs("1234567123456712345671234567\x72\x84\x04\x08");
	return 0;
}

