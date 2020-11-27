#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define OK 1
#define ERROR 0
typedef int Status;
/*
	栈的基本顺序存储结构
*/
typedef int SElemType;
typedef struct{
	SElemType data[MAXSIZE];
	int top;  /*用于栈顶的指针（游标）*/
}SqStack;

int StackEmpty(SqStack s);
void InitStack(SqStack *s);
Status Push(SqStack *s, SElemType e);
Status Pop(SqStack *s, SElemType *e);
Status ClearStack(SqStack *s);
int StackLen(SqStack s);
Status GetElem(SqStack s,SElemType *e);
Status DestroyStack(SqStack *s);
int Test01(){
	SqStack s;
	InitStack(&s);
	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);
	//int i=0;
	//while (i<=s.top){
	//	printf("%d\n", s.data[i]);
	//	i++;
	//}

	SElemType e;

//	printf("%d\n", StackLen(s));

	//Pop(&s, &e);
//	ClearStack(&s);

	int i=s.top;
	while (i!=-1){
		printf("%d\n", s.data[i]);
		i--;
	}

	
	DestroyStack(&s);
	//GetElem(s, &e);
	//printf("%d\n",e);
	return 0;
}
Status DestroyStack(SqStack *s){
	free(s->data);
	return OK;
}
Status GetElem(SqStack s, SElemType *e){
	if (s.top == -1)return ERROR;

	*e = s.data[s.top];
	return OK;
}
int StackLen(SqStack s){
	return s.top + 1;
}
Status ClearStack(SqStack *s){
	if (s->top == -1)return OK;
	while (s->top != -1){
		s->data[s->top] = 0;
		s->top--;
	}
	return OK;
}
Status Push(SqStack *s, SElemType e){
	if (s->top == MAXSIZE - 1)return ERROR;/*栈满*/
	s->top++;
	s->data[s->top] = e;
	return OK;
}
Status Pop(SqStack *s, SElemType *e){
	if (s->top == -1)return ERROR;
	*e = s->data[s->top];
	s->top--;
	return OK;
}
int StackEmpty(SqStack s){
	
	if (s.top == -1)return 0;
	else return 1;

}
void InitStack(SqStack *s){
	s->top = -1;
}