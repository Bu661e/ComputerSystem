#include<stdio.h>


int main(int argc, char **argv)
{

    union {
        short  s;
        char   c;
    } un;
    un.s = 0x1234;
    un.c=0x56;
    un.s=1;
    if (un.c== 1 )
        printf("小端法\n");
    else
        printf("大端法\n");
    
    return 0;
}
