#include <stdio.h>
static char* s1="Sorry,您可能是盗版用户的受害者!\n";
static char* s2="Welcome,欢迎进入系统!\n";
int main()
{
	int i;
	printf("请输入序列号：");
	scanf("%d",&i);
	if(i!=16)
	{
		printf("%s",s1);
		return 0;
	}
	printf("%s",s2);
	return 1;

}
