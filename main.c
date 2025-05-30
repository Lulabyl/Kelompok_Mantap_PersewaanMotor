#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username[30];
    char password[30];
} User;

User currentUser;
int isLoggedIn = 0;

void clearScreen();
void tampilanMainMenu();
void registerUser();
void loginUser();

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


void clearScreen() {
    #ifdef _WIN32
        system("cls");
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

    } else {
        printf("Username atau password salah. Coba lagi.\n");
    }
}
