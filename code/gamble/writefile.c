#include <stdio.h>
#include <stdlib.h>

int writefile(int i)
{
        
        FILE *fp;
        if ((fp = fopen("balance.txt","w")) == NULL)
        {
                printf("open file failed!\n");
                exit(1);
        }
        fprintf(fp,"%d\n", i);
        fclose(fp);

        return 0;
}
