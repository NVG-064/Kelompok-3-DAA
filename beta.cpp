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

    else if ((hour >= 18) && (hour < 0)){
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
        cout << "\n=========================================================================================\n";
}