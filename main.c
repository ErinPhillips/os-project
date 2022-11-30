// main.c

int main(int argc, char** argv)
{
    int numTimesToAccess = 1000;

	printf("Calculating time to access main memory...\n");
	float mainTime = getAvgTimeMain(numTimesToAccess);
	printf("Complete!\n");
	
	printf("Calculating time to access cache...\n");
	float cacheTime = getAvgTimeCache(numTimesToAccess);
	printf("Complete!\n");
	
	printf("Calculating cache size...\n");
	int cacheSize = getCacheSize();
	printf("Complete!\n\n");
	
	printf("Calculating cache block size...\n");
	int cacheBlockSize = getCacheBlockSize(1);
	printf("Complete!\n\n");


	printf("Ignore all text above this line!\n");

	printf("Average time to access main memory is %f seconds\n", mainTime);
	printf("Average time to access cache is %f seconds\n", cacheTime);
	printf("Cache Size is: %d KB\n", cacheSize);
	printf("Cache Block Size is: %d bytes\n\n", cacheBlockSize);

}
