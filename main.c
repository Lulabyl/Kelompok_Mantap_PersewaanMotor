#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_MOTOR 100

typedef struct {
    char username[30];
    char password[30];
} User;

User currentUser;
int isLoggedIn = 0;

typedef struct {
    char nama[30];
    int stok;
    float hargaPerHari;
} Motor;

Motor daftarMotor[MAX_MOTOR];
int jumlahMotor = 0;

typedef struct {
    char namaPenyewa[50];
    char namaMotor[30];
    int durasiSewa;
} Penyewa;

Penyewa daftarPenyewa[100];
int jumlahPenyewa = 0;

void clearScreen();
void tampilanMainMenu();
void registerUser();
void loginUser();
void tampilanMenuMasuk();
void menuMasuk(int a);
void tambahMotor();
void stockMotor();
void dataPenyewa();

int main() {
    int pilihan;

    currentUser.username[0] = '\0';
    currentUser.password[0] = '\0';
    do {
            clearScreen();
            tampilanMainMenu();
            printf("Masukkan Pilihan Anda : ");
            scanf("%d", &pilihan);
            getchar();

            switch (pilihan) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    loginUser();
                    break;
                case 0:
                    printf("\nTerima kasih telah menggunakan program Sewa Motor SatuHati.\n");
                    break;
                default:
                    printf("\nPilihan tidak valid. Yang benar saja!.\n");
                    break;
            }

             if (pilihan != 0){
                printf("\nTekan ENTER untuk melanjutkan...");
                getchar();
                printf("\n");
             }
    }while (pilihan != 0);

    return 0;
}

