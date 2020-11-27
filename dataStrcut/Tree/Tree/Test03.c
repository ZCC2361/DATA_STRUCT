#define MAX_TREE_SIZE 100

typedef int ElemType;

/*孩子兄弟表示法*/

typedef struct CSNode{
	ElemType data; /*结点数据*/
	struct CSNode *firstchild;/*第一个孩子的位置*/
	struct CSNode *rightsib;/*第一个孩子的右兄弟的位置*/
}CSNode ,*CSTree;