#include <stdio.h>
#include <assert.h>
void exch(int arr[], int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}


void bubble_sort(int arr[],int n){
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				exch(arr,j,j+1);

			} 
		}
	}
}
void test_cases(){
        int arr[] = {4,2,1,5,3,10};
        int expected[] = {1,2,3,4,5,10};

        int n = sizeof(arr)/sizeof(arr[0]);

        bubble_sort(arr,n);

	//for(int i = 0; i < n; i++) printf("%d ",arr[i]);
        for(int i = 0; i < n; i++){
               assert(arr[i] == expected[i]);
        }
}

int main(){
        test_cases();
        return 0;
}

