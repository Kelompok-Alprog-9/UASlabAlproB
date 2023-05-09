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
        
        //Membaca judul buku yang dicari dari user
        char title[100];
        printf("Judul: ");
        scanf(" %[^\n]", title);
        
        //Mencari buku berdasarkan judul
        int index = searchBook(books, numBooks, title);
        
        //Menampilkan hasil pencarian
        if (index == -1){
          printf("Tidak ditemukan buku dengan judul %s\n", title);
        } else {
          printf("Judul buku: %s\n", books[index].title);
          printf("Pengarang: %s\n", books[index].author);
          printf("Tahun terbit: %d\n", books[index].year);
          printf("Penerbit: %s\n", books[index].publisher);
          printf("Jumlah halaman: %d\n", books[index].pages);
        }
        if (books[index].borrowed == 1) {
          printf("Status: Sedang dipinjam\n");
         } else {
          printf("Status: Tersedia\n");
            }
         break;
        }
        case 3: {
            //Meminjam buku
            printf("\nPINJAM BUKU:\n");

            //Membaca judul buku yang dipinjam dari user
            char title[100];
            printf("Judul: ");
            scanf(" %[^\n]", title);

            //Mencari buku berdasarkan judul
            int index = searchBook(books, numBooks, title);

            //Meminjam buku
            if (index == -1) {
                printf("Tidak ditemukan buku dengan judul %s\n", title);
            } else if (books[index].borrowed == 1) {
                printf("Buku sedang dipinjamkan.\n");
            } else {
                books[index].borrowed = 1;
                printf("Buku berhasil dipinjam.\n");
            }
            break;
           }
        case 4: {
            //Mengembalikan buku
            printf("\nKEMBALIKAN BUKU:\n");

            //Membaca judul buku yang dikembalikan dari user
            char title[100];
            printf("Judul: ");
            scanf(" %[^\n]", title);

            //Mencari buku berdasarkan judul
            int index = searchBook(books, numBooks, title);

            //Mengembalikan buku
            if (index == -1) {
                printf("Tidak ditemukan buku dengan judul %s\n", title);
            } else if (books[index].borrowed == 0) {
                printf("Buku tidak sedang dipinjamkan.\n");
            } else {
                books[index].borrowed = 0;
                printf("Buku berhasil dikembalikan.\n");
            }
            break;
        }
        case 5: {
            // Keluar dari program
            printf("\nTerima kasih telah mengunjungi E-Perpus .\n");
            return 0;
        }
        default: {
            // Pilihan tidak valid
            printf("\nPilihan tidak valid\n");
            break;
        }
     }
}
}
                 
