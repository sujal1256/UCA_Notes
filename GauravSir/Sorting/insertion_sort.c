#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertion_sort(int arr[],int n){
	for(int i = 0; i < n; i++){
		
		int key = arr[i];
		int j = i - 1;
		
		while(j >=0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void test_sample(){

        int input[] = {5,2,1,4,3};
        int output[] = {1,2,3,4,5};
        int n = sizeof(input)/sizeof(input[0]);
	insertion_sort(input,n);

        for(int i = 0; i < n; i++) assert(input[i] == output[i]);
}


long long time_elapsed(int n){

	
  int *arr = (int *) malloc(n * sizeof(int));

  srand(time(NULL));
  for(int i = 0; i < n; i++) arr[i] = rand();

  struct timeval before;
  gettimeofday(&before, NULL);
  long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

  insertion_sort(arr, n);

  struct timeval after;
  gettimeofday(&after, NULL);
  long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

  return after_millis-before_millis;
}


int main()

{
        test_sample();

        long long t1 = time_elapsed(32000);
        long long t2 = time_elapsed(64000);

        printf("%lf",t2*1.0/t1);
        return 0;

}
   
