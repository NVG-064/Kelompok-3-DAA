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
	int saldo;
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
		cout << "Kursi: " << this->kursiDibeli << endl;
        cout << "Total: Rp. " << this->totalHarga << endl;
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
vector<User> daftarUser;
vector<Film> daftarFilm;
vector<Pembelian> daftarPembelian;
User *currentUser;
Pembelian pembelian;

bool confirmMenu(){
	int index = 1;

	for (;;){
		system("cls");

		cout << "\n\t\t\t\t\tApakah Anda yakin?\n" << endl;
		cout << "\t\t\t\t\t" << ( index == 1 ? "[1]" : " 1 " ) << " Ya" << endl;
		cout << "\t\t\t\t\t" << ( index == 2 ? "[2]" : " 2 " ) << " Tidak" << endl;

		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 1)
					index = 2;
				break;
			case ARROW_DOWN:
				if(index++ == 2)
					index = 1;
				break;
			case ENTER:
				return index == 1;
				break;
		}
	}
	return false;
}

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

					c = !c;
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
		if(!c)
			return;
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
		if(!c)
			return;
	}
}

void topUpSaldo(){
	int input;
	int index = 1;
	for (;;){
		system("cls");

		cout << "\t\t\t\t\t  `  `` ``  `  `` `` `:/oydmNNMMMMNNmdhs+:.` `` ``  `  `` ``  `  `` ``  `  " << endl;
		cout << "\t\t\t\t\t`   `  `  `   `  `.odMMMMMMNNmh//sdmNMMMMMMmy:``  `   `  `  `   `  `  `   `" << endl;
		cout << "\t\t\t\t\t                .yMMMMMMMd:` `+sys+.-+dMMMMMMMd:                           " << endl;
		cout << "\t\t\t\t\t  `  `   `  `  `hMMMMMMMMm+-..-:/++sydNMMMMMMMMN``  `  `   `  `  `   `  `  " << endl;
		cout << "\t\t\t\t\t`` ``  `  `` `` sMMMMMMMMdhyyddhhyo  ``yMMMMMMMm` `` ``  `  `` ``  `  `` ``" << endl;
		cout << "\t\t\t\t\t  `  `   `  `  `.+mMMMMMMds/::/:::::/+yNMMMMMNs-``  `  `   `  `  `   `  `  " << endl;
		cout << "\t\t\t\t\t                hh/+sdmNMMMMMMNssdMMMMMMNNmy/:om.                          " << endl;
		cout << "\t\t\t\t\t`   `  `  `   ` :mMNhs++oosyyhhddhhyys+/:-.-:+++..`   `  `  `   `  `  `   `" << endl;
		cout << "\t\t\t\t\t  `  `   `  `  `/:odNMMMNmdhhyyyyyys/-:shmNMNNNMNmhs:. `   `  `  `   `  `  " << endl;
		cout << "\t\t\t\t\t`   `  `  `   ` yNho+oshdmNNMMMMMNs:smMMMMMNo.oNMMMMMms. `  `   `  `  `   `" << endl;
		cout << "\t\t\t\t\t                .sNMMmdyoo++++oo/:+NMMMMMy:-```-:yNMMMMN+`                 " << endl;
		cout << "\t\t\t\t\t  `  `   `  `  `ys/ohmNMMMMMNNNd.sMMMMMMo```ydy:`.sMMMMMMs``  `  `   `  `  " << endl;
		cout << "\t\t\t\t\t`   `  `  `   ` +NNdyo++osyhddd//MMMMMMM:  .hmMNhmNMMMMMMM/ `   `  `  `   `" << endl;
		cout << "\t\t\t\t\t  `  `   `  `  `::ymMMNNmdhysso`hMMMMMMMh.` `.-/sdMMMMMMMMh`  `  `   `  `  " << endl;
		cout << "\t\t\t\t\t                hms++ohdNMMMMMm dMMMMMMMMNho/.`  `/NMMMMMMd                " << endl;
		cout << "\t\t\t\t\t`   `  `  `   ` .hMMNdyo+++o+oo`sMMMMMMNmhhMMNmo  `yMMMMMMs `   `  `  `   `" << endl;
		cout << "\t\t\t\t\t  `  `` ``  `  `s+/sdMMMMNNNNmmy.mMMMMMN.``+ddd/```mMMMMMm.`  `  `` ``  `  " << endl;
		cout << "\t\t\t\t\t`   `  `  `   ` oMNho//oyhdmNMMMs-dMMMMMm+.`````./dMMMMMd-  `   `  `  `   `" << endl;
		cout << "\t\t\t\t\t                `/dMMMNmhyso++//+/-oNMMMMMNm+ +mNMMMMMNo`                  " << endl;
		cout << "\t\t\t\t\t  `  `   `  `  `  `-+hmMMMMMMMMMMMNy:/hNMMMMdydMMMMNh/``   `  `  `   `  `  " << endl;
		cout << "\t\t\t\t\t`` ``  `  `` ``  `  `` `:/+ssyyhyyyso/``:+oyyyyyo/:` ``  `  `` ``  `  `` ``" << endl;
		cout << "\n========================================================================================================================\n\n";
		cout << "\t\t\t\t\t\tTOP UP SALDO\n" << endl; 
		cout << "\t\t\t\t\t" << (index == 1 ? "[1]" : " 1 ") << " Top Up 10 koin (bonus 2 koin)" << endl;
		cout << "\t\t\t\t\t" << (index == 2 ? "[2]" : " 2 ") << " Top up 20 koin (bonus 4 koin)" << endl;
		cout << "\t\t\t\t\t" << (index == 3 ? "[3]" : " 3 ") << " Top up 40 koin (bonus 16 koin)" << endl;
		cout << "\t\t\t\t\t" << (index == 4 ? "[4]" : " 4 ") << " Pilih manual jumlah koin" << endl << endl;
		cout << "\t\t\t\t\t" << (index == 5 ? "[5]" : " 5 ") << " Kembali" << endl;

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
				if(index < 4  && confirmMenu()) {
					switch(index){
						case 1:
							currentUser->saldo += 12;
							break;
						case 2:
							currentUser->saldo += 24;
							break;
						case 3:
							currentUser->saldo += 56;
							break;
					}
				} else {
					switch(index){
						case 4:
							system("cls");
							cout << "HARAP DIPERHATIKAN. TIDAK ADA BONUS KOIN UNTUK PILIHAN INI!\n" << endl;
							cout << "Masukkan jumlah koin: ";
							cin >> input;

							currentUser->saldo += input;
							break;
						case 5:
							return;
					}
				}
				break;
		}
	}
}

