#include "header.h"

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

void success(){
	system("cls");
	cout << "\t\t\t\t\t\t                 ```.`                  " << endl;
	cout << "\t\t\t\t\t\t           `:oydmNNNNNNmdyo/`       ..  " << endl;
	cout << "\t\t\t\t\t\t        .odNNNmhso++++oshmNNN/    -oss/ " << endl;
	cout << "\t\t\t\t\t\t      -hNNNy/.            ./:   -osss/  " << endl;
	cout << "\t\t\t\t\t\t    `yNNm+`                   -ossso.   " << endl;
	cout << "\t\t\t\t\t\t   -mNNs`                   -ossss:     " << endl;
	cout << "\t\t\t\t\t\t  -mNN/                   -ossss+`      " << endl;
	cout << "\t\t\t\t\t\t  dNN+                  -osssso-   sds  " << endl;
	cout << "\t\t\t\t\t\t :NNm  .//-`          -osssss/`    dNN/ " << endl;
	cout << "\t\t\t\t\t\t oNNs  .oooo+:.     -ossssso.      sNNs " << endl;
	cout << "\t\t\t\t\t\t oNNs   `/oooooo/-:ossssss:        sNNs " << endl;
	cout << "\t\t\t\t\t\t :NNm     .+ooosssssssss+`         dNN/ " << endl;
	cout << "\t\t\t\t\t\t  dNN+      :oossssssso-          /NNd  " << endl;
	cout << "\t\t\t\t\t\t  -mNN/      `+ssssss/`          :NNN-  " << endl;
	cout << "\t\t\t\t\t\t   -mNNo`      -osso.          `oNNm:   " << endl;
	cout << "\t\t\t\t\t\t    .yNNm+`      ``          `+mNNh.    " << endl;
	cout << "\t\t\t\t\t\t      :hNNmy/.            `/ymNNh:      " << endl;
	cout << "\t\t\t\t\t\t        -odNNNmhso+//+oshmNNNds-        " << endl;
	cout << "\t\t\t\t\t\t           ./ohdNNNNNNNNdhs/.           " << endl;
	cout << "\t\t\t\t\t\t                 `....`                 " << endl;
	cout << "\n\t\t\t\t\t\t\t     Pembelian Berhasil\n" << endl;
	system("pause");
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
		cout << "\n\t\t\t\t\t\t     Apakah Anda yakin?\n" << endl;
		cout << "\t\t\t\t\t" << ( index == 1 ? "[1]" : " 1 " ) << " Ya" << endl;
		cout << "\t\t\t\t\t" << ( index == 2 ? "[2]" : " 2 " ) << " Tidak" << endl;

		if(navigate(&index, 1, 2))
			continue;
		
		switch(c) {
			case BACKSPACE:
				return false;
			case ENTER:
				if(index){
					success();
					return true;
				}
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
		cout << "\t\t\t\t\t\t      -::::::.      " << endl;
		cout << "\t\t\t\t\t\t     o-``  ``:/     " << endl;
		cout << "\t\t\t\t\t\t     y ss`-o+ y     " << endl;
		cout << "\t\t\t\t\t\t     y ``  `  y     " << endl;
		cout << "\t\t\t\t\t\t ----y +o`.+/ y---- " << endl;
		cout << "\t\t\t\t\t\t`o:/+y -- `-. d//:o " << endl;
		cout << "\t\t\t\t\t\t ``h/+::::::::+/y`  " << endl;
		cout << "\t\t\t\t\t\t   o//:------:/+/   " << endl;
		cout << "\t\t\t\t\t\t    ys```````:+s    " << endl;
		cout << "\t\t\t\t\t\t    ys       :+s    " << endl;
		cout << "\t\t\t\t\t\t    :/       `/-    " << endl << endl;
                                   
		cout << "\t\t\t\t\t\t    Pilih Kursi" << endl << endl;
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
						cout << "\t\t\t\t``````````hMhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdMs``````````" << endl << endl;
						cout << "\t\t\t\t                   Saldo tidak mencukupi" << endl;
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
		cout << "\t\t\t\t\t\t     ohmNMMNmho     " << endl;
		cout << "\t\t\t\t\t\t   dMms .MM. smMd:  " << endl;
		cout << "\t\t\t\t\t\t yMm/   .MM.   /mMy " << endl;
		cout << "\t\t\t\t\t\tsMm`    .MM.    `mMs" << endl;
		cout << "\t\t\t\t\t\tNM+     .MM-     +MN" << endl;
		cout << "\t\t\t\t\t\tNM+     `dMNs-   +MN" << endl;
		cout << "\t\t\t\t\t\tsMm`      .omMd``mMs" << endl;
		cout << "\t\t\t\t\t\t yMm/         `/mMy " << endl;
		cout << "\t\t\t\t\t\t  :dMms/-..-/smMd:  " << endl;
		cout << "\t\t\t\t\t\t     ohmNMMNmho     " << endl << endl;
		cout << "\t\t\t\t\t\t Pilih Jadwal Film" << endl << endl;
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
		cout << "   sssss            Ms                                   hh        nhssyys             yy                               " << endl;
		cout << "  mm        sssyo   Ms  ossyyo    yosysyysyy    sssyso  OMysO      Mo    sN   sssyyo  OMdsO  sssyyo   ysosyo    osso    " << endl;
		cout << "   ydhs    No   my  Ms      oM   Nh   Nd   dm       Nh   Ms        Mo     Nh      hN   Ny        dm  oM    Ms  oo  yo   " << endl;
		cout << "      oN   Msoooso  Ms   hssyM   Ns   mh   yN   hssoNd   Ms        Mo     My  hysohN   Ny    hysodN  oM    Ns  os  so   " << endl;
		cout << "       Nh  No       Ms  Ms  sM   Ns   mh   yN  dd   md   Mo        My    my  Ms   hN   mh   Ms   dN  oM    Ns   ossso   " << endl;
		cout << "   sssss    ossoo   Ms   ssoso   Ns   mh   yN   ososoo    sss      oooooo     osssso    sss  osssoo  os    os      oo   " << endl;
		cout << "                                                                                                                osso    " << endl;
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

