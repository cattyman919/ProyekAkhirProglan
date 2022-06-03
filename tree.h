#ifndef tree
#define tree

#define COUNT 10

typedef struct treeNode{
	int data;
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
}treeNode;

void instruksiPencetTree();
treeNode* minValueNode(treeNode* node);
treeNode* createTreeNode(int data);
void insertNode (treeNode **root, int data);
void editNode(treeNode** root,int key);
treeNode* deleteNode (treeNode* root, int key);
void print2DUtil(treeNode *root, int space);
void print2D(treeNode *root);

// Mendapatkan array untuk node tree
int getArrayTree(treeNode* root, int arr[], int i){
	
	if(root == NULL)
	    return i;
		
	arr[i] = root->data;
	i++;
	if(root->leftPtr != NULL)
	    i = getArrayTree(root->leftPtr, arr, i);
	if(root->rightPtr != NULL)
	    i = getArrayTree(root->rightPtr, arr, i);
	
	return i;
}

// Berisi instruksi untuk binary tree
void instruksiPencetTree(){
	printf("\nPencet 6 untuk memilih fitur add/insert node\n");
	printf("Pencet 7 untuk memilih fitur edit node\n");
	printf("Pencet 8 untuk memilih fitur delete node\n");
	printf("Pencet 9 untuk memilih fitur search node\n");
	printf("Pencet 10 untuk memilih fitur menghentikan program\n");
}

// Mendapatkan nilai minimum di tree nodenya
treeNode* minValueNode(treeNode* node)
{
    treeNode* current = node;
 
    while (current && current->leftPtr != NULL)
        current = current->leftPtr;
 
    return current;
}

// Membuat node baru
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

// Menginsert node pada tree 
void insertNode(treeNode **root, int data){
	
	if(*root == NULL){
		*root = createTreeNode(data);
		return;
	}
	
	if(data < (*root)->data){
		insertNode(&((*root)->leftPtr),  data);
	}
	
	else if (data > (*root)->data){
		insertNode(&((*root)->rightPtr), data);
	}
	
	else{
		printf("Angka Duplikat\n\n");	
	}
	
	
}

// Mengedit node
void editNode(treeNode** root,int key)
{
	int dataBaru;
	
    if (*root == NULL)
        return;
 	
 	if((*root)->data == key){
 		printf("Node ditemukan\n");
 		printf("Masukkan angka baru untuk mengganti isi node : ");
 		scanf(" %d", &dataBaru);
 		(*root)->data = dataBaru;
 		return;
	 }
 	
    editNode(&((*root)->leftPtr),key);
 
    editNode(&((*root)->rightPtr),key);
    
}

// Menghapus node
treeNode* deleteNode (treeNode* root, int key){
	
	// Mengecek jika root tidak ada / empty
	if(root == NULL){
		return root;
	}
	
	// Jika key lebih kecil dari root data
	// maka ke subtree kiri pada root
	if(key < root->data)
		root->leftPtr = deleteNode(root->leftPtr, key);
		
	// Jika key lebih besar dari root data
	// maka ke subtree kanan pada root	
	else if(key > root->data)
		root->rightPtr = deleteNode(root->rightPtr, key);
	
	// Jika key sama dengan root data
	// Maka hapus node tersebut	
	else{
		// Jika node terdapat 1 child atau 0 child
		
		if(root->leftPtr == NULL){
			treeNode* temp = root->rightPtr;
			free(root);
			return temp;
		}
		else if (root->rightPtr == NULL){
			treeNode* temp = root->leftPtr;
			free(root);
			return temp;
		}
		
		// Jika node terdapat 2 child
		treeNode* temp = minValueNode(root->rightPtr);
		
		root->data = temp->data;
		
		root->rightPtr = deleteNode(root->rightPtr, temp->data);
	}
	
	return root;
}

// Memprint output binary tree
void print2DUtil(treeNode *root, int space)
{

    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2DUtil(root->rightPtr, space);
 
    printf("\n");
    int i;
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 

    print2DUtil(root->leftPtr, space);
}
 

void print2D(treeNode *root)
{

   print2DUtil(root, 0);
}
#endif
