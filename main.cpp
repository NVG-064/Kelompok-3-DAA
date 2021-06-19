#include <bits/stdc++.h>
#include <conio.h>
#include "film.h"

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
	do{
		system("cls");
		cout << "1. Cek Jadwal Film" << endl;
		cout << "2. Beli Tiket Film" << endl;
		cout << "3. Riwayat Pembelian" << endl;
		cout << "4. Top Up Saldo" << endl;
		cout << "5. Exit" << endl;
		switch(n=getch()){
			case '1':
				printAllFilm(vFilm);
				system("pause");
				break;
		}
	} while (n < '5');
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
