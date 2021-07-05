//LSUP
//Login and Sign Up Page

#include <iostream>
#include <conio.h>

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER 13
#define BACKSPACE 8

using namespace std;

struct dataPribadi{
    string nama;
    string password;
    int curr;
}d;

struct administrator{
    string nama = "admin";
    string password = "admin";
}admin;

int c;

void signUp(){
    system("cls");
    //cin.ignore();
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
    int index = 1;
    string nama, password;
    for (;;){
        system("cls");
        cout << "******************************************************************************************************************************************************" << endl;
        cout << "**************************%@**************************************************************************************************************************" << endl;
        cout << "*****@@***/@**************%@*******************************************%@***********@@***/@@@****************@(***************************************" << endl;
        cout << "****%@&*********/@@@@@****%@****@@@@@@****@@*@@@@/*#@@@@*****@@@@@@***@@@@@@********@@******@@****@@@@@@***@@@@@@***@@@@@@****#@*@@@@@*****@@@@@@@%***" << endl;
        cout << "******&@@@%****@@*****@#**%@*********@@***@@*****@@****@@*********@@***%@***********@@*******@@********@@****@(**********@@***#@#****@@***@&****@*****" << endl;
        cout << "**********&@@**@@&&&&&&/**%@****@@@@@@@***@@*****@&****@@***(@@@@@@@***%@***********@@******#@(***@@@@@@@****@(*****@@@@@@@***#@*****@@***%@@#@@@*****" << endl;
        cout << "****@*****&@#**@@*********%@***@@****@@***@@*****@&****@@***@&****@@***#@/**********@@*****@@/***@@****@@****@&****@@****@@***#@*****@@**/@%**********" << endl;
        cout << "******&@@%*******/@@@#****/&*****@@%*/&***(&*****&/****%%****(@@(*%#*****&@%********#%%%(*********/@@#*#%*****&@&****&@&**&****&*****%%**/@(****@@****" << endl;
        cout << "*****************************************************************************************************************************************%@@/**@@@****" << endl;
        cout << "******************************************************************************************************************************************************" << endl;
        cout << "******************************************************************************************************************************************************" << endl << endl << endl;
        cout << "\t\t\t\t\thhhhhhyyhhhhhhh" << endl;
        cout << "\t\t\t\t\thhhhy-  `/hhhhh" << endl;
        cout << "\t\t\t\t\thhhh+     yhhhh" << "\t\t" << (index == 1 ? "[1]" : " 1 ") << " Login" << endl;
        cout << "\t\t\t\t\thhhhs:.../yhhhh" << "\t\t" << (index == 2 ? "[2]" : " 2 ") << " Sign Up" << endl;
        cout << "\t\t\t\t\thh+.`.-:-.`.+hh" << endl;
        cout << "\t\t\t\t\thy           yh" << "\t\t" << (index == 3 ? "[3]" : " 3 ") << " Exit" << endl;
        cout << "\t\t\t\t\tho           oh" << endl;
        cout << "\t\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;
        //cout << (index == 1 ? "[1]" : " 1 ") << " Login";
        //cout << (index == 2 ? "[2]" : " 2 ") << " Sign Up";
        //cout << (index == 3 ? "[3]" : " 3 ") << " Exit";

        switch (c = getch()){
            case ARROW_UP:
            if (index-- == 1){
                index = 3;
            }
            break;

            case ARROW_DOWN:
            if (index++ == 3){
                index = 1;
            }
            break;

            case ENTER:
                switch (index){

                    case 1:
                    //cin.ignore();
                    system("cls");

                    cout << "\n\n\tLOGIN";
                    cout << "\n\nNama: ";
                    getline(cin, nama);

                    cout << "Password: ";
                    getline(cin, password);

                    if ((nama == d.nama) && (password == d.password)){
                        cout << "\nLogin berhasil! Tekan apapun untuk melanjutkan.";
                        getch();
                        system("cls");
                        cout << "\nSelamat datang " << d.nama << ". kamu mendapatkan bonus 10 koin sebagai pengguna baru :) ";
                        d.curr = 10;
                        getch();
                        break;
                    }

                    else if ((nama != d.nama) && (password == d.password)){
                        cout << "\nNama atau password salah!";
                        getch();
                        break;
                    }

                    else if ((nama == d.nama) && (password != d.password)){
                        cout << "\nNama atau password salah!";
                        getch();
                        break;
                    }

                    else if ((nama == admin.nama) && (password == admin.password)){
                        cout << "\nAnda login sebagai ADMIN.\nJika ini merupakan kesalahan, segera Logout.";
                        getch();
                        break;
                    }

                    else {
                        cout << "\nAkun tidak ditemukan! Kamu akan berpindah ke laman Sign Up.\nTekan apa saja untuk melanjutkan.";
                        getch();
                    }



                    case 2:
                    signUp();
                    break;



                    case 3:
                    return;
                }
        }
    }
    
}

int main(){
    mainPage();
}