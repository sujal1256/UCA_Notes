#include <stdio.h>

int main() {
    int num = 42;
    double pi = 3.14159;
    char str[] = "Hello, stdout!";
    FILE* fd = fopen("output.txt", "w");

    fprintf(fd, "Integer: %d\n", num);
    fprintf(fd, "Floating-point: %f\n", pi);
    fprintf(fd, "String: %s\n", str);

    return 0;
}
