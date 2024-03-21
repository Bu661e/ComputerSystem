#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, const char * argv[])
{
    FILE *infile, *outfile;
    int h, i;
    //printf("%s, %s\n", argv[1], argv[2]);
    if(strcmp(argv[1], "-n"))
    {
        if(!(infile = fopen(argv[1], "r")) || !(outfile = fopen(argv[2], "w+"))){
            printf("打开文件错误!\n");
            return 1;
        }
        while(fscanf(infile, "%x", &h) != EOF)
            fprintf(outfile, "%c", h);
    }
    else{
        if(!(infile = fopen(argv[2], "r")) || !(outfile = fopen(argv[3], "w+"))){
            printf("打开文件错误!\n");
            return 1;
        }
        for(i = 0; i < 5; i ++){
            while(fscanf(infile, "%x", &h) != EOF)
                fprintf(outfile, "%c", h);
            fprintf(outfile, "%c", '\n');
            rewind(infile);     //文件内部指针重新指向输入流开头
        }
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}
