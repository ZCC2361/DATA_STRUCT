#define MAX_TREE_SIZE 100

typedef int ElemType;

/*�����ֵܱ�ʾ��*/

typedef struct CSNode{
	ElemType data; /*�������*/
	struct CSNode *firstchild;/*��һ�����ӵ�λ��*/
	struct CSNode *rightsib;/*��һ�����ӵ����ֵܵ�λ��*/
}CSNode ,*CSTree;