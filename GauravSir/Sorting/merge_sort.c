#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void exch(int arr[], int i, int j){

	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void merge(int arr[], int aux[], int left, int mid, int right){

	for(int k = left; k <= right; k++) aux[k] = arr[k];

	int i = left;
	int j = mid + 1;

	// First 2 conditions have saved us from next 2 while loops
	for(int k = left; k <= right; k++){
		if(i > mid) arr[k] = aux[j++];
		else if(j > right) arr[k] = aux[i++];
		else if(aux[i] < aux[j]) arr[k] = aux[i++];
		else arr[k] = arr[j++];
	}
}

void merge_sort_recursive(int arr[], int aux[], int left, int right){
	
	if(left >= right) return;
	int mid = (left + right)/2;
	merge_sort_recursive(arr, aux, left, mid);
	merge_sort_recursive(arr, aux, mid + 1, right);

	merge(arr, aux, left, mid, right);
}

void merge_sort(int arr[], int n){
	
	int *aux = (int*)malloc(n*sizeof(int));
	merge_sort_recursive(arr, aux, 0, n-1);
	free(aux);
}

void test_sample(){
	
	int input[] = {5,2,1,4,3};
	int output[] = {1,2,3,4,5};
	int n = sizeof(input)/sizeof(input[0]);
	merge_sort(input,n);

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

  merge_sort(arr, n);

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
