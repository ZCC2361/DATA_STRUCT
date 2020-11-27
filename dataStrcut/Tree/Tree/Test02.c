#define MAX_TREE_SIZE 100

typedef int ElemType;
/*
���Ĵ洢�ṹ�����ӱ�ʾ��
*/

/*���������ʾ��*/
//typedef struct PTNode{ /*���ṹ*/
//	ElemType data; /*�������*/
//	
//	/*ָ��һ�������ĸ�����ָ�룬����Ϊ���Ķȣ�����Ϊ3*/
//	struct PTNode* child1;
//	struct PTNode* child2;
//	struct PTNode* child3;
//}*PTNode;
//
//typedef struct
//{
//	PTNode head;
//	//int r; /*����λ��*/
//	int n;/*�����*/
//} PTree;

/*
	������ʽ���ڶ������и����Ķ����ܴ�ʱ����Ȼ���˷ѿռ�
	����������ĸ����Ķ�����Сʱ���Ǿ���ζ�ſ��ٵĿռ��ֶ����ظ������ˡ�
	���Ҫ��Լ�ռ䣬���ǿ�������һ��λ�ã�ר�Ŵ�Ž��ָ����ĸ���
*/
//typedef struct PTNode{ /*���ṹ*/
//	ElemType data; /*�������*/
//	int degree ;
//	/*ָ��һ�������ĸ�����ָ�룬����Ϊ���Ķȣ�����Ϊ3*/
//	//struct PTNode* child[degree];
//	//struct PTNode* child2;
//	//struct PTNode* child3;
//}*PTNode;
//
//typedef struct
//{
//	PTNode head;
//	//int r; /*����λ��*/
//	int n;/*�����*/
//} PTree;

/*
	�����ṹ��Ȼ����˿ռ����⣬���Ǹ�������������ǲ�ͬ�ṹ
	����Ҫά�����ȵ�ֵ���������ϣ������ʱ������
	��������ǰ�ÿ�����ŵ�һ�������У�ÿ�����ĺ��Ӳ�ȷ��
	���ǿ��Խ���һ������������ʾ�� Ҳ�������ǵĺ��ӱ�ʾ��
*/
/*���ӱ�ʾ��*/
typedef struct CTNode{ /*���ӽ��ṹ*/
	int child;
	struct CTNode* next;
}*Childptr;

typedef struct /*��ͷ�ṹ*/
{
	ElemType data; 
	Childptr firstchild;
	/*˫�׺��ӱ�ʾ������������һ��˫�׵�λ��*/
	int parent;
} CTbox;

typedef struct{
	CTbox nodes[MAX_TREE_SIZE];
	int r; /*����λ��*/
	int n;/*�����*/
}CTree;

