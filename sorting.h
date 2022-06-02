
// Function prototype
void sortAlphabet(stock *barang, int jumlah);
void sortKategori(stock *barang, int jumlah);
void sortBarangTerlaris(stock *barang, int jumlah);
void sortHarga(stock *barang, int jumlah);
void sortMasaExpired(stock *barang, int jumlah);
void sortSisaStock(stock *barang, int jumlah);

// mengurutkan secara alphabet menggunakan insertion sort
void sortAlphabet(stock *barang, int jumlah){
	int i, j;
    stock key;
    for (i = 1; i < jumlah; i++) { // key adalah wadah sementara untuk menampung nilai tertentu
        key.sisaStock = barang[i].sisaStock;
        key.AmountSold = barang[i].AmountSold;
        key.expiredDate = barang[i].expiredDate;
        key.hargaBarang = barang[i].hargaBarang;
        key.kategori = barang[i].kategori;
        strcpy(key.nama, barang[i].nama); // strcpy karena char
        j = i - 1;
    	
    	// bila barang[j].nama > key.nama maka proses penukaran terjadi
        while (j >= 0 && strcmp(barang[j].nama, key.nama) > 0) { // strcmp untuk membandingkan char yang lebih besar
            barang[j + 1].sisaStock = barang[j].sisaStock;
    		barang[j + 1].AmountSold = barang[j].AmountSold;
        	barang[j + 1].expiredDate = barang[j].expiredDate;
        	barang[j + 1].hargaBarang = barang[j].hargaBarang;
        	barang[j + 1].kategori = barang[j].kategori;
        	strcpy(barang[j + 1].nama, barang[j].nama);
            j = j - 1;
        }
        barang[j + 1].sisaStock = key.sisaStock;
    	barang[j + 1].AmountSold = key.AmountSold;
        barang[j + 1].expiredDate = key.expiredDate;
        barang[j + 1].hargaBarang = key.hargaBarang;
        barang[j + 1].kategori = key.kategori;
        strcpy(barang[j + 1].nama, key.nama);
    }
}

// mengurutkan secara kategori dengan insertion sort
void sortKategori(stock *barang, int jumlah){
	int i, j;
    stock key;
    for (i = 1; i < jumlah; i++) {
        key.sisaStock = barang[i].sisaStock;
        key.AmountSold = barang[i].AmountSold;
        key.expiredDate = barang[i].expiredDate;
        key.hargaBarang = barang[i].hargaBarang;
        key.kategori = barang[i].kategori;
        strcpy(key.nama, barang[i].nama);
        j = i - 1;
        
        while (j >= 0 && barang[j].kategori > key.kategori) {
            barang[j + 1].sisaStock = barang[j].sisaStock;
    		barang[j + 1].AmountSold = barang[j].AmountSold;
        	barang[j + 1].expiredDate = barang[j].expiredDate;
        	barang[j + 1].hargaBarang = barang[j].hargaBarang;
        	barang[j + 1].kategori = barang[j].kategori;
        	strcpy(barang[j + 1].nama, barang[j].nama);
            j = j - 1;
        }
        barang[j + 1].sisaStock = key.sisaStock;
    	barang[j + 1].AmountSold = key.AmountSold;
        barang[j + 1].expiredDate = key.expiredDate;
        barang[j + 1].hargaBarang = key.hargaBarang;
        barang[j + 1].kategori = key.kategori;
        strcpy(barang[j + 1].nama, key.nama);
    }
}

// mengurutkan secara penjualan terlaris dengan insertion sort
void sortBarangTerlaris(stock *barang, int jumlah){
	int i, j;
    stock key;
    for (i = 1; i < jumlah; i++) {
        key.sisaStock = barang[i].sisaStock;
        key.AmountSold = barang[i].AmountSold;
        key.expiredDate = barang[i].expiredDate;
        key.hargaBarang = barang[i].hargaBarang;
        key.kategori = barang[i].kategori;
        strcpy(key.nama, barang[i].nama);
        j = i - 1;
        
        while (j >= 0 && barang[j].AmountSold > key.AmountSold) {
            barang[j + 1].sisaStock = barang[j].sisaStock;
    		barang[j + 1].AmountSold = barang[j].AmountSold;
        	barang[j + 1].expiredDate = barang[j].expiredDate;
        	barang[j + 1].hargaBarang = barang[j].hargaBarang;
        	barang[j + 1].kategori = barang[j].kategori;
        	strcpy(barang[j + 1].nama, barang[j].nama);
            j = j - 1;
        }
        barang[j + 1].sisaStock = key.sisaStock;
    	barang[j + 1].AmountSold = key.AmountSold;
        barang[j + 1].expiredDate = key.expiredDate;
        barang[j + 1].hargaBarang = key.hargaBarang;
        barang[j + 1].kategori = key.kategori;
        strcpy(barang[j + 1].nama, key.nama);
    }
}

