#include <stdio.h>

int add(int a,int b){
	return a + b;
}

int subtract(int a,int b){
	return a-b;
}
int multiply(int a,int b){
	return a*b;

}

int divide(int a,int b){
	if(b==0){
		printf("Division by Zero");
		return -1;
	}
	return a/b;
}
int main(){
	int (*func)(int,int);
	func = add;
	printf("%d\n",func(2,3));
	func = subtract;
	printf("%d\n",func(2,3));
	func = multiply;
	printf("%d\n",func(2,3));
	func = divide;
	printf("%d\n",func(2,3));
}
