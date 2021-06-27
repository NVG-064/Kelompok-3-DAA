#include <bits/stdc++.h>
#include <conio.h>

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER 13
#define BACKSPACE 8

using namespace std;

string getSeatNumber(int index1, int index2, bool flag){
	if(flag) return "XX";
	char a = index1+'A';
	char b = index2+'1';
	return string() + a + b;
}

class JadwalFilm {
	public:
	string jamTayang;
	vector< vector<bool> > kursi;

	JadwalFilm(){}
	JadwalFilm(string jamTayang) : kursi(5, vector<bool> (5, false)){
		this->jamTayang = jamTayang;
	}
    printKursi(int index1, int index2){
        for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				cout << ( i == index1 && j == index2 ? "[" : " ") << getSeatNumber(i, j, this->kursi[i][j]) << ( i == index1 && j == index2 ? "]" : " ");
			}
            cout << endl;
		}
    }
};

class Film {
	public:
	int id;
	string namaFilm;
	string ratingUsia;
	int durasi;
	vector<JadwalFilm> jadwalFilm;

	Film(){}
	Film(int id, string namaFilm, string ratingUsia, int durasi, vector<JadwalFilm> jadwalFilm) {
        this->id = id;
		this->namaFilm = namaFilm;
		this->ratingUsia = ratingUsia;
        this->durasi = durasi;
		this->jadwalFilm = jadwalFilm;
	}
	print(){
		cout << "ID: " << this->id << endl;
        cout << "Nama Film: " << this->namaFilm << endl;
		cout << "Rating Usia: " << this->ratingUsia << endl;
        cout << "Durasi: " << this->durasi << endl;
	}
	printJadwal(int index) {
		for (int i = 0; i < jadwalFilm.size(); i++) {
        	cout << ( index == i ? "[" : " " ) << i+1 << ( index == i ? "]" : " " ) << jadwalFilm.at(i).jamTayang << endl	;
		}
	}
};

class Pembelian {
	public:
	int id;
	string namaFilm;
	string jamTayang;
	string kursiDibeli;
	int totalHarga;
	Pembelian(){}
	print(){
		cout << "ID Pembelian: " << this->id << endl;
        cout << "Nama Film: " << this->namaFilm << endl;
		cout << "Jam Tayang: " << this->jamTayang << endl;
		cout << "Kursi dibeli: " << this->kursiDibeli << endl;
        cout << "Total Harga: " << this->totalHarga << endl;
	}
};

void printAllFilm(vector<Film> v, int index) {
    for (int i = 0; i < v.size(); i++) {
        cout << ( index == i ? "= = = = = = = = = = = = = = = = = = = =" : "" ) << endl;
        v.at(i).print();
        cout << ( index == i ? "= = = = = = = = = = = = = = = = = = = =" : "" ) << endl;
    }
    cout << '\n';
}

void printAllPembelian(vector<Pembelian> v) {
    for (int i = 0; i < v.size(); i++) {
        v.at(i).print();
        cout << endl;
    }
}



int c;
int saldo = 0;
vector<Film> daftarFilm;
vector<Pembelian> daftarPembelian;
Pembelian pembelian;

