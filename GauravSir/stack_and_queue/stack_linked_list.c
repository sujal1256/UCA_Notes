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
int N = 0;

// New Element will be inserted at the start of linked list.
void push(int d){
	Node* old_head = head;
	head = (Node *)malloc(sizeof(Node));
	
	head->data = d;
	head->next = old_head;
	N++;
}

// Head element will be popped out of the stack and head will point to next pointer of previous head
int pop(){
	if(head == NULL){
		return INT_MIN;
	}
	Node* temp = head;
	int d = temp->data;

	head = head->next;
	free(temp);
	N--;
	return d;
}

bool isEmpty(){
	// return N==0 also works here.
	return head == NULL;
}

int size(){
	return N;
}

// Recently added element is at head.
int top(){
	if(head == NULL){
		return INT_MIN;
	}
	return head->data;
}

void test_samples(){
	push(3);
	push(10);
	push(11);
	
	assert(pop() == 11);
	assert(size() == 2);
	assert(top() == 10);
	assert(size() == 2);
	assert(pop() == 10);
	assert(size() == 1);
}
int main(){
	test_samples();
	return 0;
}
