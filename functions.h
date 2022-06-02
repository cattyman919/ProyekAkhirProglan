#include "sorting.h"
#include "dataStruct.h"

#ifndef functions.h
#define functions.h

// Function prototype
const char* getKategoriNama(KategoriEnum kategori);
void rekursiForLoopBarang(int i , stock barang[], int totalBarang);
void instruksiPencet();
void inputStockBarang(stock *barang, char nama[200], KategoriEnum kategori,int hargaBarang, int sisaStock,int AmountSold, int hari, int bulan, int tahun);
void outputStockBarang(stock barang, int i);
void fiturPengurutanData(struct stockLink *head);
int searchData (char* pat, char* txt);
void fiturMencariData(stock barang[], int totalBarang);
void menambahkanStockBarang(stock barang[], int totalBarang);
void menghapusPilihanStockBarang(stock *barang, int totalBarang);
void editStockBarang(stock barang[], int totalBarang);

void printDataLink(struct stockLink *head);
void inputStockBarangL (struct stockLink *head, char nama[200], KategoriEnum kategori,int hargaBarang, int sisaStock,int AmountSold, int hari, int bulan, int tahun);

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
 
void rekursiForLoopBarang(int i , stock barang[], int totalBarang){
	if(i == totalBarang)
		return;
			
	outputStockBarang(barang[i], i+1);
	
	rekursiForLoopBarang(i+1 , barang, totalBarang);
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
void inputStockBarang(stock *barang, char nama[200], KategoriEnum kategori,int hargaBarang, int sisaStock,int AmountSold, int hari, int bulan, int tahun){
	
	// Mengisi Nama
	strcpy(barang->nama, nama);
	
	// Mengisi kategori barang
	barang->kategori = kategori;
	
	// Mengisi harga barang
	barang->hargaBarang = hargaBarang;
	
	// Mengisi sisa stock barang
	barang->sisaStock = sisaStock;
	
	// Mengisi barang yang terjual
	barang->AmountSold = AmountSold;
	
	// Mengisi Expired Date
	barang->expiredDate.dd = hari;
	barang->expiredDate.mm = bulan;
	barang->expiredDate.yyyy = tahun;
}

// menampilkan hasil yang sudah ada dalam bentuk tabel
void outputStockBarang(stock barang, int i){
	printf("|%d\t |%s\t |%s\t |Rp %d\t", i ,barang.nama, getKategoriNama(barang.kategori), barang.hargaBarang);
	printf(" |%d\t\t |%d\t\t\t", barang.sisaStock, barang.AmountSold);
	printf(" |%d/%d/%d\n", 
		barang.expiredDate.dd,
		barang.expiredDate.mm,
		barang.expiredDate.yyyy);
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
	
	do{
		printf("Input pilihan pengurutan data : ");
		scanf(" %d", &inputPilihan);
		
		if(inputPilihan < 1 || inputPilihan > 6)
			printf("Input yang dimasukan melewati pilihan.\n");
	}while(inputPilihan < 1 || inputPilihan > 6);
	
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
void fiturMencariData(stock barang[], int totalBarang){
	int i, DitemukanBarang = 0;
	char searchKey[500];
	printf("\nInput nama barang yang ingin dicari : ");
	scanf(" %[^\n]", searchKey);
	printf("\n|No\t |Nama barang\t |Kategori\t |Harga\t\t |Sisa Stock\t |Jumlah Terjual\t |Expired Date\n\n");

	for(i = 0; i < totalBarang ; i++){
		if(searchData(searchKey, barang[i].nama) == 1){
			DitemukanBarang = 1;
			outputStockBarang(barang[i], i+1);
		}
	}
	if(DitemukanBarang == 0){
		printf("\t\t Tidak ada barang yang ditemukan berdasarkan pencarian nama : \'%s\' \n", searchKey);
	}
}

// berfungsi untuk menambahkan hal baru ke dalam program
// array sudah pass by reference di parameter
void menambahkanStockBarang(stock barang[], int totalBarang){
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
	
	// Error Handling kalau salah input
	do{
		printf("Input Kategori Barang: ");
		scanf(" %d", &kategoriAngka);
		
		if(kategoriAngka > 7 || kategoriAngka < 1)
			printf("Input yang dimasukan melewati batas kategori.\n");
		
	}while(kategoriAngka > 7 || kategoriAngka < 1);
	
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
	do{
		printf("Input Tanggal Hari Expired : ");
		scanf(" %d", &hari);
		if(hari < 1 || hari > 31)
			printf("Input tanggal hari melewati batas.\n");
	}while(hari < 1 || hari > 31);
	
	// Input Expired Bulan
	do{
		printf("Input Tanggal Bulan Expired : ");
		scanf(" %d", &bulan);
		if(bulan < 1 || bulan > 12)
			printf("Input tanggal bulan melewati batas.\n");
	}while(bulan < 1 || bulan > 12);
	
	// Input Expired Tahun
	do{
		printf("Input Tanggal Tahun Expired : ");
		scanf(" %d", &tahun);
		if(tahun < 2000 || tahun > 3000)
			printf("Input tanggal bulan melewati batas.\n");
	}while(tahun < 2000 || tahun > 3000);
	
	// Memanggil fungsi inputStockBarang dengan input yang sudah diterima dan menempatkan di
	// array totalBarang yang terakhir yaitu totalBarang-1
	inputStockBarang(&barang[totalBarang-1], nama,kategori,hargaBarang,
	sisaStock,AmountSold,hari,bulan,tahun);
}

// menghapus suatu stock barang yang sudah ada di dalam program
void menghapusPilihanStockBarang(stock *barang, int totalBarang){
	int i,j;
	int index = 0;
	
	// Error Handling jika dimasukan salah input
	do{

		printf("Input Pilihan Index Stock Barang yang Ingin Dihapus : ");
		scanf(" %d", &index);
		
		if(index > totalBarang || index < 1){
			printf("Input yang dimasukan salah, Index melebihi atau melewati batas dari total stock barang\n");
		}
	}while(index > totalBarang || index < 1);
	
	// Menghapus elemen index pada array
	for(i = index-1 ; i < totalBarang; i++){
		j = i+1;
		*(barang+i) = *(barang+j);
	}
}

// mengedit stock barang yang sudah ada
void editStockBarang(stock barang[], int totalBarang){
	
	int pilihanInput;
	
	do{
		printf("pilihan index stock barang yang ingin diedit : ");
		scanf(" %d", &pilihanInput);
		
		if(pilihanInput > totalBarang || pilihanInput < 1)
			printf("Input yang dimasukkan melewati batas total stock barang.\n");
	}while(pilihanInput > totalBarang || pilihanInput < 1);
	
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
	do{
		printf("Input Edit Tanggal Hari Expired : ");
		scanf(" %d", &hari);
		if(hari < 1 || hari > 31)
			printf("Input Edit tanggal hari melewati batas.\n");
	}while(hari < 1 || hari > 31);
	
	// Input Expired Bulan
	do{
		printf("Input Edit Tanggal Bulan Expired : ");
		scanf(" %d", &bulan);
		if(bulan < 1 || bulan > 12)
			printf("Input Edit tanggal bulan melewati batas.\n");
	}while(bulan < 1 || bulan > 12);
	
	// Input Expired Tahun
	do{
		printf("Input Edit Tanggal Tahun Expired : ");
		scanf(" %d", &tahun);
		if(tahun < 2000 || tahun > 3000)
			printf("Input Edit tanggal bulan melewati batas.\n");
	}while(tahun < 2000 || tahun > 3000);
	
	// Memanggil fungsi inputStockBarang dengan input yang sudah diterima dan menempatkan di
	// array totalBarang yang terakhir yaitu totalBarang-1
	inputStockBarang(&barang[pilihanInput-1], barang[pilihanInput-1].nama ,barang[pilihanInput-1].kategori,hargaBarang,
	sisaStock,AmountSold,hari,bulan,tahun);
}

void inputStockBarangL (struct stockLink *head, char nama[200], KategoriEnum kategori,int hargaBarang, int sisaStock,int AmountSold, int hari, int bulan, int tahun){
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

#endif
