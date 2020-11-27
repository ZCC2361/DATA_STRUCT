#define MAX_TREE_SIZE 100

typedef int ElemType;
/*
	���Ĵ洢�ṹ��˫�ױ�ʾ��
*/

//typedef struct PTNode{ /*���ṹ*/
//	ElemType data; /*�������*/
//	int parent;  /*˫�׵�λ��*/
//}PTNode;
//
//typedef struct
//{
//	PTNode nodes[MAX_TREE_SIZE]; /*�������*/
//	int r; /*����λ��*/
//	int n;/*�����*/
//} PTree;
/*
	���������Ĵ洢�ṹ�����ǿ��Ը��ݽ���parent�������ҵ�����˫�ף�ʱ�临�Ӷ�ΪO��1��
	��parentΪ-1ʱ����ʾ�ҵ��������ĸ����������������֪�����ĺ��ӣ���Ҫ���������ṹ
	Ϊ�����ǿ��ԸĽ�һ�����߽ṹ������һ������ߺ��ӵ��򣬼���г����򣬲�����Ϊ-1
	ͬ��������������ֵܹ�ϵ����������һ�����ֵܽ�㣬û����Ϊ-1��
*/

typedef struct PTNode{ /*���ṹ*/
	ElemType data; /*�������*/
	int parent;  /*˫�׵�λ��*/
	int firstchild; /*����ߺ��ӵ�λ��*/
	int rightsib; /*���ֵܽ���λ��*/

}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE]; /*�������*/
	int r; /*����λ��*/
	int n;/*�����*/
} PTree;