void adminMenu(){
	//code here
}

void mainMenu() {
	if(currentUser->saldo == -1){
		system("cls");
		cout << "\nSelamat datang, " << currentUser->username << ". kamu mendapatkan bonus 10 koin sebagai pengguna baru :) ";
		currentUser->saldo = 10;
		getch();
	}
	int index = 1;
    time_t timeNow = time(0);
    tm *tmN = localtime(&timeNow);
    int hour = tmN->tm_hour;
    int min = tmN->tm_min;
	for(;;) {
		system("cls");
		cout << "========================================================================================================================\n";
		cout << "========================================================================================================================\n\n";
		cout << "\t\t\thhhhhhyyhhhhhhh" << endl;
        cout << "\t\t\thhhhy-  `/hhhhh" << endl;
        cout << "\t\t\thhhh+     yhhhh" << "\t\tSelamat " << getTimeState(hour) << ", " << currentUser->username << endl;
        cout << "\t\t\thhhhs:.../yhhhh" << "\t\tSekarang pukul " << hour << ":" << min << endl;
        cout << "\t\t\thh+.`.-:-.`.+hh" << endl;
        cout << "\t\t\thy           yh" << "\t\tSaldo kamu " << currentUser->saldo << " koin" << endl;
        cout << "\t\t\tho           oh" << endl;
        cout << "\t\t\thhhhhhhhhhhhhhh" << endl << endl;
		cout << "========================================================================================================================\n";
        cout << "========================================================================================================================\n\n";
		cout << "\t\t\t" << ( index == 1 ? "[1]" : " 1 " ) << "Beli Tiket Film" << endl;
		cout << "\t\t\t" << ( index == 2 ? "[2]" : " 2 " ) << "Riwayat Pembelian" << endl;
		cout << "\t\t\t" << ( index == 3 ? "[3]" : " 3 " ) << "Top Up Saldo" << endl << endl;
		cout << "\t\t\t" << ( index == 4 ? "[4]" : " 4 " ) << "Logout" << endl;
		switch(c = getch()){
			case ARROW_UP:
				if(index-- == 1)
					index = 4;
				break;
			case ARROW_DOWN:
				if(index++ == 4)
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
					case 3:
						topUpSaldo();						
						break;
					case 4:
						return;
				}
				break;
		}
	}
}