void pilihKursi(JadwalFilm* pJadwalFilm) {
	JadwalFilm jadwalFilm = *pJadwalFilm;
	pembelian.jamTayang = jadwalFilm.jamTayang;
	int index1 = 0;
	int index2 = 0;
	int totalHarga = 0;
	string kursiDibeli = "";
	for(;;){
		system("cls");
		
		cout << "Pilih Kursi" << endl << endl;
		jadwalFilm.printKursi(index1, index2);
		cout << endl;
		
		cout << ( index1 == jadwalFilm.kursi.size() ? "[Buy]" : " Buy " ) << endl << endl;

		cout << " Kursi: " << kursiDibeli << endl;
		cout << " Total: Rp. " << totalHarga << endl;
		
		switch(c = getch()){
			case ARROW_UP:
				if(index1-- == 0)
					index1 = jadwalFilm.kursi.size();
				break;
			case ARROW_DOWN:
				if(index1++ == jadwalFilm.kursi.size())
					index1 = 0;
				break;
			case ARROW_LEFT:
				if(index2-- == 0)
					index2 = jadwalFilm.kursi.at(0).size()-1;
				break;
			case ARROW_RIGHT:
				if(index2++ == jadwalFilm.kursi.at(0).size()-1)
					index2 = 0;
				break;
			case BACKSPACE:
				return;
			case ENTER:
				if(index1 != jadwalFilm.kursi.size()){
					if(!jadwalFilm.kursi[index1][index2]){
						kursiDibeli += getSeatNumber(index1, index2, false) + " ";
						jadwalFilm.kursi.at(index1).at(index2) = true;
						totalHarga += 25000;
					}
				}
				else if (index1 == jadwalFilm.kursi.size()){
					pJadwalFilm->kursi = jadwalFilm.kursi;

					pembelian.id = daftarPembelian.size()+1;
					pembelian.kursiDibeli = kursiDibeli;
					pembelian.totalHarga = totalHarga;

					daftarPembelian.push_back(pembelian);

					cout << "\nPembelian sukses!" << endl;
					system("pause");
					return;
				}
				break;
		}
	}
}

void pilihJadwal(Film* film){
	pembelian.namaFilm = film->namaFilm;
	int index = 0;
	for(;;){
		system("cls");
		cout << "Pilih Jadwal Film" << endl << endl;
		film->printJadwal(index);
		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 0)
					index = film->jadwalFilm.size()-1;
				break;
			case ARROW_DOWN:
				if(index++ == film->jadwalFilm.size()-1)
					index = 0;
				break;
			case BACKSPACE:
				return;
			case ENTER:
				pilihKursi(&film->jadwalFilm.at(index));
				break;
		}
	}
}

void beliTiket() {
	int index = 0;
	for(;;){
		system("cls");
		cout << "Pilih Film" << endl << endl;
		printAllFilm(daftarFilm, index);
		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 0)
					index = daftarFilm.size()-1;
				break;
			case ARROW_DOWN:
				if(index++ == daftarFilm.size()-1)
					index = 0;
				break;
			case BACKSPACE:
				return;
			case ENTER:
				pilihJadwal(&daftarFilm.at(index));
				break;
		}
	}
}

void mainMenu() {
	int index = 1;
	for(;;) {
		system("cls");
		cout << ( index == 1 ? "[1]" : " 1 " ) << "Beli Tiket Film" << endl;
		cout << ( index == 2 ? "[2]" : " 2 " ) << "Riwayat Pembelian" << endl;
		cout << ( index == 3 ? "[3]" : " 3 " ) << "Top Up Saldo" << endl;
		cout << ( index == 4 ? "[4]" : " 4 " ) << "Exit" << endl;
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
						beliTiket();
						break;
					case 2:
						system("cls");
						printAllPembelian(daftarPembelian);
						system("pause");
						break;
					case 4:
						return;
				}
				break;
		}
	}
}

int main()
{
	string namaFilm[] = {
		"The Lord of the Rings",
		"Inception",
		"Interstellar",
		"Joker",
		"Up"
	};
	string jadwalFilm[] = {
		"10:00",
		"13:00",
		"15:00",
		"20:00"
	};
	for(int i = 0; i < sizeof(namaFilm)/sizeof(namaFilm[0]); i++){
		vector<JadwalFilm> daftarJadwal;
		for(int j = 0; j < sizeof(jadwalFilm)/sizeof(jadwalFilm[0]); j++){
			JadwalFilm jf(jadwalFilm[j]);
			daftarJadwal.push_back(jf);
		}
		Film film(daftarFilm.size()+1, namaFilm[i], "13+", 120, daftarJadwal);
		daftarFilm.push_back(film);
	}
	mainMenu();
	return 0;
}
