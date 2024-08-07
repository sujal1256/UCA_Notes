#include <stdio.h>

int main(){
	int a = 130;
	int *b = &a;
	char *c = &a;
       printf("%d %d",*b,*c);
}
