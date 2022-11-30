// main.c
#include <stdio.h>
#include "utils.h"


int main(int argc, char** argv)
 {
  int numTimesToAccess = 1000;

	printf("Calculating time to access main memory...\n");
	float mainTime = mainTimeAvg(numTimesToAccess);
	printf("Complete!\n");

	printf("Calculating time to access cache...\n");
	float cacheTime = cacheTimeAvg(numTimesToAccess);
	printf("Complete!\n");

	printf("Calculating cache size...\n");
	int cache_size = cacheSize();
	printf("Complete!\n\n");

	printf("Calculating cache block size...\n");
	int cache_block_size = cacheBlockSize(1);
	printf("Complete!\n\n");


	printf("Ignore all text above this line!\n");

	printf("Average time to access main memory is %f seconds\n", mainTime);
	printf("Average time to access cache is %f seconds\n", cacheTime);
	printf("Cache Size is: %d KB\n", cache_size);
	printf("Cache Block Size is: %d bytes\n\n", cache_block_size);

}
