#include <stdio.h>
#include <string.h>

// Struktur data untuk buku
struct Book {
  char title[100];
  char author[100];
  char publisher[100];
  char genre[100];
  int year, pages, borrowed;
};

// Fungsi untuk mencari buku berdasarkan judul
int searchBook(struct Book books[], int n, char title[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(books[i].title, title) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  // Jumlah buku yang sudah ditambahkan
  int numBooks = 0;
  
  // Input data buku
  FILE *fileBook;
    struct Book books[50] = {
        {"Antara Dia, Aku & Mereka", "Felix Y. Siauw", "Alfatih Press", "Non Fiksi", 2019, 288, 0},
        {"Kamu Gak Sendiri", "Syahid Muhammad", "Gradien Mediatama", "Non Fiksi", 2019, 340, 0},
        {"Bumi", "Tere Liye", "Gramedia Pustaka Utama", "Fantasi", 2014, 438, 0},
        {"Beyond the Inspiration", "Felix Y. Siauw", "Alfatih Press", "Non Fiksi", 2010, 267, 0},
        {"#Pernah Tenggelam", "Fuadh Naim", "Alfatih Press", "Non Fiksi", 2019, 224, 0},
        {"Si Anak Cahaya", "Tere Liye", "Republika", "Fiksi Anak", 2018, 417, 0},
        {"Rasa", "Tere Liye", "Sabak Grip", "Romansa", 2022, 419, 0},
        {"Muhammad Al-Fatih 1453", "Felix Y. Siauw", "Alfatih Press", "Sejarah", 2013, 318, 0},
        {"How to Master Your Habits", "Felix Y. Siauw", "Alfatih Press", "Non Fiksi", 2018, 170, 0},
        {"Sesuk", "Tere Liye", "Sabak Grip", "Horor", 2022, 327, 0},
        {"Pulang-Pergi", "Tere Liye", "Sabak Grip", "Aksi", 2020, 414, 0},
        {"Atomic Habit", "James Clear", "Gramedia Pustaka Umum", "Non Fiksi", 2018, 356, 0},
        {"Antara Ibuku dan Ibuku", "Desni Intan Suri", "Salsabila", "Non Fiksi", 2011, 281, 0},
        {"Majnun", "Anton Kurnia", "Baca", "Fiksi", 2022, 199, 0},
        {"Tak Mungkin Membuat Semua Orang Senang", "Jeong Moon-jeong", "Gramedia Pustaka Utama", "Self-Improvement", 2019, 206, 0},
        {"172 Days", "Nadira Shafa", "Motivaksi Inspira", "Fiksi", 2022, 241, 0},
        {"Oh My Savior", "Washashira", "Akad", "Fiksi", 2022, 276, 0},
        {"Si Putih", "Tere Liye", "Gramedia Pustaka Utama", "Fantasi", 2021, 373, 0},
        {"Laut Bercerita", "Leila S. Chudori", "Gramedia Pustaka Utama", "Sejarah", 2017, 379, 0},
        {"Dikta dan Hukum", "Dhia'an Farah", "Asoka Aksara X Loveable", "Romansa", 2021, 320, 0},
        {"Gadis Minimarket", "Sayaka Murata", "Gramedia Pustaka Utama", "Romansa", 2020, 160, 0},
        {"Janji", "Tere Liye", "Sabak Grip", "Drama", 2021, 486, 0},
        {"Tentang Kamu", "Tere Liye", "Republika", "Drama", 2016, 524, 0},
        {"Twenty Four Eyes", "Sakae Tsuboi", "Gramedia Pustaka Utama", "Fiksi", 2021, 248, 0},
        {"Negeri 5 Menara", "Ahmad Fuadi", "Gramedia Pustaka Utama", "Drama", 2009, 423, 0},
        {"Soekarno Sang Guru Bangsa", "Anom Whani Wicaksana", "C-Klik Media", "Non Fiksi", 2017, 210, 0},
        {"Pergi", "Tere Liye", "Republika", "Aksi", 2018, 455, 0},
        {"Si Anak Savana", "Tere Liye", "Sabak Grip", "Fiksi Anak", 2022, 380, 0},
        {"Lima Cerita", "Desi Anwar", "Gramedia Pustaka Utama", "Non Fiksi", 2019, 320, 0},
        {"Man's Search For Meaning", "Viktor E. Frankl", "Noura Books Publishing", "Self-Improvement", 2018, 233, 0},
        {"What's So Wrong About Your Life", "Ardhi Mohamad", "Bhumi Anoma", "Non Fiksi", 2019, 180, 0},
        {"Bicara Itu Ada Seninya", "Oh Su-hyang", "Bhuana Ilmu Populer", "Self-Improvement", 2018, 238, 0},
        {"Bibi Gill", "Tere Liye", "Sabak Grip", "Fantasi", 2021, 356, 0},
        {"Introvert and Extrovert is Fine", "Amir Ubaidillah", "C-Klik Media", "Non Fiksi", 2021, 168, 0},
        {"The Ikigai Journey", "Hector Garcia", "Renebook", "Non Fiksi", 2017, 289, 0},
        {"Hello", "Tere Liye", "Sabak Grip", "Romansa", 2023, 318, 0},
        {"SagaraS", "Tere Liye", "Sabak Grip", "Fantasi", 2021, 384, 0},
        {"Loving the Wounded Soul", "Regis Machdy", "Gramedia Pustaka Utama", "Non Fiksi", 2019, 324, 0},
        {"Lost & Found", "Nirasha Darusman", "Kawan Pustaka", "Non Fiksi", 2022, 408, 0},
        {"Bittersweet", "Susan Cain", "Gramedia Pustaka Utama", "Non Fiksi", 2012, 312, 0},
        {"Tanah Para Bandit", "Tere Liye", "Sabak Grip", "Aksi", 2023, 433, 0},
        {"Sebuah Seni Untuk Bersikap Bodo Amat", "Mark Manson", "Grasindo", "Self-Improvement", 2022, 243, 0},
        {"The Lonely Stories", "Natalie Eve Garrett", "Alvi Ardhi Publishing", "Non Fiksi", 2022, 296, 0},
        {"Brianna dan Bottomwise", "Andrea Hirata", "Bentang Pustaka", "Fiksi", 2022, 380, 0},
        {"Bedebah di Ujung Tanduk", "Tere Liye", "Sabak Grip", "Aksi", 2021, 411, 0},
        {"Hujan", "Tere Liye", "Gramedia Pustaka Utama", "Romansa", 2016, 318, 0},
        {"Man Boy", "Alia Zalea", "Gramedia Pustaka Utama", "Fiksi", 2023, 312, 0},
        {"Paint", "Lee Hee-young", "M&C", "Fiksi", 2020, 362, 0},
        {"Si Anak Pelangi", "Tere Liye", "Sabak Grip", "Fiksi Anak", 2021, 365, 0},
        {"Rindu", "Tere Liye", "Republika", "Drama", 2014, 544, 0},

    };
  
  // Membuka file untuk menuliskan data
    fileBook = fopen("D:/TugasAlprolab/dataBuku.txt", "w");

    // Menuliskan data buku ke file
    for (numBooks = 0; numBooks < 50; numBooks++) {
        fprintf(fileBook, "Buku ke-%d\n", numBooks + 1);
        fprintf(fileBook, "Judul: %s\n", books[numBooks].title);
        fprintf(fileBook, "Pengarang: %s\n", books[numBooks].author);
        fprintf(fileBook, "Tahun terbit: %d\n", books[numBooks].year);
        fprintf(fileBook, "Penerbit: %s\n", books[numBooks].publisher);
        fprintf(fileBook, "Genre: %s\n", books[numBooks].genre);
        fprintf(fileBook, "Jumlah halaman: %d\n", books[numBooks].pages);
        fprintf(fileBook, "\n");
    }

    // Menutup file
    fclose(fileBook);

  // Loop utama program
  printf("\n=======SELAMAT DATANG DI E-PERPUS=======\n");
  while (1) {
    // Menampilkan menu
    printf("\nSilahkan pilih menu layanan E-Perpus :\n");
    printf("1. Tambah buku\n");
    printf("2. Cari buku\n");
    printf("3. Pinjam buku\n");
    printf("4. Kembalikan buku\n");
    printf("5. Keluar\n");
    
    // Membaca pilihan user
    int choice;
    printf("\nPilihan anda : ");
    scanf("%d", &choice);
    
    // Proses pilihan user
    switch (choice) {
      case 1: {
        // Menambahkan buku
        printf("\nTAMBAH BUKU\n");
        
        // Membaca data buku dari user
        printf("Judul : ");
        scanf(" %[^\n]", books[numBooks].title);
        printf("Pengarang : ");
        scanf(" %[^\n]", books[numBooks].author);
        printf("Penerbit : ");
        scanf(" %[^\n]", books[numBooks].publisher);
        printf("Tahun terbit : ");
        scanf("%d", &books[numBooks].year);
        printf("Genre : ");
        scanf(" %[^\n]", books[numBooks].genre);
        printf("Jumlah halaman : ");
        scanf("%d", &books[numBooks].pages);
        
        // Menandai bahwa buku belum dipinjamkan
        books[numBooks].borrowed = 0;
        
        // Menaikkan jumlah buku yang sudah ditambahkan
        numBooks++;
        
        printf("Buku berhasil ditambahkan!\n");
        break;
      }
      case 2: {
        // Mencari buku
        printf("\nCARI BUKU\n");
        
        // Membaca judul buku yang dicari dari user
        char title[100];
        printf("Judul: ");
        scanf(" %[^\n]", title);
        
        // Mencari buku berdasarkan judul
        int index = searchBook(books, numBooks, title);
        
        // Menampilkan hasil pencarian
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
            // Meminjam buku
            printf("\nPINJAM BUKU:\n");

            // Membaca judul buku yang dipinjam dari user
            char title[100];
            printf("Judul: ");
            scanf(" %[^\n]", title);

            // Mencari buku berdasarkan judul
            int index = searchBook(books, numBooks, title);

            // Meminjam buku
            if (index == -1) {
                printf("Tidak ditemukan buku dengan judul %s\n", title);
            } else if (books[index].borrowed == 1) {
                printf("Buku sedang dipinjamkan. Cari buku lain\n");
            } else {
                books[index].borrowed = 1;
                printf("Buku berhasil dipinjam.\n");
            }
            break;
           }
        case 4: {
            // Mengembalikan buku
            printf("\nKEMBALIKAN BUKU:\n");

            // Membaca judul buku yang dikembalikan dari user
            char title[100];
            printf("Judul: ");
            scanf(" %[^\n]", title);

            // Mencari buku berdasarkan judul
            int index = searchBook(books, numBooks, title);

            // Mengembalikan buku
            if (index == -1) {
                printf("Tidak ditemukan buku dengan judul %s\n", title);
            } else if (books[index].borrowed == 0) {
                printf("Buku tidak sedang dipinjamkan. Pastikan cek status buku terlebih dahulu.\n");
            } else {
                books[index].borrowed = 0;
                printf("Buku berhasil dikembalikan.\n");
            }
            break;
        }
        case 5: {
            // Keluar dari program
            printf("\nTERIMA KASIH TELAH MENGUNJUNGI E-PERPUS!\n");
            printf("\nSILAHKAN DATANG LAIN KALI.\n);
            return 0;
        }
        default: {
            // Pilihan tidak valid
            printf("\nPILIHAN TIDAK VALID\n");
            break;
        }
     }
}
}
                 
