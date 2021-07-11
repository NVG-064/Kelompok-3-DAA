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
	JadwalFilm(string jamTayang) : kursi(9, vector<bool> (9, false)){
		this->jamTayang = jamTayang;
	}
	printKursi(int index1, int index2){
		for(int i = 0; i < kursi.size(); i++){
			cout << "\t\t\t\t\t";
			for(int j = 0; j < kursi.at(0).size(); j++){
				cout << ( i == index1 && j == index2 ? "[" : " ") << getSeatNumber(i, j, this->kursi[i][j]) << ( i == index1 && j == index2 ? "]" : " ");
			}
			cout << endl;
		}
	}
};

class Film {
	public:
	string namaFilm;
	string ratingUsia;
	string durasi;
	vector<JadwalFilm> jadwalFilm;

	Film(){}
	Film(string namaFilm, string ratingUsia, string durasi) {
		this->namaFilm = namaFilm;
		this->ratingUsia = ratingUsia;
		this->durasi = durasi;
		this->jadwalFilm.push_back(JadwalFilm("08:00"));
		this->jadwalFilm.push_back(JadwalFilm("10:15"));
		this->jadwalFilm.push_back(JadwalFilm("12:30"));
		this->jadwalFilm.push_back(JadwalFilm("15:45"));
		this->jadwalFilm.push_back(JadwalFilm("18:00"));
	}
	print(){
		cout << "\t\t\t\t\tNama Film: " << this->namaFilm << endl;
		cout << "\t\t\t\t\tRating Usia: " << this->ratingUsia << endl;
		cout << "\t\t\t\t\tDurasi: " << this->durasi << endl;
	}
	print(int index1){
		cout << "\t\t\t\t\tNama Film: " << this->namaFilm << (index1 == 0 ? "_" : " ") << endl;
		cout << "\t\t\t\t\tRating Usia: " << this->ratingUsia << (index1 == 1 ? "_" : " ") << endl;
		cout << "\t\t\t\t\tDurasi: " << this->durasi << (index1 == 2 ? "_" : " ") <<endl;
	}
	printJadwal(int index) {
		for (int i = 0; i < jadwalFilm.size(); i++) {
			cout << "\t\t\t\t\t\t" << ( index == i ? "[" : " " ) << i+1 << ( index == i ? "]" : " " ) << jadwalFilm.at(i).jamTayang << endl	;
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
		cout << "\t\t\t\t\tID Pembelian: " << this->id << endl;
		cout << "\t\t\t\t\tNama Film: " << this->namaFilm << endl;
		cout << "\t\t\t\t\tJam Tayang: " << this->jamTayang << endl;
		cout << "\t\t\t\t\tKursi: " << this->kursiDibeli << endl;
		cout << "\t\t\t\t\tTotal: Rp. " << this->totalHarga << endl;
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
	string s;
	s.resize(typeid(T).name() == typeid(Pembelian).name() ? 7 : 5, '\n');
	if (v.empty()) {
		cout << "Daftar Kosong\n" << endl;
		return;
	}
	for(int i = index - 1; i <= index+1; i++){
		if(i < 0 || i == v.size()){
			cout << s;
		} else {
			cout << ( index == i ? "\t\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = =" : "" ) << endl;
			v.at(i).print();
			cout << ( index == i ? "\t\t\t\t\t= = = = = = = = = = = = = = = = = = = = = = = =" : "" ) << endl;
		}
	}
	cout << '\n';
}

#endif // HEADER_H_INCLUDED
