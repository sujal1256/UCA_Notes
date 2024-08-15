#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// here we are taking pivot as the leftmost element but we can take any element
void exch(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void quick_sort_recursive(int arr[],int left,int right){
	if(left >= right) return;

	int pivot = arr[left];
	int i = left + 1;
	
	for(int j = left + 1; j <= right; j++){
		if(arr[j] < pivot){
			exch(arr,i,j);
			i++;
		}
	}
	exch(arr,left,--i);
	quick_sort_recursive(arr,left,i-1);
	quick_sort_recursive(arr,i+1,right);
}
void quick_sort(int arr[],int n){
	quick_sort_recursive(arr,0,n-1);
	
}
void test_sample(){

        int input[] = {5,2,1,4,3};
        int output[] = {1,2,3,4,5};
        int n = sizeof(input)/sizeof(input[0]);
        quick_sort(input,n);

        for(int i = 0; i < n; i++) assert(input[i] == output[i]);
}

long long time_elapsed(int n)
{
  int *arr = (int *) malloc(n * sizeof(int));

  srand(time(NULL));
  for(int i = 0; i < n; i++) arr[i] = rand();

  struct timeval before;
  gettimeofday(&before, NULL);
  long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

  quick_sort(arr,n);

  struct timeval after;
  gettimeofday(&after, NULL);
  long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

  return after_millis-before_millis;
}

long long time_elapsed_worstcase(int n)
{
  int *arr = (int *) malloc(n * sizeof(int));

  srand(time(NULL));
  for(int i = n - 1; i>= 0 ; i--) arr[i] = i;

  struct timeval before;
  gettimeofday(&before, NULL);
  long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

  quick_sort(arr,n);

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

	printf("%lf\n",t2*1.0/t1);
        // printf("%lld\n",t2);
	// printf("%lld\n",t1);
	
	long long t3 = time_elapsed_worstcase(32000);
	long long t4 = time_elapsed_worstcase(64000);
	printf("%lf\n",t4*1.0/t3);
	return 0;

}
