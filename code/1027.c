#include <stdio.h>
#include <math.h>
int main()
{
	float f1=0.25f*pow(2,-2);
	float f2=300000.0f*pow(2,10);
	float f3;
	f3=f1+f2;
	printf("%.30f\n",f3);
  	return 0;
}

