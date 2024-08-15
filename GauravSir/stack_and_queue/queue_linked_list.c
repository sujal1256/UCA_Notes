#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
struct Node{
	int data;
	struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;
Node* tail = NULL;
int N = 0;

// Recently added element is kept at the end of linked List
void push(int item){

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = tail->next;
	}

	N++;
}
int pop(){
	if(N==0){
		return INT_MIN;
	}
	Node* delete = head;
	head = head->next;
	int data = delete->data;
	free(delete);
	N--;
	return data;
}
bool isEmpty(){
	return N==0;
}

int size(){
	return N;
}

int front(){
	if(N == 0){
		return INT_MIN;
	}
	return head->data;
}

void test_samples(){
        push(3);
        push(10);
        push(11);
	
	printf("%d\n",N);
        assert(pop() == 3);
        assert(size() == 2);
        assert(pop() == 10);
        assert(size() == 1);
     	assert(front() == 11);
	assert(pop() == 11);
        assert(size() == 0);
	assert(pop() == INT_MIN);
	assert(front() == INT_MIN);
}
int main(){
        test_samples();
	printf("All testcases passes");
        return 0;
}
