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
	bool kursi[5][5];

	Film(){}
	Film(int id, string namaFilm, int durasi, string sinopsis){
        this->id = id;
		this->namaFilm = namaFilm;
        this->durasi = durasi;
        this->sinopsis = sinopsis;
        for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				this->kursi[i][j] = false;
			}
		}
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
};

template <typename V>
void printAllFilm(V& v) {
    typename V::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        cout << endl;
        ptr->print();
        cout << endl;
    }
}
template <typename V>
void printAllFilm(V& v, int index) {
    typename V::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        cout << ( index == ptr->id ? "\\/ \\/ \\/ \\/ \\/" : "" ) << endl;
        ptr->print();
        cout << ( index == ptr->id ? "/\\ /\\ /\\ /\\ /\\" : "" ) << endl;
    }
    cout << '\n';
}

#endif
