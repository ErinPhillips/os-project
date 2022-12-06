// main.c
#include <stdio.h>
#include "utils.h"


int main(int argc, char** argv)
 {
  	int n = 1000;
	float mainTime = mainTimeAvg(n);
  	float cacheTime = cacheTimeAvg(n);
	//int cache_size = cacheSize();
	//int cache_block_size = cacheBlockSize(1);

	printf("Average time to access main memory is %f seconds\n", mainTime);
	printf("Average time to access cache is %f seconds\n", cacheTime);
	//printf("Cache Size is: .2%d KB\n", cache_size);
	//printf("Cache Block Size is: .2%d bytes\n\n", cache_block_size);

}
