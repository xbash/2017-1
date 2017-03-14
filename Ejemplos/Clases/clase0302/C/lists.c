#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(int argc, char** argv)
{
	int size  = atoi(argv[1]);
  long sum;
	clock_t timer = clock();

	double* lines = calloc(size, sizeof(double));

	for(int i = 0; i < size; i++)
	{
		lines[i] = (((double)(rand()) / (double)(INT32_MAX)));
	}

	fprintf(stderr, "Arreglo generado en %lf segundos\n", ((double)(clock() - timer)/((double)CLOCKS_PER_SEC)));

	// printf("%d\n", size);
	timer = clock();
  sum = 0;
	for(int i = 0; i < size; i++)
	{
    sum += lines[i];
	}
  printf("sum %ld\n",sum);
	fprintf(stderr, "Suma calculada en %lf segundos\n", ((double)(clock() - timer)/((double)CLOCKS_PER_SEC)));

	free(lines);

	return 0;
}
