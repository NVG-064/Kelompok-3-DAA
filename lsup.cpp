//LSUP
//Login and Sign Up Page

#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

struct dataPribadi{
    string nama;
    string password;
    int curr;
}d;

void signUp(){
    system("cls");
    cin.ignore();
    string nama, password;

    cout << "\n\tSIGN UP";
    cout << "\n\nMasukkan Nama: ";
    getline(cin, nama);

    cout << "Masukkan Password: ";
    getline(cin, password);

    d.nama = nama;
    d.password = password;
}

void mainPage(){
    int pil;
    do {
        system("cls");
        cout << "\n\tSELAMAT DATANG!\n\n1. Login\n2. Sign Up\n\nPilihan: ";
        cin >> pil;

        if (pil == 1){
            system("cls");
            cin.ignore();
            string nama, password;

            cout << "\n\n\tLOGIN";
            cout << "\n\nNama: ";
            getline(cin, nama);

            cout << "Password: ";
            getline(cin, password);

            if ((nama == d.nama) && (password == d.password)){
                cout << "\nLogin berhasil! Tekan apapun untuk melanjutkan.";
                getch();
                system("cls");
                cout << "\nSelamat datang " << d.nama << ". kamu mendapatkan bonus 10 koin sebagai pengguna baru";
                d.curr = 10;
                getch();
                break;
            }

            else if ((nama != d.nama) && (password == d.password)){
                cout << "\nNama atau password salah!";
                getch();
            }

            else if ((nama == d.nama) && (password != d.password)){
                cout << "\nNama atau password salah!";
                getch();
            }

            else {
                cout << "\nAkun tidak ditemukan! Silahkan sign up terlebih dahulu.";
                getch();
            }
        }

        else if (pil == 2){
            signUp();
        }
    } while ((pil > 0) && (pil < 3));
    
}

int main(){
    mainPage();
}