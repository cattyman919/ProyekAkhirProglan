// KELOMPOK : 
// Zefanya Christira Deardo - 2106637214
// Seno Pamungkas Rahman - 2106731586
// Michael Gunawan - 2106731195

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataStruct.h"
#include "functions.h"

int main(){
	
	stock stockBarang[5000];
	stockL *head = NULL; 
	stockL *tmp = (struct stockLink*) malloc(sizeof(struct stockLink)); 
	int totalBarang = 4;
	int pilihanFitur;
	
	//data awal linked list
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

	
	do {
		int i = 0;
		
		printf("\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PROGRAM STOCK BARANG >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
		
		printf("Stock Barang Saat Ini : \n\n");
		printf("|No\t |Nama barang\t |Kategori\t |Harga\t\t |Sisa Stock\t |Jumlah Terjual\t |Expired Date\n\n");
		if(totalBarang > 0)
			rekursiForLoopBarang(i , stockBarang, totalBarang);
	
		else{
			printf("Tidak ada stock barang untuk saat ini \n");
		}
		
		printf("\nData Linked List : \n\n");
		printDataLink(head);
		
		instruksiPencet();
		
		// Error Handling jika salah input
		do{
			printf("Pilihan Fitur : ");
			scanf(" %d", &pilihanFitur);
			
			if(pilihanFitur > 6 || pilihanFitur < 1)
				printf("Input yang dimasukan melewati batas pilihan fitur.\n");
				
		}while(pilihanFitur > 6 || pilihanFitur < 1);
		
		
		switch(pilihanFitur){
			
			case 1 : 
				fiturPengurutanData(head);
				break;
				
			case 2 :
				fiturMencariData(stockBarang, totalBarang);
				break;
			
			case 3 : 
				totalBarang++;
				menambahkanStockBarang(stockBarang, totalBarang);
				break;
			
			case 4 :
				// Kalau tidak ada stock barang, tidak bisa hapus pilihan barang
				if(totalBarang > 0){
					menghapusPilihanStockBarang(stockBarang, totalBarang);
					totalBarang--;
				}
				else{
					printf("Tidak bisa menghapus pilihan stock barang karena tidak ada stock barang\n");
				}

				break;
				
			case 5 :
				// Kalau tidak ada stock barang, tidak bisa edit pilihan barang
				if(totalBarang > 0){
					editStockBarang(stockBarang, totalBarang);
				}
				else{
					printf("Tidak bisa mengedit pilihan stock barang karena tidak ada stock barang\n");
				}
				
				break;
		}
		
	} while(pilihanFitur != 6);
	printf("\nterima kasih telah menggunakan program ini :D");	
}
