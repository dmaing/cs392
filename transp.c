#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {

	srand(time(NULL));
	struct timeval t1; // for timing
	struct timeval t2; // for timing

	if (argc != 3) {
		fprintf(stderr, "Error: Wrong number of command line arguments.\n");
		return -1;
	}

	int width = atoi(argv[1]); // width of input matrix
	int block = atoi(argv[2]); // width of block

	float *input = (float *)malloc(width * width * sizeof(float));
	float *output = (float *)malloc(width * width * sizeof(float));


	for (int i = 0; i < (width * width); i++) { // insert random values into input matrix
		input[i] = rand() % 100;
	}

	gettimeofday(&t1, NULL);

	/*for (int j = 0; j < width; j++) {
		for (int k = 0; k < width; k++) {
			output[j * width + k] = input[k * width + j];
		}
	}
	*/
	

	for (int i = 0; i < width; i+= block) {
		for (int j = 0; j < width; j+= block) {
			for (int k = i; k < i + block; k++) {
				for (int l = j; l < j + block; l++) {
					output[k * width + l] = input[l * width + k];
				}
			}
		}
	}
	


	gettimeofday(&t2, NULL);

	double sec = t2.tv_sec - t1.tv_sec;
	double ms = t2.tv_usec - t1.tv_usec;




	/*for (int m = 0; m < (width * width); m++) {
		printf("%f ", input[m]);
		if ((m + 1) % width == 0) {
			printf("\n");
		}
	}

	printf("\n");



	for (int p = 0; p < (width * width); p++) {
		printf("%f ", output[p]);
		if ((p + 1) % width == 0) {
			printf("\n");
		}
	}
	*/
	

	printf("Transposition took %f seconds and %f microseconds.\n", sec, ms);

	return 0;
}