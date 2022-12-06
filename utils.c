// utils.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int blockSize = 32;


double getAvg(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum/size;
}
//TODO
int cacheBlockSize(int n) {

  // size of cache block is size of the cache in bytes divided by the size of a block in bytes.

    for (int i = 1; i < 256; i = i * 2) {

        blockSize = i;

        // get both times to compare
        float cacheTime = cacheTimeAvg(n);
        float mainTime = mainTimeAvg(n)

        if (cacheTime < 0.0001) {
            return i;
            break;
        }
    }

return 0;

}
//TODO
int cacheSize() {

  struct timespec start, stop;
 	double accum;
 	int *arr;
  int i;

	int MAX_CACHE = 65536;

 	for (i = 1; i <= MAX_CACHE; i = i*2) {
 		arr = malloc(sizeof(int) * MB);
 		clock_gettime(CLOCK_MONOTONIC, &start);

 		for (int j = 0; j < (i * MB); j++){
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

  int *ptr;
	struct timespec start, stop;
	double elapsed;
  double mainTimes[TRIALS];


  for(int i = 0; i < TRIALS; i++){
		ptr = (int *) malloc((n)*sizeof(int));

		for(int j = 0; j < n; j++){
			ptr[j] = rand()%10000;
		}

		clock_gettime(CLOCK_MONOTONIC, &start);
		for(int k = 0; k < n; k++){
			ptr[k] += 1;
			}

		clock_gettime(CLOCK_MONOTONIC, &stop);
		free(ptr);

		elapsed = ( stop.tv_sec - start.tv_sec )
				+ ( stop.tv_nsec - start.tv_nsec);

		mainTimes[i] = elapsed;
		}
	}
  double mainAvg = getAvg(mainTimes, TRIALS);
	return(mainAvg); // returning the average time for all results

}

float cacheTimeAvg(int n) {

  int *ptr;
	struct timespec start, stop;
  int testArr[SIZE][SIZE];
  double cacheTimes[TRIALS]
	double elapsed;

  for(int t = 0; t < TRIALS; t++){
  ptr = (int *) malloc((n)*sizeof(int));

    for(int i = 0; i < n; i++){
      ptr[i] = rand()%1000;
    }

    for(int j = 0; j < 1000; j++){
      for(int k = 0; k < 1000; k++){
        testArr[j][k] = rand()%1000;
      }
  }
  int sum = 0;

  clock_gettime(CLOCK_MONOTONIC, &start);

  for(int i = 0; i < n; i++){

    int row = rand()%1000;
    int col = rand()%1000;

    sum += testArr[row][col]; //attempting to flood cache
    ptr[row] += 1;
  }
  clock_gettime(CLOCK_MONOTONIC, &stop);

  free(ptr);

  elapsed = ( stop.tv_sec - start.tv_sec )
      + ( stop.tv_nsec - start.tv_nsec);

  cacheTimes[t] = elapsed;
  }
}

double cacheAvg = getAvg(cacheTimes, TRIALS);
return(cacheAvg);
 }
}
