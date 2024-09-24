#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}
int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b)
{
	if (b == 0)
	{
		printf("Division by Zero");
		return -1;
	}
	return a / b;
}

void operate(int (*operation)(int, int), int x, int y)
{
	printf("%d\n", operation(2, 3));
}

int main()
{
	operate(add, 2, 3);
	operate(subtract, 2, 3);
	operate(multiply, 2, 3);
	operate(divide, 2, 3);

	return 0;
}
