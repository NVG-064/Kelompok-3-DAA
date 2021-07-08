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

void printAllFilm(vector<Film> v, int index) {
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

void printAllPembelian(vector<Pembelian> v) {
	cout << "\t\t\t\t\t\t           `:oydmNMMMMNmdyo:`           " << endl;
	cout << "\t\t\t\t\t\t`````   -odMMMMMMMMMMMMMMMMMMds-        " << endl;
	cout << "\t\t\t\t\t\tMMMMs`+dMMMMMMdyo+/::/+oydMMMMMMd+`     " << endl;
	cout << "\t\t\t\t\t\tMMMMdmMMMMNy:`    ````    `:yNMMMMm/    " << endl;
	cout << "\t\t\t\t\t\tMMMMMMMMm+`      /MMMM/      `+mMMMMy`  " << endl;
	cout << "\t\t\t\t\t\tMMMMMMMy....`    /MMMM/        `sMMMMd. " << endl;
	cout << "\t\t\t\t\t\tMMMMMMMMMMMMo    /MMMM/          /MMMMh " << endl;
	cout << "\t\t\t\t\t\tMMMMMMMMMMMMo    /MMMM/           oMMMM/" << endl;
	cout << "\t\t\t\t\t\t------------.    /MMMM/           `mMMMd" << endl;
	cout << "\t\t\t\t\t\t....`            /MMMM/            yMMMM" << endl;
	cout << "\t\t\t\t\t\tMMMMy            /MMMMNh/`         yMMMM" << endl;
	cout << "\t\t\t\t\t\tdMMMm`           `/hMMMMMNy:`     `mMMMd" << endl;
	cout << "\t\t\t\t\t\t/MMMMo              `+dMMMMMNy-   oMMMM/" << endl;
	cout << "\t\t\t\t\t\t hMMMM/                .omMMMy.  /MMMMh " << endl;
	cout << "\t\t\t\t\t\t `dMMMMs`                 -o:  `sMMMMd` " << endl;
	cout << "\t\t\t\t\t\t  `yMMMMm+`                  `+mMMMMy`  " << endl;
	cout << "\t\t\t\t\t\t    /mMMMMNy:`            `:yNMMMMm/    " << endl;
	cout << "\t\t\t\t\t\t     `/dMMMMMMmyo+/::/+oymMMMMMMd+`     " << endl;
	cout << "\t\t\t\t\t\t        -sdMMMMMMMMMMMMMMMMMMds-        " << endl;
	cout << "\t\t\t\t\t\t           `:oydmNMMMMNmdyo:`           " << endl << endl;

	if (v.empty() == false){
		for (int i = 0; i < v.size(); i++) {
			v.at(i).print();
			cout << endl;
		}
	}
	else cout << "Tidak ada riwayat pembelian\n" << endl;
}



const int HARGA = 35000;
int c;
vector<User> daftarUser;
vector<Film> daftarFilm;
vector<Pembelian> daftarPembelian;
User *currentUser;
Pembelian pembelian;

bool navigate(int *index, int min, int max){
	c = getch();
	if (!c || c == 224) {
		switch(c = getch()) {
			case ARROW_UP:
				if((*index)-- == min)
					*index = max;
				break;
			case ARROW_DOWN:
				if((*index)++ == max)
					*index = min;
				break;
		}
		return true;
	}
	return false;
}

bool navigate(int *index1, int *index2, int min1, int max1, int min2, int max2){
	c = getch();
	if (!c || c == 224) {
		switch(c = getch()) {
			case ARROW_UP:
				if((*index1)-- == min1)
					*index1 = max1;
				break;
			case ARROW_DOWN:
				if((*index1)++ == max1)
					*index1 = min1;
				break;
			case ARROW_LEFT:
				if((*index2)-- == min2)
					*index2 = max2;
				break;
			case ARROW_RIGHT:
				if((*index2)++ == max2)
					*index2 = min2;
				break;
		}
		return true;
	}
	return false;
}

bool confirmMenu(){
	int index = 1;

	for (;;){
		system("cls");
		cout << "\t\t\t\t````````````````````````````.++:````````````````````````````" << endl;
		cout << "\t\t\t\t```````````````````````````oMdhMh.``````````````````````````" << endl;
		cout << "\t\t\t\t``````````````````````````yMy--oNd.`````````````````````````" << endl;
		cout << "\t\t\t\t````````````````````````.dMo----+Nm-````````````````````````" << endl;
		cout << "\t\t\t\t```````````````````````-mN+------/mN/```````````````````````" << endl;
		cout << "\t\t\t\t``````````````````````:Nm/--/oo+:-:dN+``````````````````````" << endl;
		cout << "\t\t\t\t`````````````````````+Nd:--oMMMMm--:hMo`````````````````````" << endl;
		cout << "\t\t\t\t````````````````````sMh:---oMMMMN----yMy.```````````````````" << endl;
		cout << "\t\t\t\t``````````````````.yMy-----/MMMMd-----sNh.``````````````````" << endl;
		cout << "\t\t\t\t`````````````````.dNo-------MMMMy------+Nm-`````````````````" << endl;
		cout << "\t\t\t\t````````````````:mN+--------mMMMs-------/mm:````````````````" << endl;
		cout << "\t\t\t\t```````````````/Nm/---------hMMM+--------/mN/```````````````" << endl;
		cout << "\t\t\t\t``````````````oNd:----------/yhs----------:hNo``````````````" << endl;
		cout << "\t\t\t\t`````````````sMy:-----------+yhy/----------:yMs`````````````" << endl;
		cout << "\t\t\t\t```````````.hMs------------+MMMMN------------sMh.```````````" << endl;
		cout << "\t\t\t\t``````````.dNo-------------:ymNdo-------------oNd.``````````" << endl;
		cout << "\t\t\t\t``````````mM/----------------::----------------+Md``````````" << endl;
		cout << "\t\t\t\t``````````hMhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdMs``````````" << endl;
		cout << "\n\t\t\t\t\t\tApakah Anda yakin?\n" << endl;
		cout << "\t\t\t\t\t" << ( index == 1 ? "[1]" : " 1 " ) << " Ya" << endl;
		cout << "\t\t\t\t\t" << ( index == 2 ? "[2]" : " 2 " ) << " Tidak" << endl;

		if(navigate(&index, 1, 2))
			continue;
		
		switch(c) {
			case BACKSPACE:
				return false;
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
		cout << " Total: Rp. " << formatNumber(totalHarga) << endl;
		
		if(navigate(&index1, &index2, 0, jadwalFilm.kursi.size(), 0, jadwalFilm.kursi.at(0).size()-1))
			continue;

		switch(c){
			case BACKSPACE:
				return;
			case ENTER:
				if(index1 != jadwalFilm.kursi.size()){
					if(!jadwalFilm.kursi[index1][index2]){
						kursiDibeli += getSeatNumber(index1, index2, false) + " ";
						jadwalFilm.kursi[index1][index2] = true;
						totalHarga += HARGA;
					}
				} else {
					if(currentUser->saldo < totalHarga){
						cout << "Saldo tidak mencukupi" << endl;
						system("pause");
						break;
					}
					if(!confirmMenu())
						break;
					
					pJadwalFilm->kursi = jadwalFilm.kursi;
					pembelian.id = daftarPembelian.size()+1;
					pembelian.kursiDibeli = kursiDibeli;
					pembelian.totalHarga = totalHarga;
					daftarPembelian.push_back(pembelian);
					
					currentUser->saldo -= totalHarga;

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

		if(navigate(&index, 0, film->jadwalFilm.size()-1))
			continue;

		switch(c){
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
		cout << "\t\t\t\t\t\t+hhhhhhhhhhhhhhhhhh+" << endl;
		cout << "\t\t\t\t\t\t.sMd:hMs:NM/+Mm:yMy." << endl;
		cout << "\t\t\t\t\t\tyMhyyyNMhyyhMNyyyhMy" << endl;
		cout << "\t\t\t\t\t\thM`   dN    Nd   `Mh" << endl;
		cout << "\t\t\t\t\t\thM`   dN    Nd   `Mh" << endl;
		cout << "\t\t\t\t\t\thM`   dN    Nd   `Mh" << endl;
		cout << "\t\t\t\t\t\tyMhhhhNMhhhhMNhhhhMy" << endl;
		cout << "\t\t\t\t\t\t.sMd:hMs:NM/+Mm:yMy." << endl;
		cout << "\t\t\t\t\t\t+hhhyhhhyhhyhhhyhhh+" << endl << endl;
		cout << "\t\t\t\t\t\t     Pilih Film" << endl << endl;
		printAllFilm(daftarFilm, index);

		if(navigate(&index, 0, daftarFilm.size()-1))
			continue;

		switch(c){
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

		cout << "\t\t\t\tMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
		cout << "\t\t\t\tMMMMM/oooooooooooooooooooooooooooooooooooooooooooooooo/MMMMM" << endl;
		cout << "\t\t\t\tMMmh/oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo/hmMM" << endl;
		cout << "\t\t\t\tMN hNMMMMMMMMMMMMMMMMMMMms+:-..-:+smMMMMMMMMMMMMMMMMMMMNh NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMMMMNo.            .oNMMMMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMMMh+/////:`         `sMMMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMM+:MMsssyMM/          +MMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMh :MM`  `dMo sNhddNh:  hMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMM/ :MMmmmMMh  yMy  .NM. /MMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMM/ :MM`  `mM+ yMs  `NM- /MMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMh :MM`   sMy yMmhhNm+  hMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMM+           yMo ``   +MMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMMMs`         :/-    `yMMMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN`MMMMMMMMMMMMMMMMMMNo.            .oNMMMMMMMMMMMMMMMMMM`NM" << endl;
		cout << "\t\t\t\tMN hNMMMMMMMMMMMMMMMMMMMmy+:-..-:+ymMMMMMMMMMMMMMMMMMMMNh NM" << endl;
		cout << "\t\t\t\tMMmh/oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo/hmMM" << endl;
		cout << "\t\t\t\tMMMMM/oooooooooooooooooooooooooooooooooooooooooooooooo/MMMMM" << endl;
		cout << "\t\t\t\tMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
		cout << "\n========================================================================================================================\n\n";
		cout << "\t\t\t\t\t\t\tTOP UP SALDO\n" << endl; 
		cout << "\t\t\t\t\t" << (index == 1 ? "[1]" : " 1 ") << " Top Up Rp. 10,000 (bonus Rp. 2,000)" << endl;
		cout << "\t\t\t\t\t" << (index == 2 ? "[2]" : " 2 ") << " Top up Rp. 20,000 (bonus Rp. 4,000)" << endl;
		cout << "\t\t\t\t\t" << (index == 3 ? "[3]" : " 3 ") << " Top up Rp. 40,000 (bonus Rp. 16,000)" << endl;
		cout << "\t\t\t\t\t" << (index == 4 ? "[4]" : " 4 ") << " Masukkan nominal sendiri" << endl << endl;
		cout << "\t\t\t\t\t" << (index == 5 ? "[5]" : " 5 ") << " Kembali" << endl;

		if(navigate(&index, 1, 5))
			continue;
		
		switch(c){
			case ENTER:
				if(index < 4  && confirmMenu()) {
					switch(index){
						case 1:
							currentUser->saldo += 12000;
							break;
						case 2:
							currentUser->saldo += 24000;
							break;
						case 3:
							currentUser->saldo += 56000;
							break;
					}
					return;
				} else {
					switch(index){
						case 4:
							system("cls");
							cout << "HARAP DIPERHATIKAN. TIDAK ADA BONUS UNTUK PILIHAN INI!\n" << endl;
							cout << "Masukkan jumlah top up: ";
							cin >> input;
							if(confirmMenu()){
								currentUser->saldo += input;
								return;
							}
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
		cout << "\nSelamat datang, " << currentUser->username << ". kamu mendapatkan bonus Rp. 35,000 sebagai pengguna baru :) ";
		currentUser->saldo = 35000;
		getch();
	}
	int index = 1;
	time_t timeNow;
	tm *tmN;
	for(;;) {
		system("cls");

		time(&timeNow);
		tmN = localtime(&timeNow);
		int hour = tmN->tm_hour;
		int min = tmN->tm_min;

		cout << "========================================================================================================================\n";
		cout << "========================================================================================================================\n\n";
		cout << "\t\t\t\thhhhhhyyhhhhhhh" << endl;
		cout << "\t\t\t\thhhhy-  `/hhhhh" << endl;
		cout << "\t\t\t\thhhh+     yhhhh" << "\t\tSelamat " << getTimeState(hour) << ", " << currentUser->username << endl;
		cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\tSekarang pukul " << hour << ":" << min << endl;
		cout << "\t\t\t\thh+.`.-:-.`.+hh" << endl;
		cout << "\t\t\t\thy           yh" << "\t\tSaldo kamu Rp. " << fixed << formatNumber(currentUser->saldo) << endl;
		cout << "\t\t\t\tho           oh" << endl;
		cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;
		cout << "========================================================================================================================\n";
		cout << "========================================================================================================================\n\n";
		cout << "\t\t\t\t\t\t\tMAIN MENU\n" << endl;
		cout << "\t\t\t\t\t\t" << ( index == 1 ? "[1]" : " 1 " ) << "Beli Tiket Film" << endl;
		cout << "\t\t\t\t\t\t" << ( index == 2 ? "[2]" : " 2 " ) << "Riwayat Pembelian" << endl;
		cout << "\t\t\t\t\t\t" << ( index == 3 ? "[3]" : " 3 " ) << "Top Up Saldo" << endl << endl;
		cout << "\t\t\t\t\t\t" << ( index == 4 ? "[4]" : " 4 " ) << "Logout" << endl;
		
		if(navigate(&index, 1, 4))
			continue;
		
		switch(c){
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
	system("pause");
}

void signUp() {
	int index1 = 0;
	int index2 = 0;
	string username, password, pwMask;
	for(;;){
		system("cls");

		pwMask.resize(password.size(), '*');
		string *s = (!index1 ? &username : &password);

		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\thhhhhhyyhhhhhhh" << "\t\t\t" << "SIGN UP" << endl;
		cout << "\t\t\t\thhhhy-  `/hhhhh" << endl;
		cout << "\t\t\t\thhhh+     yhhhh" << "\t\t" << " Masukkan Username: " << username << (!index1 ? "_" : " ") << endl;
		cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\t" << " Masukkan Password: " << pwMask << (index1 ? "_" : " ") << endl;
		cout << "\t\t\t\thh+.`.-:-.`.+hh" << endl;
		cout << "\t\t\t\thy           yh" << "\t\t" << (!index2 ? "[Register]\t Exit " : " Register \t[Exit]") << endl;
		cout << "\t\t\t\tho           oh" << "\t\t" << endl;
		cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;

		if(navigate(&index1, &index2, 0, 1, 0, 1))
			continue;

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

		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\thhhhhhyyhhhhhhh" << endl;
		cout << "\t\t\t\thhhhy-  `/hhhhh" << "\t\t\t" << "LOGIN" << endl;
		cout << "\t\t\t\thhhh+     yhhhh" << endl;
		cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\t" << " Username: " << username << (!index1 ? "_" : " ") << endl;
		cout << "\t\t\t\thh+.`.-:-.`.+hh" << "\t\t" << " Password: " << pwMask << (index1 ? "_" : " ") << endl;
		cout << "\t\t\t\thy           yh" << endl;
		cout << "\t\t\t\tho           oh" << "\t\t" << (!index2 ? "[Login]\t Exit " : " Login \t[Exit]") << endl;
		cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;

		if(navigate(&index1, &index2, 0, 1, 0, 1))
			continue;
			
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
	User user("1", "1");
	daftarUser.push_back(user);
}

int main() {
	setupDummy();

	int index = 1;
	for (;;){
		system("cls");
		cout << "========================================================================================================================" << endl;
		cout << "..odysyh:....---....Ms...----.......--...---.....---....:h:.......:Nhssyys:-...----...-y+.....---.......---.....---....." << endl;
		cout << "..mm:-....-/sssyo-..Ms..ossyyo-.-y+osys:+syy:../sssys:.+yMys+...../Mo...-sN+.-sssyy/.:sMdso.:sssyy/../y/osyo-.-/sssyyo-." << endl;
		cout << "../ydhs/-./No::/my..Ms../:::oM/.-Nh:-:Nd/--dm..::::/Nh.-+M+--...../Mo....-Nh.-/:::hN--:Ny--.-/:::dm..oMo--:Ms.:Mo--yN-.." << endl;
		cout << "....-:oNh.yMsoooso..Ms.-shssyM+.-Ns...mh...yN.-+hssoNd../M+......./Mo..../My.:hysohN-.-Ny.../hysodN..oM:..-Ny.-Nhoohy-.." << endl;
		cout << ".-o///+Nh./No:-:/:..Ms./Ms-:sM+.-Ns...mh...yN.-dd::/md..:Mo--...../My//+smy-.sM/-/hN-.-mh::.yN/-/dN..oM:..-Ny./Nysso/-.." << endl;
		cout << ".-+ssss/-.-:ossoo:..o/.-+sso/o:.-o/...++.../o..:oso+++..-+ss/.....-ooooo/:-..-oss+/o-../ss+.-oss+/o..:s-..-o/.oN+///dh.." << endl;
		cout << "..............................................................................................................+dyssyd+.." << endl;
		cout << "========================================================================================================================" << endl;
		cout << endl;

		cout << "\t\t\t\thhhhhhyyhhhhhhh" << endl;
		cout << "\t\t\t\thhhhy-  `/hhhhh" << endl;
		cout << "\t\t\t\thhhh+     yhhhh" << "\t\t" << (index == 1 ? "[1]" : " 1 ") << " Login" << endl;
		cout << "\t\t\t\thhhhs:.../yhhhh" << "\t\t" << (index == 2 ? "[2]" : " 2 ") << " Sign Up" << endl;
		cout << "\t\t\t\thh+.`.-:-.`.+hh" << endl;
		cout << "\t\t\t\thy           yh" << "\t\t" << (index == 3 ? "[3]" : " 3 ") << " Exit" << endl;
		cout << "\t\t\t\tho           oh" << endl;
		cout << "\t\t\t\thhhhhhhhhhhhhhh" << endl << endl;
		
		if(navigate(&index, 1, 3))
			continue;
		
		switch (c){
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

