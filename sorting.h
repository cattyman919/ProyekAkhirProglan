// Function prototype
void swapData(stockL *a, stockL *b);
void sortAlphabetL(stockL *head);
void sortKategoriL(stockL *head);
void sortBarangTerlarisL(stockL *head);
void sortHargaL(stockL *head);
void sortMasaExpiredL(stockL *head);
void sortSisaStockL(stockL *head);

// mengurutkan secara alphabet menggunakan insertion sort
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

// mengurutkan secara kategori dengan insertion sort
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

// mengurutkan secara penjualan terlaris dengan insertion sort
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

// mengurutkan secara besar harga dengan insertion sort
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

// mengurutkan secara masa expired dengan insertion sort
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

// mengurutkan secara sisa stock dengan insertion sort
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



