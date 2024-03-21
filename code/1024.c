#include <stdio.h>
int main()
{
	short s1=-6; //-32768~32767
	short s2=32763;
	unsigned short us1;	//0~65535
	unsigned short us2;		
	us1 = s1;
	printf("%hx,%hx,%hd,%hu\n",s1,us1,s1,us1);
	s1=6;
	printf("%hx+%hx\n",s1,s2);
	s1+=s2;
	us1=s1;
	printf("%hx,%hx,%hd,%hu\n",s1,us1,s1,us1);
	s1+=s1;
	us1+=us1;
	printf("%hx,%hx,%hd,%hu\n",s1,us1,s1,us1);
	return 0;
}
