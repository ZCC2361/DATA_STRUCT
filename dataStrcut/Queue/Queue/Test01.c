#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElmeType;
typedef struct{
	QElmeType data[MAXSIZE];
	int front; /*头指针*/
	int rear; /*队尾指针，若队列不为空，则执行队尾元素的下一位置*/
}SqQueue;
/*
	循环队列的实现
	
*/
void InitQueue(SqQueue *q);
Status EnQueue(SqQueue *q, QElmeType e);
Status DeQueue(SqQueue *q, QElmeType *e);
int QueueLength(SqQueue q);
int test01(){
	SqQueue q;
	InitQueue(&q);
	printf("%d\n", QueueLength(q));
	EnQueue(&q, 10);
	EnQueue(&q, 20);
	EnQueue(&q, 30);
	EnQueue(&q, 40);
	printf("%d\n", QueueLength(q));
	QElmeType e;
	DeQueue(&q, &e);
	printf("%d\n", e);
	DeQueue(&q, &e);
	printf("%d\n", e);

	EnQueue(&q, 50);
	printf("#%d	%d\n", q.front, q.rear);

	int i = q.front;
	while (i != q.rear){
		printf("%d\n", q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	
	return 0;
}
void InitQueue(SqQueue *q){

	q->front = 0;
	q->rear = 0;
}

Status EnQueue(SqQueue *q, QElmeType e){
	if ((q->rear+1)%MAXSIZE==q->front)return ERROR;
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *q, QElmeType *e){
	if (q->rear == q->front)return ERROR;
	*e = q->data[q->front];
	
	q->front = (q->front + 1) % MAXSIZE;
	return OK;
}
int QueueLength(SqQueue q){
	return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}