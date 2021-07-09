#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>

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

class User {
	public:
	string username;
	string password;
	long saldo;
	User(){}
	User(string username, string password) {
		this->username = username;
		this->password = password;
		this->saldo = -1;
	}
};

User *findUsername(vector<User> *v, string username) {
	for(int i = 0; i < v->size(); i++) {
		if(v->at(i).username == username) {
			return &v->at(i);
		}
	}
	return NULL;
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
		cout << "\t\t\t\t\tID: " << this->id << endl;
		cout << "\t\t\t\t\tNama Film: " << this->namaFilm << endl;
		cout << "\t\t\t\t\tRating Usia: " << this->ratingUsia << endl;
		cout << "\t\t\t\t\tDurasi: " << this->durasi << endl;
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
	long totalHarga;
	Pembelian(){}
	print(){
		cout << "ID Pembelian: " << this->id << endl;
		cout << "Nama Film: " << this->namaFilm << endl;
		cout << "Jam Tayang: " << this->jamTayang << endl;
		cout << "Kursi: " << this->kursiDibeli << endl;
		cout << "Total: Rp. " << this->totalHarga << endl;
	}
};

bool checkString(string s){
	return s.find_first_not_of(' ') == string::npos;
}

string getTimeState(int hour){
	string timeState;
	if ((hour >= 0) && (hour < 3)){
		timeState = "dini hari";
	}
	else if ((hour >= 3) && (hour < 12)){
		timeState = "pagi";
	}
	else if ((hour >= 12) && (hour < 15)){
		timeState = "siang";
	}
	else if ((hour >= 15) && (hour < 18)){
		timeState = "sore";
	}
	else if ((hour >= 18) && (hour < 24)){
		timeState = "malam";
	}
	return timeState;
}

string formatNumber(long value) {
	if (value < 1)
		return "0";
	string s = "";
	char c;
	int i = 2;
	while(value != 0){
		c = value%10+'0';
		s += c;
		value /= 10;
		if(value && !i--){
			s+=',';
			i = 2;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

template <typename T>
void printAll(vector<T> v, int index) {
	if (v.empty()) {
		cout << "Daftar Kosong\n" << endl;
		return;
	}
	for(int i = index - 1; i <= index+1; i++){
		if(i < 0 || i == v.size()){
			cout<<"\n\n\n\n\n\n";
		} else {
			cout << ( index == i ? "\t\t\t\t\t= = = = = = = = = = = = = = = = = = = =" : "" ) << endl;
			v.at(i).print();
			cout << ( index == i ? "\t\t\t\t\t= = = = = = = = = = = = = = = = = = = =" : "" ) << endl;
		}
	}
	cout << '\n';
}

#endif // HEADER_H_INCLUDED
