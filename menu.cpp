#include <iostream>     // Menyediakan fungsi untuk input-output standar (cout, cin)
#include <conio.h>      // Sama seperti iostream tetapi ini library conio.h seperti getch() dan system("cls") (khusus Windows)
using namespace std;    // Agar tidak perlu menulis std:: sebelum cout, cin, dll

const int MAX = 100;    // untuk mendeklarasikan sebuah variabel integer yang nilainya tidak dapat diubah setelah diinisialisasi, dan maksimal kapasitas array sampai 100
int data[MAX];          // deklarasi array bernama data, data yang dimasukkan di menu input akan dimasukkan di array ini
int n = 0;              // n Variabel untuk menyimpan jumlah data yang diinputkan

// Fungsi untuk menampilkan informasi pembuat program
void info() { 
    system("cls");      // Membersihkan layar konsol
    cout << "Nama  : Gean Prana Daniswara\n";
    cout << "NIM   : C030324018\n";
    cout << "Kelas : TI-2B\n";
    getch();            // Menunggu pengguna menekan tombol sebelum kembali
}

// Fungsi untuk menampilkan menu utama dari program ke layar
void dMenu() {
    system("cls");      // Bersihkan layar konsol
    cout << "Aplikasi Tampilan Menu\n";
    cout << "1. Input Nilai ke Array\n";
    cout << "2. Tampilkan Isi Array\n";
    cout << "3. Urutkan Array (Bubble Sort)\n";
    cout << "4. Informasi\n";
    cout << "5. Exit\n";
    cout << "Masukkan Angka: ";
}

// Fungsi untuk input data ke array
void inputArray() {
    system("cls");      // Bersihkan layar
    cout << "Masukkan jumlah elemen: ";
    cin >> n;           // Input jumlah elemen yang ingin dimasukkan 

    if(n > MAX) {       // ngecek apakah input melebihi kapasitas array
        cout << "Jumlah melebihi batas maksimal!\n";
        n = 0;          // jika input melebihi kapasitas maka di reset n ke 0 agar array tidak di proses
    } else { 
        // Loop (perulangan) untuk input data sebanyak n elemen
        for (int i = 0; i < n; i++) { // i itu adalah nilai data yang dimasukkan untuk jumlah elemen, kalau i kurang dari n maka i + 1
            cout << "Data ke-" << i + 1 << ": "; // Menampilkan pesan menggunakan i + 1 agar tampak data ke 1, data ke 2...
            cin >> data[i];     // Simpan nilai ke array
        }
    }
    getch();            // Tunggu input karakter sebelum lanjut enter
}

// Fungsi untuk menampilkan isi array
void tampilArray() {
    system("cls");      // Bersihkan layar
    if (n == 0) {       // Jika array belum di isi maka akan menampilkan teks ini
        cout << "Array masih kosong!\n";
    } else {
        cout << "Isi array: "; 
        for (int i = 0; i < n; i++) {   // Melakukan perulangan otomatis dari indeks i = 0
            cout << data[i] << " ";     // Menampilkan isi array satu persatu di pisahkan spasi
        }
        cout << "\n";
    }
    getch();            // Tunggu input karakter sebelum lanjut
}

// Fungsi untuk mengurutkan array menggunakan bubble sort
void bubbleSort() {
    system("cls");      // Bersihkan layar
    if (n == 0) {       // Jika array belum terisi maka akan tampil teks ini
        cout << "Array masih kosong!\n";
    } else {
        // Proses bubble sort
        for (int i = 0; i < n - 1; i++) { // Misalnya kalau jumlah data (n) ada 5, maka cukup dilakukan 4 kali pengulangan (n - 1)
            for (int j = 0; j < n - i - 1; j++) { // Membandingkan elemen bersebelahan, seperti data[0] dan data[1], data[1] dan data[2] 
                if (data[j] > data[j + 1]) { //Kalau elemen sebelah kiri lebih besar dari yang kanan, maka mereka belum urut harus ditukar
                    // Tukar data[j] dan data[j+1]
                    int temp = data[j]; // Di simpan sementara di variabel temp
                    data[j] = data[j + 1]; // Nilai data j ditukar ke data j + 1
                    data[j + 1] = temp; // ini proses menggeser angka yang besar ke kanan
                }
            }
        }
        cout << "Array berhasil diurutkan.\n";
        // Menampilkan hasil sorting array 
        cout << "Isi array setelah diurutkan: "; 
        for (int i = 0; i < n; i++) { // Melakukan perulangan otomatis dari indeks i = 0
            cout << data[i] << " "; // Menampilkan isi array satu persatu di pisahkan spasi
        }
        cout << "\n";
    }
    getch();            // Tunggu input karakter sebelum lanjut
}

// Fungsi utama program
int main() {
    char pilihan;       // Variabel untuk menyimpan pilihan menu

    do {
        dMenu();            // Tampilkan menu utama
        pilihan = getch(); // Ambil input pilihan tanpa perlu tekan Enter

        switch (pilihan) {  // Cek pilihan menu
            case '1':
                inputArray();   // Panggil fungsi input nilai ke array
                break;
            case '2':
                tampilArray();  // Panggil fungsi tampil data isi array dan hasil sorting 
                break;
            case '3':
                bubbleSort();   // Melakukan sorting 
                break;
            case '4':
                info();         // Tampilkan informasi pembuat
                break;
            case '5':
                break;          // Keluar dari loop  tampilan menu (program selesai)
            default:
                system("cls");  // Jika pilihan tidak valid
                cout << "Pilihan tidak tersedia!\n";
                getch();        // Tunggu user menekan tombol
                break;
        }
    } while (pilihan != '5');   // Ulangi selama pilihan bukan 5 (exit) jika klik 5 maka pilihan == 5 dan ke case '5' program selesai

    return 0;   // Akhiri program
}
