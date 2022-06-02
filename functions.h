#include "sorting.h"
#include "dataStruct.h"

#ifndef functions.h
#define functions.h

// Function prototype
const char* getKategoriNama(KategoriEnum kategori);
void instruksiPencet();

void inputStockBarangL (struct stockLink *head, char nama[500], KategoriEnum kategori,int hargaBarang, int sisaStock,int AmountSold, int hari, int bulan, int tahun);

void outputStockBarangIndexL(struct stockLink *head, int i);

void fiturPengurutanData(struct stockLink *head);
int searchData (char* pat, char* txt);

void fiturMencariDataL(struct stockLink *head);

void menambahkanStockBarangL(struct stockLink *head);

void menghapusPilihanStockBarangL(struct stockLink **head);

void editStockBarangL(struct stockLink *head);

void printDataLink(struct stockLink *head);

int totalBarangList(struct stockLink *head);

void inputAngkaErrorHandling(char description[500], int *angka, int min, int max);

// Untuk mendapatkan string dari Enumerator Kategori
const char* getKategoriNama(KategoriEnum kategori){
	switch (kategori){
		case Makanan: return "Makanan";
		case Minuman: return "Minuman";
		case Pakaian: return "Pakaian";
		case Buku: return "Buku";
		case AlatTulis : return "Alat Tulis";
		case Gadget: return "Gadget";
		case Aksesoris: return "Aksesoris";
	}
}
 

// penjelasan pemmilihan menu
void instruksiPencet(){
		printf("\nPencet 1 untuk memilih fitur mengurutkan data\n");
		printf("Pencet 2 untuk memilih fitur mencari data\n");
		printf("Pencet 3 untuk memilih fitur menambahkan stock barang\n");
		printf("Pencet 4 untuk memilih fitur menghapus pilihan stock barang\n");
		printf("Pencet 5 untuk memilih fitur mengedit pilihan stock barang\n");
		printf("Pencet 6 untuk stop program stock barang\n");
}

// Untuk menginput stock barang pada program
// Menggunakan pointer untuk pass by reference, agar berubah di void main

void inputStockBarangL (struct stockLink *head, char nama[500], KategoriEnum kategori,int hargaBarang, int sisaStock,int AmountSold, int hari, int bulan, int tahun){
	struct stockLink *input = malloc(sizeof(struct stockLink));
	// Mengisi Nama
	strcpy(input->nama, nama);
	
	// Mengisi kategori barang
	input->kategori = kategori;
	
	// Mengisi harga barang
	input->hargaBarang = hargaBarang;
	
	// Mengisi sisa stock barang
	input->sisaStock = sisaStock;
	
	// Mengisi barang yang terjual
	input->AmountSold = AmountSold;
	
	// Mengisi Expired Date
	input->expiredDate.dd = hari;
	input->expiredDate.mm = bulan;
	input->expiredDate.yyyy = tahun;
	input->next = NULL;
	
	struct stockLink *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = input;
	return;
}

// menampilkan hasil yang sudah ada dalam bentuk tabel
void outputStockBarangIndexL(struct stockLink *head, int i){
	printf("|%d\t |%s\t |%s\t |Rp %d\t", i ,head->nama, getKategoriNama(head->kategori), head->hargaBarang);
	printf(" |%d\t\t |%d\t\t\t", head->sisaStock, head->AmountSold);
	printf(" |%d/%d/%d\n", 
		head->expiredDate.dd,
		head->expiredDate.mm,
		head->expiredDate.yyyy);
}

// mengurutkan barang sesuai kriteria yang dipilih
void fiturPengurutanData(stockL *head){

	int inputPilihan;
	
	printf("\nPilihlah fitur pengurutan data berdasarkan :\n");
	printf("1. Alphabet\n");
	printf("2. Kategori Barang\n");
	printf("3. Barang Terlaris\n");
	printf("4. Harga\n");
	printf("5. Masa Expired\n");
	printf("6. Sisa Stock\n");

	inputAngkaErrorHandling("Input pilihan pengurutan data : ", &inputPilihan, 1,6);
	
	switch(inputPilihan){
		case 1 :
			sortAlphabetL(head);
			break;
		case 2 :
			sortKategoriL(head);
			break;
		case 3 :
			sortBarangTerlarisL(head);
			break;
		case 4 :
			sortHargaL(head);
			break;
		case 5 :
			sortMasaExpiredL(head);
			break;
		case 6 :
			sortSisaStockL(head);
			break;
	}
}

