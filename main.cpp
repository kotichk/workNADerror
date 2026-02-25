#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct LogEntry {
    int year;
    int month;
    int day;

    int hour;
    int minut;
    int sec;
    int milisec;

    int cod;

    string info;

    string mainThread;

    string namePotoka;

    string message;
};

void InStruct(const string& line, LogEntry& entr)
{
    stringstream ss(line);
    char charr;
    ss >> entr.year >> charr >> entr.month >> charr >> entr.day;
    ss >> entr.hour >> charr >> entr.minut >> charr >> entr.sec >> charr >> entr.milisec;
    ss >> entr.cod;
    ss >> entr.info;
    ss >> entr.mainThread;
    ss >> entr.namePotoka;
    getline(ss, entr.message);
    if (entr.message.length() > 0 && entr.message[0] == ' ') {
        entr.message = entr.message.substr(1);
    }
}

int main()
{
    ifstream file("Box-1.17.120.2022-10-31.log");
    if (!file.is_open()) {
        cout << "Error! File is`t open" << endl;
        return 0;
    }

    // kol-vo strok v file
    string line;
    int countLine = 0;
    while (getline(file, line)) {
        countLine ++;
    }

    cout << "Strok v file: " << countLine << endl;
    file.close();

    LogEntry* logs = new LogEntry[countLine];
    file.open("Box-1.17.120.2022-10-31.log");
    if (!file.is_open()) {
        cout << "Error! File is`t open" << endl;
        return 0;
    }
    int index = 0;
    while (getline(file, line) && index < countLine) {
        InStruct(line, logs[index]);
        index++;
    }
    file.close();

    int infomess = 0;
    int warnmess = 0;
    int errormess = 0;
    for (int i = 0; i < countLine; i++) {
        if (logs[i].info == "INFO") {
            infomess++;
        }
        if (logs[i].info == "WARNING") {
            warnmess++;
        }
        if (logs[i].info == "ERROR") {
            errormess++;
        }
    }
    cout << "INFO messages: " << infomess << endl;
    cout << "WARNING messages: " << warnmess << endl;
    cout << "ERROR messages: " << errormess << endl;
}

//2022-10-31 21:31:51.448 3260 INFO    MainThread           windows_sync_app_dele Launching Box
// дата год-месяц-число
// время часы-минуты-секунды-милесек
// код
// инфа
// имя потока
// название процесса
// сообщение
