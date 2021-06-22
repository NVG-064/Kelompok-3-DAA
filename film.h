#include <bits/stdc++.h>

using namespace std;

#ifndef FILM_H
#define FILM_H

class Film {
	public:
	int id;
	string namaFilm;
	int durasi;
	string sinopsis;
	vector< vector<bool> > kursi;

	Film(){}
	Film(int id, string namaFilm, int durasi, string sinopsis) : kursi(5, vector<bool> (5, false)){
        this->id = id;
		this->namaFilm = namaFilm;
        this->durasi = durasi;
        this->sinopsis = sinopsis;
	}
	print(){
		cout << "ID: " << this->id << endl;
        cout << "Nama Film: " << this->namaFilm << endl;
        cout << "Durasi: " << this->durasi << endl;
        cout << "Sinopsis: " << this->sinopsis << endl;
	}
    printKursi(){
        for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				cout << "["<< (char)( this->kursi[i][j] == true ? 'X' : i+'A' ) << (char)( this->kursi[i][j] == true ? 'X' : j+'1' ) << "] ";
			}
            cout << endl;
		}
    }
    printKursi(int index1, int index2){
        for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				cout << ( i == index1 && j == index2 ? "[" : " ") << (char)( this->kursi[i][j] == true ? 'X' : i+'A' ) << (char)( this->kursi[i][j] == true ? 'X' : j+'1' ) << ( i == index1 && j == index2 ? "]" : " ");
			}
            cout << endl;
		}
    }
};

template <typename V>
void printAllFilm(V& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << endl;
        v.at(i).print();
        cout << endl;
    }
}
template <typename V>
void printAllFilm(V& v, int index) {
    for (int i = 0; i < v.size(); i++) {
        cout << ( index == i ? "\\/ \\/ \\/ \\/ \\/" : "" ) << endl;
        v.at(i).print();
        cout << ( index == i ? "/\\ /\\ /\\ /\\ /\\" : "" ) << endl;
    }
    cout << '\n';
}

#endif