// untuk mencari data yang sudah ada per karakter yang dimasukkan
int searchData (char* pat, char* txt){
	int M = strlen(pat);
    int N = strlen(txt);
 	int i;
    
    for (i = 0; i <= N - M; i++) {
        int j;
 
        // Mengecek 1 per satu 1 kata dan mengabaikan huruf kapital
        for (j = 0; j < M; j++)
        	if (txt[i + j] != pat[j] && txt[i+j] - pat[j] != 32 && txt[i+j] - pat[j] != -32)
                break;
		
        if (j == M) // Jika benar, return 1 untuk benar
            return 1;
    }
    
    // Jika salah, return 0 untuk salah
    return 0;
}

// hasil pencarian barang yang telah dilakukan
void fiturMencariDataL(struct stockLink *head){
	
	int i, DitemukanBarang = 0;
	char searchKey[500];
	printf("\nInput nama barang yang ingin dicari : ");
	scanf(" %[^\n]", searchKey);
	printf("\n|No\t |Nama barang\t |Kategori\t |Harga\t\t |Sisa Stock\t |Jumlah Terjual\t |Expired Date\n\n");
	
	struct stockLink *temp = head;
	int counter = 1;
	while(temp->next != NULL){
		
		if(searchData(searchKey, temp->nama) == 1){
			DitemukanBarang = 1;
			outputStockBarangIndexL(temp, counter);
		}
		counter++;
		temp = temp->next;
	}
	
	if(DitemukanBarang == 0){
		printf("\t\t Tidak ada barang yang ditemukan berdasarkan pencarian nama : \'%s\' \n", searchKey);
	}
	
}

// berfungsi untuk menambahkan hal baru ke dalam program
// array sudah pass by reference di parameter
void menambahkanStockBarangL(struct stockLink *head){
	
	char nama[500];
	int kategoriAngka;
	KategoriEnum kategori;
	int hargaBarang, sisaStock, AmountSold;
	int hari, bulan, tahun;
	
	printf("\nMasukan Data Stock Barang\n");
	
	// Input Nama
	printf("Input Nama Barang : ");
	scanf(" %[^\n]", nama);
	
	// Input Kategori
	printf("Kategori Barang :\n1. Makanan\n2. Minuman\n3. Pakaian\n4. Buku\n5. Alat Tulis\n6. Gadget\n7. Aksesoris\n");

	inputAngkaErrorHandling("Input Kategori Barang: ", &kategoriAngka, 1, 7);
	
	switch(kategoriAngka){
		case 1 : 
			kategori = Makanan;
			break;
		case 2 :
			kategori = Minuman;
			break;
		case 3 :
			kategori = Pakaian;
			break;
		case 4 : 
			kategori = Buku;
			break;
		case 5 : 
			kategori = AlatTulis;
			break;
		case 6 : 
			kategori = Gadget;
			break;
		case 7 : 
			kategori = Aksesoris;
			break;
	}
	
	// Input harga Barang
	do{
		printf("Input harga Barang : Rp ");
		scanf(" %d", &hargaBarang);
		
		if(hargaBarang < 0)
			printf("Input yang dimasukkan melewati batas harga barang.\n");
	}while(hargaBarang < 0);
	
	// Input Sisa Stock Barang
	do{
		printf("Input Sisa Stock Barang : ");
		scanf(" %d", &sisaStock);
		
		if(sisaStock < 0)
			printf("Input yang dimasukkan melewati batas sisa stock barang.\n");
	}while(sisaStock < 0);
	
	// Input Barang yang terjual
	do{
		printf("Input Barang yang terjual : ");
		scanf(" %d", &AmountSold);
		
		if(AmountSold < 0)
			printf("Input yang dimasukkan melewati batas barang yang terjual.\n");
	}while(AmountSold < 0);
	
	// Input Expired Hari 
	inputAngkaErrorHandling("Input Tanggal Hari Expired (1 - 31) : ", &hari, 1, 31);
	
	// Input Expired Bulan
	inputAngkaErrorHandling("Input Tanggal Bulan Expired (1 - 12) : ", &bulan, 1, 12);
	
	// Input Expired Tahun
	inputAngkaErrorHandling("Input Tanggal Tahun Expired (2000 - 3000) : ", &tahun, 2000, 3000);
	
	inputStockBarangL(head,nama,kategori,hargaBarang, sisaStock, AmountSold, hari, bulan, tahun);	
}

