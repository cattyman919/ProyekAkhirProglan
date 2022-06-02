
// Function prototype
void sortAlphabet(stock *barang, int jumlah);
void sortKategori(stock *barang, int jumlah);
void sortBarangTerlaris(stock *barang, int jumlah);
void sortHarga(stock *barang, int jumlah);
void sortMasaExpired(stock *barang, int jumlah);
void sortSisaStock(stock *barang, int jumlah);

void swapData(stockL *a, stockL *b);
void sortAlphabetL(stockL *head);
void sortKategoriL(stockL *head);
void sortBarangTerlarisL(stockL *head);
void sortHargaL(stockL *head);
void sortMasaExpiredL(stockL *head);
void sortSisaStockL(stockL *head);

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

void sortAlphabetL(stockL *head){
    int swapped, i;
    stockL *barang;
    stockL *lptr = NULL;
    
    /* Checking for empty list */
    if (head == NULL)
        return;
    do {
        swapped = 0;
        barang = head;
  
        while (barang->next != lptr){
            if (strcmp(barang->nama, barang->next->nama) > 0){ 
                swapData (barang, barang->next);
                swapped = 1;
            }
            barang = barang->next;
        }
        lptr = barang;
    }
    while (swapped);
}

void sortKategoriL(stockL *head){
	int swapped, i;
    stockL *barang;
    stockL *lptr = NULL;
    
    /* Checking for empty list */
    if (head == NULL)
        return;
    do {
        swapped = 0;
        barang = head;
  
        while (barang->next != lptr){
            if (barang->kategori > barang->next->kategori){ 
                swapData (barang, barang->next);
                swapped = 1;
            }
            barang = barang->next;
        }
        lptr = barang;
    }
    while (swapped);
}

void sortBarangTerlarisL(stockL *head){
		int swapped, i;
    stockL *barang;
    stockL *lptr = NULL;
    
    /* Checking for empty list */
    if (head == NULL)
        return;
    do {
        swapped = 0;
        barang = head;
  
        while (barang->next != lptr){
            if (barang->AmountSold > barang->next->AmountSold){ 
                swapData (barang, barang->next);
                swapped = 1;
            }
            barang = barang->next;
        }
        lptr = barang;
    }
    while (swapped);
}

void sortHargaL(stockL *head){
		int swapped, i;
    stockL *barang;
    stockL *lptr = NULL;
    
    /* Checking for empty list */
    if (head == NULL)
        return;
    do {
        swapped = 0;
        barang = head;
  
        while (barang->next != lptr){
            if (barang->hargaBarang > barang->next->hargaBarang){ 
                swapData (barang, barang->next);
                swapped = 1;
            }
            barang = barang->next;
        }
        lptr = barang;
    }
    while (swapped);
}

void sortMasaExpiredL(stockL *head){
		int swapped, i;
    stockL *barang;
    stockL *lptr = NULL;
    
    /* Checking for empty list */
    if (head == NULL)
        return;
    do {
        swapped = 0;
        barang = head;
  
        while (barang->next != lptr){
            if (barang->expiredDate.yyyy > barang->next->expiredDate.yyyy 
				|| barang->expiredDate.yyyy == barang->next->expiredDate.yyyy 
				&& barang->expiredDate.mm > barang->next->expiredDate.mm
				|| barang->expiredDate.yyyy == barang->next->expiredDate.yyyy 
				&& barang->expiredDate.mm == barang->next->expiredDate.mm 
				&& barang->expiredDate.dd > barang->next->expiredDate.dd){ 
                swapData (barang, barang->next);
                swapped = 1;
            }
            barang = barang->next;
        }
        lptr = barang;
    }
    while (swapped);
}

void sortSisaStockL(stockL *head){
		int swapped, i;
    stockL *barang;
    stockL *lptr = NULL;
    
    /* Checking for empty list */
    if (head == NULL)
        return;
    do {
        swapped = 0;
        barang = head;
  
        while (barang->next != lptr){
            if (barang->sisaStock > barang->next->sisaStock){ 
                swapData (barang, barang->next);
                swapped = 1;
            }
            barang = barang->next;
        }
        lptr = barang;
    }
    while (swapped);
}


/* function to swap data of two nodes a and b*/
void swapData(stockL *a, stockL *b){
	stockL *temp = malloc(sizeof(struct stockLink));
	
    temp->AmountSold = a->AmountSold;
    a->AmountSold = b->AmountSold;
    b->AmountSold = temp->AmountSold;
    
    temp->hargaBarang = a->hargaBarang;
    a->hargaBarang = b->hargaBarang;
    b->hargaBarang = temp->hargaBarang;
    
    temp->kategori = a->kategori;
    a->kategori = b->kategori;
    b->kategori = temp->kategori;
    
    temp->sisaStock = a->sisaStock;
    a->sisaStock = b->sisaStock;
    b->sisaStock = temp->sisaStock;
    
    temp->expiredDate.dd = a->expiredDate.dd;
    a->expiredDate.dd = b->expiredDate.dd;
    b->expiredDate.dd = temp->expiredDate.dd;
    
    temp->expiredDate.mm = a->expiredDate.mm;
    a->expiredDate.mm = b->expiredDate.mm;
    b->expiredDate.mm = temp->expiredDate.mm;
    
    temp->expiredDate.yyyy = a->expiredDate.yyyy;
    a->expiredDate.yyyy = b->expiredDate.yyyy;
    b->expiredDate.yyyy = temp->expiredDate.yyyy;
    
    strcpy (temp->nama, a->nama);
    strcpy(a->nama, b->nama);
    strcpy(b->nama, temp->nama);
}