// mengurutkan secara besar harga dengan insertion sort
void sortHarga(stock *barang, int jumlah){
	int i, j;
    stock key;
    for (i = 1; i < jumlah; i++) {
        key.sisaStock = barang[i].sisaStock;
        key.AmountSold = barang[i].AmountSold;
        key.expiredDate = barang[i].expiredDate;
        key.hargaBarang = barang[i].hargaBarang;
        key.kategori = barang[i].kategori;
        strcpy(key.nama, barang[i].nama);
        j = i - 1;
        
        while (j >= 0 && barang[j].hargaBarang > key.hargaBarang) {
            barang[j + 1].sisaStock = barang[j].sisaStock;
    		barang[j + 1].AmountSold = barang[j].AmountSold;
        	barang[j + 1].expiredDate = barang[j].expiredDate;
        	barang[j + 1].hargaBarang = barang[j].hargaBarang;
        	barang[j + 1].kategori = barang[j].kategori;
        	strcpy(barang[j + 1].nama, barang[j].nama);
            j = j - 1;
        }
        barang[j + 1].sisaStock = key.sisaStock;
    	barang[j + 1].AmountSold = key.AmountSold;
        barang[j + 1].expiredDate = key.expiredDate;
        barang[j + 1].hargaBarang = key.hargaBarang;
        barang[j + 1].kategori = key.kategori;
        strcpy(barang[j + 1].nama, key.nama);
    }
}

// mengurutkan secara masa expired dengan insertion sort
void sortMasaExpired(stock *barang, int jumlah){
	int i, j;
    stock key;
    for (i = 1; i < jumlah; i++) {
        key.sisaStock = barang[i].sisaStock;
        key.AmountSold = barang[i].AmountSold;
        key.expiredDate = barang[i].expiredDate;
        key.hargaBarang = barang[i].hargaBarang;
        key.kategori = barang[i].kategori;
        strcpy(key.nama, barang[i].nama);
        j = i - 1;
        
        while (j >= 0 && barang[j].expiredDate.yyyy > key.expiredDate.yyyy // membandingkan tahun terlebih dulu, baru bulan, dan hari
				|| j >= 0 && barang[j].expiredDate.yyyy == key.expiredDate.yyyy && barang[j].expiredDate.mm > key.expiredDate.mm 
				|| j >= 0 && barang[j].expiredDate.yyyy == key.expiredDate.yyyy && barang[j].expiredDate.mm == key.expiredDate.mm 
				&& barang[j].expiredDate.dd > key.expiredDate.dd) {
            barang[j + 1].sisaStock = barang[j].sisaStock;
    		barang[j + 1].AmountSold = barang[j].AmountSold;
        	barang[j + 1].expiredDate = barang[j].expiredDate;
        	barang[j + 1].hargaBarang = barang[j].hargaBarang;
        	barang[j + 1].kategori = barang[j].kategori;
        	strcpy(barang[j + 1].nama, barang[j].nama);
            j = j - 1;
        }
        barang[j + 1].sisaStock = key.sisaStock;
    	barang[j + 1].AmountSold = key.AmountSold;
        barang[j + 1].expiredDate = key.expiredDate;
        barang[j + 1].hargaBarang = key.hargaBarang;
        barang[j + 1].kategori = key.kategori;
        strcpy(barang[j + 1].nama, key.nama);
    }
}

// mengurutkan secara sisa stock dengan insertion sort
void sortSisaStock(stock *barang, int jumlah){
    int i, j;
    stock key;
    for (i = 1; i < jumlah; i++) {
        key.sisaStock = barang[i].sisaStock;
        key.AmountSold = barang[i].AmountSold;
        key.expiredDate = barang[i].expiredDate;
        key.hargaBarang = barang[i].hargaBarang;
        key.kategori = barang[i].kategori;
        strcpy(key.nama, barang[i].nama);
        j = i - 1;
        
        while (j >= 0 && barang[j].sisaStock > key.sisaStock) {
            barang[j + 1].sisaStock = barang[j].sisaStock;
    		barang[j + 1].AmountSold = barang[j].AmountSold;
        	barang[j + 1].expiredDate = barang[j].expiredDate;
        	barang[j + 1].hargaBarang = barang[j].hargaBarang;
        	barang[j + 1].kategori = barang[j].kategori;
        	strcpy(barang[j + 1].nama, barang[j].nama);
            j = j - 1;
        }
        barang[j + 1].sisaStock = key.sisaStock;
    	barang[j + 1].AmountSold = key.AmountSold;
        barang[j + 1].expiredDate = key.expiredDate;
        barang[j + 1].hargaBarang = key.hargaBarang;
        barang[j + 1].kategori = key.kategori;
        strcpy(barang[j + 1].nama, key.nama);
    }
}
