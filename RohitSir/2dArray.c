#include <stdio.h>


int main(){
	int arr[3][2] = {{1,2},{5,6},{3,4}};
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			printf("%d ",arr[j][i]);
		}
		printf("\n");
	}

	// Linear Access
	for (int i = 0; i < 6; i++)
	{
		printf(" %d",*(arr+i));
	}
	return 0;
}
