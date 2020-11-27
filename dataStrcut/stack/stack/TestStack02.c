#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int Status;
typedef int SElemType;

typedef struct{
	SElemType data[MAXSIZE];
	int top1; /*栈1栈顶指针*/
	int top2; /*栈2栈顶指针*/
}SqDoubleStack;
/*
	两栈共享空间
	用一个数组存放两个栈
	
*/
void InitStack_2(SqDoubleStack *s);
Status Push_2(SqDoubleStack *s, SElemType e, int stackNumber);
Status Pop_2(SqDoubleStack *s, SElemType *e, int stackNumber);
int test02(){
	SqDoubleStack *s = malloc(sizeof(SqDoubleStack));;
	InitStack_2(s);
	Push_2(s, 10, 1);
	Push_2(s, 20, 1);
	Push_2(s, 30, 1);

	Push_2(s, 60, 2);
	Push_2(s, 50, 2);
	Push_2(s, 40, 2);

	/*int t1 = s->top1, t2 = s->top2;
	while (t1 != -1){
		printf("%d\n", s->data[t1--]);
	}

	while (t2 != MAXSIZE){
		printf("%d\n", s->data[t2++]);
	}*/
	SElemType e;
	Pop_2(s, &e, 1);
	printf("%d\n",e);


	return 0;
}
void InitStack_2(SqDoubleStack *s){
	s->top1 = -1;
	s->top2 = MAXSIZE;
}

Status Push_2(SqDoubleStack *s, SElemType e, int stackNumber){
	if (s->top1 + 1 == s->top2) return ERROR;/*栈满*/
	if (stackNumber == 1){
		s->data[++s->top1] = e;
	}else if (stackNumber == 2){
		s->data[--s->top2] = e;
	}
	return OK;

}

Status Pop_2(SqDoubleStack *s, SElemType *e, int stackNumber){
	if (stackNumber==1){
		if (s->top1 == -1)return ERROR;
		*e = s->data[s->top1--];
	}
	else if (stackNumber == 2){
		if (s->top2 == MAXSIZE)return ERROR;
		*e = s->data[s->top2++];
	}
	return OK;
}