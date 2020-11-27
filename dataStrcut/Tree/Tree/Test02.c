#define MAX_TREE_SIZE 100

typedef int ElemType;
/*
树的存储结构：孩子表示法
*/

/*多重链表表示法*/
//typedef struct PTNode{ /*结点结构*/
//	ElemType data; /*结点数据*/
//	
//	/*指向一颗子树的根结点的指针，个数为树的度，假设为3*/
//	struct PTNode* child1;
//	struct PTNode* child2;
//	struct PTNode* child3;
//}*PTNode;
//
//typedef struct
//{
//	PTNode head;
//	//int r; /*根的位置*/
//	int n;/*结点数*/
//} PTree;

/*
	上述方式，在对于树中各结点的度相差很大时，显然很浪费空间
	不过如果树的各结点的度相差很小时，那就意味着开辟的空间又都被重复利用了。
	如果要节约空间，我们可以增加一个位置，专门存放结点指针域的个数
*/
//typedef struct PTNode{ /*结点结构*/
//	ElemType data; /*结点数据*/
//	int degree ;
//	/*指向一颗子树的根结点的指针，个数为树的度，假设为3*/
//	//struct PTNode* child[degree];
//	//struct PTNode* child2;
//	//struct PTNode* child3;
//}*PTNode;
//
//typedef struct
//{
//	PTNode head;
//	//int r; /*根的位置*/
//	int n;/*结点数*/
//} PTree;

/*
	上述结构虽然解决了空间问题，但是各个结点间的链表是不同结构
	加上要维护结点度的值，在运算上，会带来时间的损耗
	而如果我们把每个结点放到一个数组中，每个结点的孩子不确定
	我们可以建立一个单链表来表示它 也就是我们的孩子表示法
*/
/*孩子表示法*/
typedef struct CTNode{ /*孩子结点结构*/
	int child;
	struct CTNode* next;
}*Childptr;

typedef struct /*表头结构*/
{
	ElemType data; 
	Childptr firstchild;
	/*双亲孩子表示法：即再增加一个双亲的位置*/
	int parent;
} CTbox;

typedef struct{
	CTbox nodes[MAX_TREE_SIZE];
	int r; /*根的位置*/
	int n;/*结点数*/
}CTree;

