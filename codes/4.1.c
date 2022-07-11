#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000000

int main() {
	FILE *fp = fopen("t.dat", "w");
	if (!fp) {
		printf("Couldn't open file\n");
		return 1;
	}
	for (int i = 0; i < NUM; i++) {
		double u1 = (double)rand()/RAND_MAX;
		double u2 = (double)rand()/RAND_MAX;
		fprintf(fp, "%lf\n", u1 + u2);
	}
	fclose(fp);
	return 0;	
}
