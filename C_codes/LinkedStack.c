/* 链式栈 
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
	int data;
	struct Node *next;
} *LNode;

LNode initStack(){
	LNode l = (LNode)malloc(sizeof(struct Node));
	l->next = NULL;
	return l;
}

int isEmpty(LNode L){
	return L->next==NULL?1:0;
}

void clear(LNode L){
	L->next = NULL;
}

void printAll(LNode L){
	LNode p = L->next;
	while(p){
		printf("%d\t", p->data);
		p =p->next;
	}
}

void push(LNode L, int e){
	LNode l = (LNode)malloc(sizeof(struct Node));
	l->data = e;
	l->next = L->next;
	L->next = l;
}

void pop(LNode L, int* e){
	if (isEmpty(L)){
		printf("The stack is empty already");
		return;
	}
	*e = L->next->data;
	LNode p = L->next;
	L->next = L->next->next;
	free(p);
}

void getTop(LNode L, int* e){
	if (isEmpty(L)){
		printf("The stack is empty already");
		return;
	}
	*e = L->next->data;
}

int main(){
	int n;
	int m;
	scanf("%d", &n);
	LNode l1 = initStack();
	while(n!=-1){
		push(l1, n);
		scanf("%d", &n);
	}
	printAll(l1);
	printf("\n");
	while(!isEmpty(l1)){
		pop(l1, &m);
		printf("%d\t", m);
	}
	return 0;
}
