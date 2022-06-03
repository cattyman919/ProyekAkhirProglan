// KELOMPOK : 
// Zefanya Christira Deardo - 2106637214
// Seno Pamungkas Rahman - 2106731586
// Michael Gunawan - 2106731195

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataStruct.h"
#include "functions.h"
#include "tree.h"

int main(){
	stockL *head = NULL; 
	stockL *tmp = (struct stockLink*) malloc(sizeof(struct stockLink)); 
	
	int arrayTree[5000] = {};
	
	int pilihanFitur;
	
	// data awal linked list
	
	strcpy(tmp->nama, "Sariroti keju");
	tmp->kategori = Makanan;
	tmp->hargaBarang = 5000;
	tmp->sisaStock = 12;
	tmp->AmountSold = 20;
	tmp->expiredDate.dd = 20;
	tmp->expiredDate.mm = 4;
	tmp->expiredDate.yyyy = 2022;
	tmp->next = NULL;
	
	head = tmp;
	
	inputStockBarangL(head, "Pepsi 1,5L", Minuman, 15000, 20, 50, 7,12,2022);
	inputStockBarangL(head, "Kemeja Batik", Pakaian, 70000, 3, 5, 1,1,2030);
	inputStockBarangL(head, "Advan G9 Pro", Gadget, 1400000, 2, 1, 1,1,2030);
	
	// data awal binary tree
	treeNode *root = createTreeNode(5);
	root->leftPtr = createTreeNode(2);
	root->rightPtr = createTreeNode(3);
	
	do {
		int i = 0, data;
		int angkaTidakAda = 1;
		int size = sizeof(arrayTree)/sizeof(arrayTree[0]);
		getArrayTree(root,arrayTree,0);
		
		printf("\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PROGRAM STOCK BARANG >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
		printf("Stock Barang Saat Ini : \n");
		
		printf("\nData Linked List : \n\n");
		printf("|No\t |Nama barang\t |Kategori\t |Harga\t\t |Sisa Stock\t |Jumlah Terjual\t |Expired Date\n\n");
			
		
		if(totalBarangList(head) > 0)
			printDataLink(head);
	
		else{
			printf("Tidak ada stock barang untuk saat ini \n");
		}
		
		instruksiPencet();
		
		printf("\nBinary Tree : \n\n");
		print2D(root);
		instruksiPencetTree();
		
		// Input fitur
		inputAngkaErrorHandling("\nPilihan Fitur : ", &pilihanFitur, 1, 10);
		
		switch(pilihanFitur){
			
			case 1 : 
				fiturPengurutanData(head);
			break;
				
			case 2 :
				fiturMencariDataL(head);
			break;
			
			case 3 : 
				menambahkanStockBarangL(head);
			break;
			
			case 4 :
				// Kalau tidak ada stock barang, tidak bisa hapus pilihan barang
				if(head != NULL){
					menghapusPilihanStockBarangL(&head);
				}
				else{
					printf("Tidak bisa menghapus pilihan stock barang karena tidak ada stock barang\n");
				}
			break;
				
			case 5 :
				// Kalau tidak ada stock barang, tidak bisa edit pilihan barang
				if(totalBarangList(head) > 0){
					editStockBarangL(head);
				}
				else{
					printf("Tidak bisa mengedit pilihan stock barang karena tidak ada stock barang\n");
				}
			break;
			
			case 6 :
				printf("Masukkan angka untuk data node : ");
				scanf(" %d", &data);
				insertNode(&root,data);	
			break;
			
			case 7:
				// Menerima input edit node 
				// jika node tidak ditemukan, terdapat error handling
				// dan meminta inputnya lagi
				do {	
					printf("Pilih angka dari tree node untuk diedit : ");
					scanf(" %d", &data);
		
					for(i = 0 ; i < size; i++ ){
						if(data == arrayTree[i]){
							angkaTidakAda = 0;
						}
					}
					
					if(angkaTidakAda == 1) 
					printf("Angka %d yang dimasukkan tidak terdapat pada tree node\n", data);
					
				} while(angkaTidakAda == 1);

				editNode(&root, data);
			
				angkaTidakAda = 1;
			break;
			
			case 8 :
				// Menerima input delete node 
				// jika node tidak ditemukan, terdapat error handling
				// dan meminta inputnya lagi
				do {	
					printf("Masukkan angka pada node untuk dihapus : ");
					scanf(" %d", &data);
		
					for(i = 0 ; i < size; i++ ){
						if(data == arrayTree[i]){
							angkaTidakAda = 0;
						}
					}
					
					if(angkaTidakAda == 1) 
						printf("Angka %d yang dimasukkan tidak terdapat pada tree node\n", data);
					
				} while(angkaTidakAda == 1);
				
				root = deleteNode(root, data);
				
			break;
			case 9 :
				// Menerima input search node
				printf("Masukkan angka untuk dicari pada node : ");
				scanf(" %d", &data);
	
				for(i = 0 ; i < size; i++ ){
					if(data == arrayTree[i]){
						angkaTidakAda = 0;
					}
				}
				
				if(angkaTidakAda == 1) 
					printf("Angka %d yang dimasukkan tidak terdapat pada tree node\n", data);
				else
					printf("Angka %d terdapat pada tree node\n", data);
				
			break;
			
		}
		
	} while(pilihanFitur != 10);
	
	printf("\nTerima kasih telah menggunakan program ini :D");	
}
