#include<stdio.h>
#include<stdlib.h>

int
main(int argc, char **argv)
{
    union {
        short  s;
        char   c[sizeof(short)];
    } un;

    un.s = 0x0102;
    if (sizeof(short) == 2) {
    if (un.c[0] == 1 && un.c[1] == 2)
        printf("大端法\n");
    else if (un.c[0] == 2 && un.c[1] == 1)
        printf("小端法\n");
    else
        printf("不能判断\n");
    } else
    printf("sizeof(short) = %d\n", sizeof(short));

    exit(0);
}
