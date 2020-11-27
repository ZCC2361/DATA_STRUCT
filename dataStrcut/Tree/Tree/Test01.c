#define MAX_TREE_SIZE 100

typedef int ElemType;
/*
	树的存储结构：双亲表示法
*/

//typedef struct PTNode{ /*结点结构*/
//	ElemType data; /*结点数据*/
//	int parent;  /*双亲的位置*/
//}PTNode;
//
//typedef struct
//{
//	PTNode nodes[MAX_TREE_SIZE]; /*结点数组*/
//	int r; /*根的位置*/
//	int n;/*结点数*/
//} PTree;
/*
	根据上述的存储结构，我们可以根据结点的parent很容易找到结点的双亲，时间复杂度为O（1）
	当parent为-1时，表示找到了树结点的跟，但是如果我们想知道结点的孩子，则要遍历整个结构
	为此我们可以改进一下上诉结构，增加一个最左边孩子的域，假设叫长子域，不存在为-1
	同样如果还想结点间的兄弟关系，可以增加一个右兄弟结点，没有则为-1；
*/

typedef struct PTNode{ /*结点结构*/
	ElemType data; /*结点数据*/
	int parent;  /*双亲的位置*/
	int firstchild; /*最左边孩子的位置*/
	int rightsib; /*右兄弟结点的位置*/

}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE]; /*结点数组*/
	int r; /*根的位置*/
	int n;/*结点数*/
} PTree;





