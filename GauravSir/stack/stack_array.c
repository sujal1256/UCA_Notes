#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
int* arr = NULL;
int N = 0;
int max_size = 1;

int size(){
	return N;
}

bool isEmpty(){
	return N==0;
}

void resize(int new_size){
	int* new_arr = (int *)malloc(new_size*sizeof(int));
	for(int i = 0; i < N; i++){
		new_arr[i] = arr[i];
	}

	free(arr);
	arr  = new_arr;
	max_size = new_size;
}

void push(int item){
	if(arr == NULL){
		arr = (int*)malloc(sizeof(int)*max_size);
	}
	else if(N == max_size){
		resize(2*max_size);
		max_size = 2*max_size;	
	}

	arr[N] = item;
	N++;	
}

int pop(){
	if(N == 0) return INT_MIN;

	int data = arr[N-1];
	N--;
	if(N>0 && N == max_size/4){
		resize(max_size/2);
		max_size /= 2;
	}
	return data;
}

int top(){
	return arr[N-1];
}
void test_samples(){
        push(3);
        push(10);
        push(11);

	assert(size() == 3);
        assert(pop() == 11);
        assert(size() == 2);
        assert(top() == 10);
        assert(size() == 2);
        assert(pop() == 10);
        assert(size() == 1);
}
int main(){
        test_samples();
	printf("All tests passed.\n");
	return 0;

}
