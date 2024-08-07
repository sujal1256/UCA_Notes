#include <stdio.h>

int main(){
	int x = 123;
	int sign = 1;
	if(x < 0){
		sign = -1;
	}
	x = abs(x);
	int rev = 0;
	while(x>0){
		int rem = x%10;
		//if(rev*10 + rem > INT_MAX){
		if( rev > (INT_MAX - rem)/10){
			printf("%d",0);
			return 0;
		}
		rev = rev*10 + rem;
		x = x/10;
	}
	printf("%d",sign*rev);
	return 0;
}