void menuMasuk(int a){
do {
    clearScreen();
    tampilanMenuMasuk();
    printf("Masukkan pilihan: ");
    scanf("%d", &a);
    getchar();

    switch (a) {
        case 1:
            tambahMotor();
            break;
        case 2:
            stockMotor();
            break;
            
        case 3:
            dataPenyewa();
            break;

        case 4:
            printf("menu 4 belum dibuat pak\n");
            break;

        case 5:
            printf("menu 5 belum dibuat pak\n");
            break;
        case 0:
            isLoggedIn = 0;
            printf("Logout berhasil.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
    }

    if (a != 0) {
        printf("Tekan ENTER untuk kembali...");
        getchar();
    }
} while (a != 0);
}

void tambahMotor() {
    if (jumlahMotor >= MAX_MOTOR) {
        printf("Kapasitas data motor penuh.\n");
        return;
    }

    Motor m;

    printf("\n--- TAMBAH DATA MOTOR ---\n");

    printf("Nama Motor: ");
    fgets(m.nama, sizeof(m.nama), stdin);
    m.nama[strcspn(m.nama, "\n")] = '\0';

    printf("Jumlah Stok: ");
    scanf("%d", &m.stok);
    getchar();

    printf("Harga Sewa per Hari: ");
    scanf("%f", &m.hargaPerHari);
    getchar();

    daftarMotor[jumlahMotor] = m;
    jumlahMotor++;

    printf("Motor berhasil ditambahkan!\n");
}

void stockMotor() {
    if (jumlahMotor == 0) {
        printf("\nBelum ada data motor yang ditambahkan.\n");
        return;
    }

    printf("\n--- DAFTAR STOK MOTOR ---\n");
    for (int i = 0; i < jumlahMotor; i++) {
        printf("Motor ke-%d\n", i + 1);
        printf("Nama Motor        : %s\n", daftarMotor[i].nama);
        printf("Jumlah Stok       : %d\n", daftarMotor[i].stok);
        printf("Harga per Hari    : Rp %.2f\n", daftarMotor[i].hargaPerHari);
        printf("-----------------------------------\n");
    }
}

void dataPenyewa() {
    if (jumlahMotor == 0) {
        printf("Belum ada data motor yang tersedia untuk disewa.\n");
        return;
    }

    Penyewa p;

    printf("\n--- INPUT DATA PENYEWA ---\n");
    printf("Nama Penyewa: ");
    fgets(p.namaPenyewa, sizeof(p.namaPenyewa), stdin);
    p.namaPenyewa[strcspn(p.namaPenyewa, "\n")] = '\0';

    printf("\nPilih motor yang ingin disewa:\n");
    for (int i = 0; i < jumlahMotor; i++) {
        printf("%d. %s (Stok: %d, Harga/hari: Rp %.2f)\n", i + 1,
               daftarMotor[i].nama, daftarMotor[i].stok, daftarMotor[i].hargaPerHari);
    }

    int pilihan;
    printf("Masukkan nomor motor: ");
    scanf("%d", &pilihan);
    getchar();

    if (pilihan < 1 || pilihan > jumlahMotor) {
        printf("Pilihan tidak valid.\n");
        return;
    }

    if (daftarMotor[pilihan - 1].stok == 0) {
        printf("Maaf, motor ini sedang kosong.\n");
        return;
    }

    strcpy(p.namaMotor, daftarMotor[pilihan - 1].nama);

    printf("Lama sewa (hari): ");
    scanf("%d", &p.durasiSewa);
    getchar();

    daftarMotor[pilihan - 1].stok--;

    daftarPenyewa[jumlahPenyewa] = p;
    jumlahPenyewa++;

    printf("Data penyewa berhasil disimpan!\n");
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
    system("clear");
    #endif
}

void tampilanMainMenu(){
    printf("=================================================\n");
    printf("=    SELAMAT DATANG DI SEWA MOTOR SATUHATI      =\n");
    printf("=================================================\n");
    printf("=   	          1.REGISTER                    =\n");
    printf("=                 2.LOGIN                       =\n");
    printf("=                 0.EXIT                        =\n");
    printf("=================================================\n");
    printf("= Dari Kami, Untuk Perjalanan Tak Terlupakanmu. =\n");
    printf("=================================================\n");
}
void tampilanMenuMasuk(){
    printf("=================================================\n");
    printf("=    SELAMAT DATANG DI SEWA MOTOR SATUHATI      =\n");
    printf("=================================================\n");
    printf("=   	      1.Tambah Stok Motor               =\n");
    printf("=             2.Semua Jenis Motor               =\n");
    printf("=             3.Tambah Data Penyewa             =\n");
    printf("=             4.Kalkulasi Harga                 =\n");
    printf("=             5.Cetak Struk                     =\n");
    printf("=             0.LOGOUT                          =\n");
    printf("=================================================\n");
    printf("= Dari Kami, Untuk Perjalanan Tak Terlupakanmu. =\n");
    printf("=================================================\n");
}

void registerUser() {
     if (strlen(currentUser.username) > 0) {
            printf("\nMaaf, hanya satu atmin yang bisa diregistrasi untuk saat ini.\n");
            printf("User '%s' sudah terdaftar.\n", currentUser.username);
            return;
     }
      printf("\n--- REGISTRASI USER BARU ---\n");
      printf("Masukkan Username: ");

    fgets(currentUser.username, sizeof(currentUser.username), stdin);
    currentUser.username[strcspn(currentUser.username, "\n")] = '\0';

    printf("Masukkan Password: ");
    fgets(currentUser.password, sizeof(currentUser.password), stdin);
    currentUser.password[strcspn(currentUser.password, "\n")] = '\0';

    printf("Registrasi berhasil! Sekarang Anda bisa LOGIN.\n");
}

void loginUser() {
    if (isLoggedIn) {
        printf("\nAnda sudah login sebagai '%s'. Silakan logout terlebih dahulu.\n", currentUser.username);
        return;
    }

    if (strlen(currentUser.username) == 0) {
        printf("\nBelum ada user yang terdaftar. Silakan REGISTER terlebih dahulu.\n");
        return;
    }

    char inputUsername[30];
    char inputPassword[30];

    printf("\n--- LOGIN ---\n");
    printf("Username: ");
    fgets(inputUsername, sizeof(inputUsername), stdin);
    inputUsername[strcspn(inputUsername, "\n")] = '\0';

    printf("Password: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "\n")] = '\0';


    if (strcmp(inputUsername, currentUser.username) == 0 && strcmp(inputPassword, currentUser.password) == 0) {
        printf("Login berhasil! Selamat datang, %s.\n", currentUser.username);
        isLoggedIn = 1;


        printf("\nSelamat datang Sang Atmin!.\n");
        menuMasuk(0);

    } else {
        printf("Username atau password salah. Coba lagi.\n");
    }
}
