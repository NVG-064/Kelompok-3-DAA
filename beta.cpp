#include <iostream>
#include <ctime>

using namespace std;
        
int main(){
    time_t timeNow = time(0);
    tm *tmN = localtime(&timeNow);
    int hour = tmN->tm_hour;
    int min = tmN->tm_min;
    string greetings;
    if ((hour >= 0) && (hour < 3)){
        greetings = "dini hari";
    }

    else if ((hour >= 3) && (hour < 12)){
        greetings = "pagi";
    }

    else if ((hour >= 12) && (hour < 15)){
        greetings = "siang";
    }

    else if ((hour >= 15) && (hour < 18)){
        greetings = "sore";
    }

    else if ((hour >= 18) && (hour < 24)){
        greetings = "malam";
    }
        system("cls");
        cout << "hhhhhhyyhhhhhhh" << endl;
        cout << "hhhhy-  `/hhhhh" << endl;
        cout << "hhhh+     yhhhh" << endl;
        cout << "hhhhs:.../yhhhh" << "\t\tSelamat " << greetings << "," << " (nama_pengguna_atau_admin)" << endl;
        cout << "hh+.`.-:-.`.+hh" << "\t\tSekarang pukul " << hour << ":" << min /* << d.nama */ << endl;
        cout << "hy           yh" << endl;
        cout << "ho           oh" << endl;
        cout << "hhhhhhhhhhhhhhh" << endl;
        cout << "\n=========================================================================================\n" << endl;
        cout << "..--::-.........-o-.....................................-----......................................." << endl;
        cout << ".-dy+os.........:M-............................/d-......mhosyho-.........h+........................." << endl;
        cout << ".:Ns:-...+hssh+.:M-.ossyd:./dssyhossd+.-ysshy-/hMso.....ms...-No.+yssd/-sNhs:-ysshy-.shsshh-.ohsymy-" << endl;
        cout << "..-oydy-:MsooyN-:M-.-+ooNs.+N-.-No..yd..:+osM:.+N-......ms....dy.-/oomy..mo...:+osM:.yh..-M/.ds-:N+." << endl;
        cout << ".--..-No:M/----.:M--Ns:-ms.+N-.-N+..sd.+N/-/M:.+N-......ms..-oN/-dy:-hy..mo..+N/-/M:.yh..-M/-myss/-." << endl;
        cout << ".+hyyhs-.+ysss+.:d--shssy+./h-.-h/..oy.:hyssh:.-hyo.....yhyyyo:.-ohssyo..ohs::hyssh-.os..-h:-mysshy-" << endl;
        cout << "............................................................................................:Ns++hh-" << endl;
        cout << ".............................................................................................-:::-.." << endl;
}