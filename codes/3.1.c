#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void variables(char *str, int len)
{
int i,j;
double temp,value;
FILE *fp;

fp = fopen(str,"w");
for (i = 0; i < len; i++)
{	
	temp = (double)rand()/RAND_MAX;
	value=-2*log(1-temp);
	fprintf(fp,"%lf\n",value);
}
fclose(fp);
}


int  main(void)
{

//random numbers
variables("rnd.dat", 1000000);

return 0;
}
