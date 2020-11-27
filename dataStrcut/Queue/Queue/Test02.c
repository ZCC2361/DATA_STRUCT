#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElmeType;

typedef struct Node{
	/*结点结构*/
	QElmeType data;
	struct Node *next;
}QNode,*Queueptr;

typedef struct{
	Queueptr front, rear;
}LinkQueue;

Status EnQueue_02(LinkQueue *q, QElmeType e);
Status DeQueue_02(LinkQueue *q, QElmeType *e);
int main(){
	QNode head = { .next = NULL };
	LinkQueue q = { &head, &head };
	EnQueue_02(&q, 10);
	EnQueue_02(&q, 20);
	EnQueue_02(&q, 30);
	EnQueue_02(&q, 40);

	QElmeType e;
	Queueptr t = q.front->next;

	while (t){
		printf("%d\n", t->data);
		t = t->next;
	}

	DeQueue_02(&q, &e);
	printf("%d\n", e);

	return 0;
}
Status EnQueue_02(LinkQueue *q, QElmeType e){
	Queueptr s = malloc(sizeof(Queueptr));
	if (!s) exit(0);
	s->data = e;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
	return OK;
}
Status DeQueue_02(LinkQueue *q, QElmeType *e){
	Queueptr p;
	if (q->front == q->rear)
		return ERROR;	
	p= q->front->next;
	*e = p->data;
	q->front->next = p->next;

	if (p == q->rear)	q->rear = q->front;
	//free(p);
	return OK;
}