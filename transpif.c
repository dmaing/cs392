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

	if (argc != 4) {
		fprintf(stderr, "Error: Wrong number of command-line arguments.\n");
		return -1;
	}

	int height = atoi(argv[1]); // height of input matrix
	int width = atoi(argv[2]); // width of input matrix
	int block = atoi(argv[3]); // width of block


	float *input = (float *)malloc(height * width * sizeof(float));
	float *output = (float *)malloc(height * width * sizeof(float));

	for (int i = 0; i < (height * width); i++) {
		input[i] = rand();
	}


	gettimeofday(&t1, NULL);

	for (int i = 0; i < height; i += block) { // increment rows by block size
		for (int j = 0; j < width; j++) { // increment through columns
			for (int k = 0; (k < block) && (i + k < height); k++) { // checks edge case i + k < height
				output[j * height + i + k] = input[(i + k) * width + j];
			}
		}
	}

	gettimeofday(&t2, NULL);

	double sec = t2.tv_sec - t1.tv_sec;
	double microsec = t2.tv_usec - t1.tv_usec;



	/*for (int m = 0; m < (height * width); m++) {
		printf("%f ", input[m]);
		if ((m + 1) % width == 0) {
			printf("\n");
		}
	}

	printf("\n");

	for (int p = 0; p < (height * width); p++) {
		printf("%f ", output[p]);
		if ((p + 1) % height == 0) {
			printf("\n");
		}
	}
	*/
	
	
	
	printf("Transposition took %f seconds and %f microseconds.\n", sec, microsec);

	return 0;
}