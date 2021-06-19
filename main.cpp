#include <bits/stdc++.h>
#include <conio.h>
#include "film.h"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER 13
#define BACKSPACE 8

using namespace std;

int c;
vector<Film> vFilm;

void beliTiket() {
	int index = 1;
	for(;;){
		system("cls");
		printAllFilm(vFilm, index);
		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 1)
					index = vFilm.size();
				break;
			case ARROW_DOWN:
				if(index++ == vFilm.size())
					index = 1;
				break;
			case BACKSPACE:
				return;
		}
	}
}

void mainMenu() {
	int index = 1;
	for(;;) {
		system("cls");
		cout << ( index == 1 ? "[1]" : " 1 " ) << "Cek Jadwal Film" << endl;
		cout << ( index == 2 ? "[2]" : " 2 " ) << "Beli Tiket Film" << endl;
		cout << ( index == 3 ? "[3]" : " 3 " ) << "Riwayat Pembelian" << endl;
		cout << ( index == 4 ? "[4]" : " 4 " ) << "Top Up Saldo" << endl;
		cout << ( index == 5 ? "[5]" : " 5 " ) << "Exit" << endl;
		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 1)
					index = 5;
				break;
			case ARROW_DOWN:
				if(index++ == 5)
					index = 1;
				break;
			case ENTER:
				switch(index) {
					case 1:
						system("cls");
						printAllFilm(vFilm);
						system("pause");
						break;
					case 2:
						beliTiket();
						break;
					case 5:
						return;
				}
				break;
		}
	}
}
int main()
{
	string namaFilm[] = {"A", "B", "C"};
	for(int i = 0; i < sizeof(namaFilm)/sizeof(namaFilm[0]); i++){
		Film film(vFilm.size()+1, namaFilm[i], 120, "bla");
		vFilm.push_back(film);
	}
	mainMenu();
	return 0;
}
