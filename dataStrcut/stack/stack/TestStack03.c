#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int Status;
typedef int SElemType;

typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;
/*
	ջ����ʽ�洢
	���⣺ ��ɾ���ڵ�ʱ free()�ͷ��ڴ����
*/
typedef struct{
	LinkStackPtr top; //ջ��ָ��
	int count;
}LinkStack;

Status Push_03(LinkStack *s, SElemType e);
int StackEmpty_03(LinkStack s);
Status Pop_03(LinkStack *s, SElemType *e);
int test03(){
	LinkStack s = {NULL,0};
	SElemType e;
	Push_03(&s, 10);
	Push_03(&s, 20);
	Push_03(&s, 30);

	Pop_03(&s, &e);
	LinkStackPtr t = s.top;
	while (t != NULL){
		printf("%d\n", t->data);

		t = t->next;
	}
	printf("%d\n", e);
	return 0;
}

Status Push_03(LinkStack *s, SElemType e){
	LinkStackPtr p = malloc(sizeof(LinkStackPtr));
	
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;

}

Status Pop_03(LinkStack *s, SElemType *e){
	if (!StackEmpty_03(*s))return ERROR;//ջΪ��

	*e = s->top->data;
	LinkStackPtr p;
	p = s->top;
	s->top = s->top->next;
	//free(p);
	s->count--;

	return OK;
}

int StackEmpty_03(LinkStack s){
	return s.count==0 ? 0:1;
}