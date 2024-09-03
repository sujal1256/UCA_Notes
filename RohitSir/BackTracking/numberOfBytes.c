#include <stdio.h>
#include <stdlib.h>

void* callocCustom(int num_of_bytes){
    void *ptr = malloc(num_of_bytes);

    for(int i = 0; i < num_of_bytes; i++){
        char* currByte = (char*)(ptr) + i;
        *currByte = '\0';
    }
    return ptr;
}
int main(){
    int num = 100;
    char* arr = (char*) callocCustom(num);

    if(arr == NULL){
        printf("Not Working");
        return 0;
    }

    int success = 1;
    for(int i = 0; i < num; i++){
        if(arr[i] != 0){
            success = 0;
            break;
        }
    }

    if(success){
        printf("Test cases passed");
    }
    else{
        printf("Test cases not passes");
    }

    return 0;
}