void signUp() {
	int index1 = 0;
	int index2 = 0;
    string username, password, pwMask;
	for(;;){
		system("cls");

		pwMask.resize(password.size(), '*');
		string *s = (!index1 ? &username : &password);

		cout << "\t\t\t\thhhhhhyyhhhhhhh" << "\t\t\t" << "SIGN UP" << endl;
        cout << "\t\t\t\thhhhy-  `/hhhhh" << endl;
        cout << "\t\t\t\thhhh+     yhhhh" << "\t\t" << " Masukkan Username: " << username << (!index1 ? "_" : " ") << endl;
        cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\t" << " Masukkan Password: " << pwMask << (index1 ? "_" : " ") << endl;
        cout << "\t\t\t\thh+.`.-:-.`.+hh" << endl;
        cout << "\t\t\t\thy           yh" << "\t\t" << (!index2 ? "[Register]\t Exit " : " Register \t[Exit]") << endl;
        cout << "\t\t\t\tho           oh" << "\t\t" << endl;
        cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;

		c = getch();
        if (c && c != 224) {
			switch(c) {
				case BACKSPACE:
					if (!s->empty()) 
        				s->resize(s->size() - 1);
					break;
				case ENTER:
					if(!index1) {
						index1 = !index1;
						break;
					}
					else if(index2) {
						return;
					} else {
						if(username == "admin" || checkString(username) || checkString(password)) {
							cout << "\n\t\t\t\t\tUsername/Password tidak valid";
							getch();
							break;
						}
						currentUser = findUsername(&daftarUser, username);
						if(currentUser != NULL){
							cout << "\n\t\t\t\t\tUsername sudah terpakai";
							getch();
							break;
						}
						User user(username, password);
						daftarUser.push_back(user);
    					cout << "\n\t\t\t\t\tRegistrasi berhasil";
    					getch();
						return;
					}
					break;
				default:
					*s += (char)c;
			}
        } else {
            switch(c = getch()) {
				case ARROW_UP:
					index1 = !index1;
					break;
				case ARROW_DOWN:
					index1 = !index1;
					break;
				case ARROW_LEFT:
					index2 = !index2;
					break;
				case ARROW_RIGHT:
					index2 = !index2;
					break;
            }
        }
	}
}

void login() {
	int index1 = 0;
	int index2 = 0;
    string username, password, pwMask;
	for(;;){
		system("cls");

		pwMask.resize(password.size(), '*');
		string *s = (!index1 ? &username : &password);

		cout << "\t\t\t\thhhhhhyyhhhhhhh" << "\t\t\t" << "Login" << endl;
        cout << "\t\t\t\thhhhy-  `/hhhhh" << endl;
        cout << "\t\t\t\thhhh+     yhhhh" << "\t\t" << " Username: " << username << (!index1 ? "_" : " ") << endl;
        cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\t" << " Password: " << pwMask << (index1 ? "_" : " ") << endl;
        cout << "\t\t\t\thh+.`.-:-.`.+hh" << endl;
        cout << "\t\t\t\thy           yh" << "\t\t" << (!index2 ? "[Login]\t Exit " : " Login \t[Exit]") << endl;
        cout << "\t\t\t\tho           oh" << "\t\t" << endl;
        cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;

		c = getch();
        if (c && c != 224) {
			switch(c) {
				case BACKSPACE:
					if (!s->empty()) 
        				s->resize(s->size() - 1);
					break;
				case ENTER:
					if(!index1) {
						index1 = !index1;
						break;
					}
					else if(index2) {
						return;
					} else {
						if (username == "admin" && password == "admin"){
							adminMenu(); 
							return;
						}
						currentUser = findUsername(&daftarUser, username);
						if(currentUser == NULL || username != currentUser->username || password != currentUser->password){
							cout << "\n\t\t\t\t\tUsername atau password salah!";
							getch();
							break;
						} else {
							mainMenu();
							return;
						}
					}
					break;
				default:
					*s += (char)c;
			}
        } else {
            switch(c = getch()) {
				case ARROW_UP:
					index1 = !index1;
					break;
				case ARROW_DOWN:
					index1 = !index1;
					break;
				case ARROW_LEFT:
					index2 = !index2;
					break;
				case ARROW_RIGHT:
					index2 = !index2;
					break;
            }
        }
	}
}