// menghapus suatu stock barang yang sudah ada di dalam program
void menghapusPilihanStockBarangL(struct stockLink **head){
	
	int index = 0;

	// Error Handling jika dimasukan salah input
	do{

		printf("Input Pilihan Index Stock Barang yang Ingin Dihapus : ");
		scanf(" %d", &index);
		
		if(index > totalBarangList(*head) || index < 1){
			printf("Input yang dimasukan salah, Index melebihi atau melewati batas dari total stock barang\n");
		}
	}while(index > totalBarangList(*head) || index < 1);
	
	struct stockLink *pointer  = *head;
	struct stockLink *pointer2 = *head;
	
	if(index == 1)
	{
		*head = pointer->next;
		free(pointer);
		pointer = NULL;
	}
	else
	{
		while (index != 1)
		{
			pointer2 = pointer;
			pointer = pointer->next;
			index--;
		}
		
		pointer2->next = pointer->next;
		free(pointer);
		pointer = NULL;
	}
}

// mengedit stock barang yang sudah ada
void editStockBarangL(struct stockLink *head){
		
	int pilihanInput;
	
	do{
		printf("pilihan index stock barang yang ingin diedit : ");
		scanf(" %d", &pilihanInput);
		
		if(pilihanInput > totalBarangList(head) || pilihanInput < 1)
			printf("Input yang dimasukkan melewati batas total stock barang.\n");
	}while(pilihanInput > totalBarangList(head) || pilihanInput < 1);
	
	KategoriEnum kategori;
	int hargaBarang, sisaStock, AmountSold;
	int hari, bulan, tahun;
	
	printf("\nMasukan Data Stock Barang\n");
	
	// Input harga Barang
	do{
		printf("Input Edit harga Barang : Rp ");
		scanf(" %d", &hargaBarang);
		
		if(hargaBarang < 0)
			printf("Input yang dimasukkan melewati batas harga barang.\n");
	}while(hargaBarang < 0);

	// Input Sisa Stock Barang
	do{
		printf("Input Edit Sisa Stock Barang : ");
		scanf(" %d", &sisaStock);
		
		if(sisaStock < 0)
			printf("Input yang dimasukkan melewati batas sisa stock barang.\n");
	}while(sisaStock < 0);
	
	// Input Barang yang terjual
	do{
		printf("Input Edit Barang yang terjual : ");
		scanf(" %d", &AmountSold);
		
		if(AmountSold < 0)
			printf("Input yang dimasukkan melewati batas barang yang terjual.\n");
	}while(AmountSold < 0);

	// Input Expired Hari 
	inputAngkaErrorHandling("Input Tanggal Hari Expired (1 - 31) : ", &hari, 1, 31);
	
	// Input Expired Bulan
	inputAngkaErrorHandling("Input Tanggal Bulan Expired (1 - 12) : ", &bulan, 1, 12);
	
	// Input Expired Tahun
	inputAngkaErrorHandling("Input Tanggal Tahun Expired (2000 - 3000) : ", &tahun, 2000, 3000);
	
	struct stockLink *pointer = head;
	
	while (pilihanInput != 1)
	{
		pointer = pointer->next;
		pilihanInput--;
	}
	
	// Mengisi kategori barang
	pointer->kategori = kategori;
	
	// Mengisi harga barang
	pointer->hargaBarang = hargaBarang;
	
	// Mengisi sisa stock barang
	pointer->sisaStock = sisaStock;
	
	// Mengisi barang yang terjual
	pointer->AmountSold = AmountSold;
	
	// Mengisi Expired Date
	pointer->expiredDate.dd = hari;
	pointer->expiredDate.mm = bulan;
	pointer->expiredDate.yyyy = tahun;
}

void printDataLink(struct stockLink *head){
	int i = 1;
	struct stockLink *barang = head;
	while(barang != NULL) {
		printf("|%d\t |%s\t |%s\t |Rp %d\t", i , barang->nama, getKategoriNama(barang->kategori), barang->hargaBarang);
		printf(" |%d\t\t |%d\t\t\t", barang->sisaStock, barang->AmountSold);
		printf(" |%d/%d/%d\n", 
		barang->expiredDate.dd,
		barang->expiredDate.mm,
		barang->expiredDate.yyyy);
		barang = barang->next;
		i++;
	}
}

int totalBarangList(struct stockLink *head){
	struct stockLink *pointer = head;
	int count = 0;
	
	if(pointer == NULL){
		return count;
	}
	
	while(pointer != NULL){
		pointer = pointer->next;
		count++;
	}

	return count;	
}

void inputAngkaErrorHandling(char description[500], int *angka, int min, int max){
	do{

		printf("%s", description);
		scanf(" %d", angka);
		
		if(*angka > max || *angka < min){
			printf("Input yang dimasukan salah, Input melewati batas\n");
		}
	}while(*angka > max || *angka < min);
}
#endif
