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

void pilihKursi(Film* pFilm) {
	Film film = *pFilm;
	int index1 = 0;
	int index2 = 0;
	int jumlahKursi = 0;
	for(;;){
		system("cls");
		film.printKursi(index1, index2);
		cout << endl;
		cout << ( index1 == film.kursi.size() ? "[Buy]" : " Buy " ) << endl;
		cout << " Total: Rp. " << 50000 * jumlahKursi << endl;
		switch(c = getch()){
			case ARROW_UP:
				if(index1-- == 0)
					index1 = film.kursi.size();
				break;
			case ARROW_DOWN:
				if(index1++ == film.kursi.size())
					index1 = 0;
				break;
			case ARROW_LEFT:
				if(index2-- == 0)
					index2 = film.kursi.at(0).size()-1;
				break;
			case ARROW_RIGHT:
				if(index2++ == film.kursi.at(0).size()-1)
					index2 = 0;
				break;
			case BACKSPACE:
				return;
			case ENTER:
				if(index1 != film.kursi.size()){
					if(!film.kursi.at(index1).at(index2)){
						film.kursi.at(index1).at(index2)= true;
						jumlahKursi++;
					}
				}
				break;
		}
	}
}
void beliTiket() {
	int index = 0;
	for(;;){
		system("cls");
		printAllFilm(vFilm, index);
		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 0)
					index = vFilm.size()-1;
				break;
			case ARROW_DOWN:
				if(index++ == vFilm.size()-1)
					index = 0;
				break;
			case BACKSPACE:
				return;
			case ENTER:
				pilihKursi(&vFilm.at(index));
				break;
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
