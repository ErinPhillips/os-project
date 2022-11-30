// utils.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int blockSize = 32;

int cacheBlockSize(int n) {

    for (int i = 1; i < 256; i = i * 2) {

        blockSize = i;

        // get both times to compare
        float cacheTime = cacheTimeAvg(n);

        if (cacheTime < 0.0001) {
            return i;
            break;
        }
    }

return 0;

}

int cacheSize() {

  struct timespec start, stop;
 	double accum;
 	int *arr;
  int i;

	int MAX_CACHE = 65536;

 	for (i = 1; i <= MAX_CACHE; i = i*2) {
 		arr = malloc(sizeof(int) * (1024 * 1024));
 		clock_gettime(CLOCK_MONOTONIC, &start);

 		for (int j = 0; j < (i * 1024 * 1024); j++){
 			arr[0]++;
 		}

 		clock_gettime(CLOCK_MONOTONIC, &stop);

 		accum = ( stop.tv_sec - start.tv_sec )
          + ( stop.tv_nsec - start.tv_nsec);


 		if (accum < 1000.0 && accum > 0.0){
 			break;
 		}
 	}
 	return i;

}

float mainTimeAvg(int n) {
	struct timespec ts_begin, ts_end;
	double elapsed1;
	double totalElapsed = 0;

	int z = 0;

	for (int i = 0; i < n; i++){

		int arr[1024*1024];// * (1024 * 1024)); // turn size of int (bytes) to size of int (kilobyte) smaller number to larger number

		int arrSize = 1024 * 1024;// * (1024 * 1024);

		//populate array
		for (int x = 0; x < arrSize; x++){
			arr[x] = x;
		}

		//for main memory
		clock_gettime(CLOCK_MONOTONIC, &ts_begin);
		for (int j = 0; j < arrSize; j = j + blockSize){
			z += arr[j];
		}
		clock_gettime(CLOCK_MONOTONIC, &ts_end);

		elapsed1 = ts_end.tv_sec - ts_begin.tv_sec;
		elapsed1 += ((ts_end.tv_nsec - ts_begin.tv_nsec)/1000000000.0);
		totalElapsed = totalElapsed + elapsed1;

	}
	printf("IGNORE %d\n", z);
	return(totalElapsed/n); // returning the average time for all results

}

float cacheTimeAvg(int n) {

	struct timespec ts_begin, ts_end;
	double elapsed1;
	double totalElapsed = 0;

	int z = 0;


	for (int i = 0; i < n; i++){

		int arr[1024*1024];// * (1024 * 1024)); // turn size of int (bytes) to size of int (kilobyte) smaller number to larger number

		int arrSize = 1024 * 1024;// * (1024 * 1024);

		//populate array
		for (int x = 0; x < arrSize; x++){
			arr[x] = x+1;
		}

		// only check the same amount of time that we did for main memory
		arrSize = arrSize/blockSize;

		//for cache memory
		clock_gettime(CLOCK_MONOTONIC, &ts_begin);
		for (int j = 0; j < arrSize; j++){
			z += arr[0];
		}
		clock_gettime(CLOCK_MONOTONIC, &ts_end);


		elapsed1 = ts_end.tv_sec - ts_begin.tv_sec;
		elapsed1 += ((ts_end.tv_nsec - ts_begin.tv_nsec)/1000000000.0);
		totalElapsed = totalElapsed + elapsed1;

    }
}
