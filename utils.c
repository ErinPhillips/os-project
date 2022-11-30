// utils.c

int cacheBlockSize() {

    for (int i = 1; i<256; i= i*2) {

        blockSize = i;
        
        // get both times to compare
        float cacheTime = getAvgTimeCache(n);
        
        if (cacheTime < 0.0001) {
            return i;
            break;
        }
    }
return 0;

}

int cacheSize() {
    struct timespec ts_begin, ts_end;
 	double elapsed1;
 	int *arr;

	int MAX_CACHE = 65536;

 	int j;

 	for (j = 1; j <= MAX_CACHE; j = j*2){

 		arr = malloc(sizeof(int) * (1024 * 1024));

 		clock_gettime(CLOCK_MONOTONIC, &ts_begin);
 		for (int i = 0; i < (j * 1024 * 1024); i++){
 			arr[0]++;
 		}
 		clock_gettime(CLOCK_MONOTONIC, &ts_end);
 		elapsed1 = ts_end.tv_sec - ts_begin.tv_sec;
 		elapsed1 += ((ts_end.tv_nsec - ts_begin.tv_nsec));

 		if (elapsed1 < 1000.0 && elapsed1 > 0.0){
 			break;
 		} 
 	}
 	return j;
    
}

float mainTimeAvg(int n) {
	struct timespec ts_begin, ts_end;
	double elapsed1;
	double totalElapsed = 0;
	
	z = 0;
	
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
	
	z = 0;
	

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