#ifndef tree
#define tree

#define COUNT 10

typedef struct treeNode{
	int data;
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
}treeNode;

void instruksiPencetTree();
void inOrder (treeNode *root);
void preOrder (treeNode *root);
void postOrder (treeNode *root);
treeNode* createTreeNode(int data);
void insertNode (treeNode *root, int data);

void instruksiPencetTree(){
	printf("\nPencet 6 untuk add/insert node\n");
	printf("Pencet 7 untuk edit node\n");
	printf("Pencet 8 untuk delete node\n");
	printf("Pencet 9 untuk edit node\n");
	printf("Pencet 10 untuk menghentikan program\n");
}

void inOrder (treeNode *root){
	
	if(root == NULL) return;
	
	inOrder(root->leftPtr);
	printf("%3d", root->data);
	inOrder(root->rightPtr);
	
}

void preOrder (treeNode *root){
	if(root == NULL) return;
	
	printf("%3d", root->data);		
	inOrder(root->leftPtr);
	inOrder(root->rightPtr);
	
}

void postOrder (treeNode *root){
	if(root == NULL) return;
	
	inOrder(root->leftPtr);
	inOrder(root->rightPtr);
	printf("%3d", root->data);	
	
}

treeNode* createTreeNode(int data){
	
	treeNode* temp = (treeNode*) malloc (sizeof(treeNode*));
	
	if(!temp){
		printf("%d not inserted. No memory available.\n",data);
		return;
	}
	temp->data = data;
	
	temp->leftPtr  = NULL;
	temp->rightPtr = NULL;
	return temp;
	
}

void insertNode(treeNode *root, int data){
	if(root == NULL){
		root = createTreeNode(data);
		return;
	}
	
	if(data < root->data){
		insertNode(&(root->leftPtr),  data);
	}
	
	else if (data > root->data){
		insertNode(&(root->rightPtr), data);
	}
	
	else{
		printf("duplicate number\n");	
	}
	
}

void print2DUtil(treeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->rightPtr, space);
 
    // Print current node after space
    // count
    printf("\n");
    int i;
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->leftPtr, space);
}
 
// Wrapper over print2DUtil()
void print2D(treeNode *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
#endif
