#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int rare = -1;
int front = -1;
int* arr;
int max_size = 1;

resize(max_size);

int resize(int new_size){
	int *new_arr = (int)malloc(sizeof(int)*new_size);
	int k = 0;
	for(int i = 0; i < N; i++){
		new_arr[i] = arr[i];
	}
	max_size = new_size;
	free(arr);
	arr = new_arr;
}
void push(int item){
	if(front == -1){
		front = 0;
		rear == 0;
	}
	arr[rear++] = item;
	if(rear - front == max_size){
		resize((rear-front)*2);
	}

}
int pop(){
	int item = arr[N];
	N--;
	if(N == max_size/4){
		resize(max_size/2);
	}	
	return item;
}

void test_samples(){
        push(3);
        push(10);
        push(11);

        printf("%d\n",N);
        assert(pop() == 3);
        assert(size() == 2);
        assert(pop() == 10);
        assert(size() == 1);
        assert(front() == 11);
        assert(pop() == 11);
        assert(size() == 0);
        assert(pop() == INT_MIN);
        assert(front() == INT_MIN);
}
int main(){
        test_samples();
        printf("All testcases passes");
        return 0;
}  
