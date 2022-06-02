#ifndef dataStruct.h
#define dataStruct.h

// Enumerator kategori untuk kategori stock barang
typedef enum Kategori{
	AlatTulis,
	Aksesoris,
	Buku,
	Gadget,
	Makanan,
	Minuman,
	Pakaian,
} KategoriEnum;

// Struct untuk expired Date
typedef struct Date{
	int yyyy; // tahun
	int mm; // bulan
	int dd; // hari
} Date;

// Struct untuk stock barangnya
typedef struct stockLink{
	char nama[200];
	KategoriEnum kategori;
	int hargaBarang;
	int sisaStock;
	int AmountSold;
	Date expiredDate;
	struct stockLink *next;	
} stockL;

#endif
