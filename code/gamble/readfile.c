#include <stdio.h>
#include <stdlib.h>

int readfile()
{
        int i;
        
        FILE *fp;
        if ((fp = fopen("balance.txt","r")) == NULL)
        {
                printf("open file failed!\n");
                exit(1);
        }
        fscanf(fp,"%d\n", &i);
  //      printf("%d  ",i);
  //      printf("\n");
        fclose(fp);

        return i;
}