void setupDummy() {
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
}

int main() {
	setupDummy();

	int index = 1;
    for (;;){
        system("cls");
		cout << "========================================================================================================================\n" << endl;
        cout << "...------...........+:...................................-........--------.............--..............................." << endl;
		cout << "..odysyh:....---....Ms...----.......--...---.....---....:h:.......:Nhssyys:-...----...-y+.....---.......---.....---....." << endl;
		cout << "..mm:-....-/sssyo-..Ms..ossyyo-.-y+osys:+syy:../sssys:.+yMys+...../Mo...-sN+.-sssyy/.:sMdso.:sssyy/../y/osyo-.-/sssyyo-." << endl;
		cout << "../ydhs/-./No::/my..Ms../:::oM/.-Nh:-:Nd/--dm..::::/Nh.-+M+--...../Mo....-Nh.-/:::hN--:Ny--.-/:::dm..oMo--:Ms.:Mo--yN-.." << endl;
		cout << "....-:oNh.yMsoooso..Ms.-shssyM+.-Ns...mh...yN.-+hssoNd../M+......./Mo..../My.:hysohN-.-Ny.../hysodN..oM:..-Ny.-Nhoohy-.." << endl;
		cout << ".-o///+Nh./No:-:/:..Ms./Ms-:sM+.-Ns...mh...yN.-dd::/md..:Mo--...../My//+smy-.sM/-/hN-.-mh::.yN/-/dN..oM:..-Ny./Nysso/-.." << endl;
		cout << ".-+ssss/-.-:ossoo:..o/.-+sso/o:.-o/...++.../o..:oso+++..-+ss/.....-ooooo/:-..-oss+/o-../ss+.-oss+/o..:s-..-o/.oN+///dh.." << endl;
		cout << "..............................................................................................................+dyssyd+.." << endl;
		cout << "..............................................................................................................-------..." << endl;
		cout << "\n========================================================================================================================\n" << endl;
        cout << "\t\t\t\thhhhhhyyhhhhhhh" << endl;
        cout << "\t\t\t\thhhhy-  `/hhhhh" << endl;
        cout << "\t\t\t\thhhh+     yhhhh" << "\t\t" << (index == 1 ? "[1]" : " 1 ") << " Login" << endl;
        cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\t" << (index == 2 ? "[2]" : " 2 ") << " Sign Up" << endl;
        cout << "\t\t\t\thh+.`.-:-.`.+hh" << endl;
        cout << "\t\t\t\thy           yh" << "\t\t" << (index == 3 ? "[3]" : " 3 ") << " Exit" << endl;
        cout << "\t\t\t\tho           oh" << endl;
        cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;
        switch (c = getch()){
            case ARROW_UP:
            	if (index-- == 1)
            	    index = 3;
            	break;
            case ARROW_DOWN:
	            if (index++ == 3)
	                index = 1;
            	break;
            case ENTER:
                switch (index){
                    case 1:
						login();
						break;
                    case 2:
                    	signUp();
                    	break;
                    case 3:
                    	return 0;
				}
				break;
        }
    }
	return 0;
}
