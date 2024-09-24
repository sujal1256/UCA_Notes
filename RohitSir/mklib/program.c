#include <stdio.h>
#include "calc1.h"
#include "calc2.h"


int main(){
	printf("Sum is 1 and 2 %d\n",add(1,2));
	printf("Subtraction is 1 and 2 %d \n",subs(1,2));
	printf("Multiplication is 1 and 2 %d \n",multiply(1,2));
	printf("Division of 10 and 2 %d \n",divide(10,2));
	printf("Modulus:%d \n",mod(10,4));
	printf("Maximum of 2 and 4 is %d \n",max(2,4));
	printf("Minimum if 2 and 4 is %d \n ",min(2,4));
	printf("Absolute Value %d \n",abs(2-3));
	return 0;
}
