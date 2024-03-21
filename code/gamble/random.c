#include <stdio.h>
#include <stdlib.h>
int randomint()
{
 	int i;
	srand( (unsigned int)time(0) );
    	i=rand();
	i=i%10+1;
	return i;
}
