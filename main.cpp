#include <bits/stdc++.h>
#include <conio.h>
#include "film.h"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER 13

using namespace std;

vector<Film> vFilm;

void printAllFilm(vector<Film> arr) {
	system("cls");
	for(int i = 0; i < arr.size(); i++){
		arr[i].print();
		cout << "---------------" << endl;
	}
}

void mainMenu() {
	int n;
	int index = 1;
	do {
		system("cls");
		cout << ( index == 1 ? "[1]" : " 1 " ) << "Cek Jadwal Film" << endl;
		cout << ( index == 2 ? "[2]" : " 2 " ) << "Beli Tiket Film" << endl;
		cout << ( index == 3 ? "[3]" : " 3 " ) << "Riwayat Pembelian" << endl;
		cout << ( index == 4 ? "[4]" : " 4 " ) << "Top Up Saldo" << endl;
		cout << ( index == 5 ? "[5]" : " 5 " ) << "Exit" << endl;
		switch(n=getch()){
			case ARROW_UP:
				if(--index == 0)
					index = 5;
				break;
			case ARROW_DOWN:
				if(++index == 6)
					index = 1;
				break;
			case ENTER:
				switch(index) {
					case 1:
						printAllFilm(vFilm);
						system("pause");
						break;
					
					case 5:
						return;
				}
				break;
		}
	} while (true);
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
