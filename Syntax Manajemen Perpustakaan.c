#include <stdio.h>
#include <string.h>

//Struktur data untuk buku
struct Book {
  char title[100];
  char author[100];
  char publisher[100];
  int year, pages, borrowed;
};

//Fungsi untuk mencari buku berdasarkan judul
int searchBook(struct Book books[], int n, char title[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(books[i].title, title) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  //Array untuk menyimpan data buku
  struct Book books[50];
  //Jumlah buku yang sudah ditambahkan
  int numBooks = 0;
  
  //Loop utama program
  while (1) {
    //Menampilkan menu
    printf("\n=======SELAMAT DATANG DI E-PERPUS=======\n");
    printf("\nSilahkan pilih menu layanan E-Perpus :\n");
    printf("1. Tambah buku\n");
    printf("2. Cari buku\n");
    printf("3. Pinjam buku\n");
    printf("4. Kembalikan buku\n");
    printf("5. Keluar\n");
    
    //Membaca pilihan user
    int choice;
    scanf("%d", &choice);
    
    //Proses pilihan user
    switch (choice) {
      case 1: {
        //Menambahkan buku
        printf("\nTAMBAH BUKU\n");
        
        //Membaca data buku dari user
        printf("Judul : ");
        scanf("%[^\n]", books[numBooks].title);
        printf("Pengarang : ");
        scanf("%[^\n]", books[numBooks].author);
        printf("Penerbit : ");
        scanf("%[^\n]", books[numBooks].publisher);
        printf("Tahun terbit : ");
        scanf("%d", &books[numBooks].year);
        printf("Jumlah halaman : ");
        scanf("%d", &books[numBooks].pages);
        
        //Menandai bahwa buku belum dipinjamkan
        books[numBooks].borrowed = 0;
        
        //Menaikkan jumlah buku yang sudah ditambahkan
        numBooks++;
        
        printf("Buku berhasil ditambahkan!\n");
        break;
      }
      case 2: {
        //Mencari buku
        printf("\nCARI BUKU\n");
