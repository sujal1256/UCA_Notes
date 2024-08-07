#include <stdio.h>

int find_peak(int arr[], int s, int e){
	int mid = (s + e)/2;
	while(s<=e){
		if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
			return mid;
		}	
		else if(arr[mid - 1] > arr[mid]){
			e = mid;
		}
		else if(arr[mid + 1] > arr[mid]){
			s = mid + 1;
		}
	}
	return -1;
	
}
int main(){
	//int arr[] = {0,1,0};
	//int arr[] = {0,2,1,0};
	int arr[] = {0,1,5,4,3};
	int ans = find_peak(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	printf("%d\n",ans);	
}
