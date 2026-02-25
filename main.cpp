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
        logs[index].message = line;
        index++;
    }
    file.close();


}

//2022-10-31 21:31:51.448 3260 INFO    MainThread           windows_sync_app_dele Launching Box
// дата год-месяц-число
// время часы-минуты-секунды-милесек
// код
// инфа
// имя потока
// название процесса
// сообщение
