#include <stdio.h>
int desc(int a,int b){
        return b - a;

}
int asc(int a,int b){
	return a - b; 
}

void print(int arr[],int size){
        for(int i = 0; i < size; i++){
                printf("%d ",arr[i]);
        }
        printf("\n");
}

void sort(int arr[],int size,int (*comp)(int,int)){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(comp(arr[j],arr[j + 1]) > 0){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

}

int main(){
	int arr[] = {6,4,2,6,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Original Array\n");
	print(arr,n);

	printf("Ascending Array\n");
	sort(arr,n,asc);
	print(arr,n);

	printf("Descending Array\n");
	sort(arr,n,desc);
	print(arr,n);
	return 0;
}
