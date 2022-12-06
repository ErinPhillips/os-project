// utils.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


double getAvg(double *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum/size;
}

double min(double arr[], int arrLen){
	int i;
	double min = 1.000;
	for(i = 0; i<arrLen;i++){
		if(min>arr[i]){
			min = arr[i];
		}
	}
	return min;
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

		elapsed = ( stop.tv_sec - start.tv_sec );
		elapsed += ((stop.tv_nsec - start.tv_nsec)/10.0);

		mainTimes[i] = elapsed;
	}
		printf("Minimum time to access main memory: %f\n", min(mainTimes, TRIALS));
		
		double mainAvg = getAvg(mainTimes, TRIALS);
		return(mainAvg); // returning the average time for all results
}

float cacheTimeAvg(int n) {

	int *ptr;
	struct timespec start, stop;
	int testArr[SIZE][SIZE];
	double cacheTimes[TRIALS];
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

	  	elapsed = ( stop.tv_sec - start.tv_sec );
		elapsed += ((stop.tv_nsec - start.tv_nsec)/10.0);

	  	cacheTimes[t] = elapsed;
 	}
	
	printf("Minimum time to access main memory: %f\n", min(cacheTimes, TRIALS));
	double cacheAvg = getAvg(cacheTimes, TRIALS);
	return(cacheAvg);
 }

