#include <iostream>
#include "fitness_center.h"

void fitness_center_task() {
    using namespace std;

    cout << "\nСведения о клиентах фитнес-центра\n" << endl;
    cout << "Введите кол-во строк:" << endl;

    int n;
    int min_duration = 100;
    int min_year, min_month;
    bool valid_input = false;

    cin >> n;

    cout << "Заполнение строк в формате:\n" << endl;
    cout << "<Продолжительность занятий (в часах) (1-30)> <Код клиента (10-99)> <Год (2000-2010)> <Номер месяца (1-12)>\n" << endl;
    cout << "Некорректные данные в учёт не идут!\n" << endl;

    cout << "Вводите строки:" << endl;

    client_data* clients = new client_data[n];

    for (int i = 0; i < n; i++) {
        int duration, id, year, month;
        cin >> duration >> id >> year >> month;

        clients[i].duration = duration;
        clients[i].id = id;
        clients[i].year = year;
        clients[i].month = month;

        if (clients[i].duration >= 1 && clients[i].duration <= 30 &&
    clients[i].id >= 10 && clients[i].id <= 99 &&
    clients[i].year >= 2000 && clients[i].year <= 2010 &&
    clients[i].month >= 1 && clients[i].month <= 12) {
            valid_input = true;

            if (clients[i].duration < min_duration) {
                min_duration = clients[i].duration;
                min_year = clients[i].year;
                min_month = clients[i].month;
            }
            else if (clients[i].duration == min_duration) {
                if (clients[i].year < min_year ||
                   (clients[i].year == min_year && clients[i].month < min_month)) {
                    min_year = clients[i].year;
                    min_month = clients[i].month;
                   }
            }
    }
        else {
            cout << "invalid input!" << endl;
        }
    }

    if (valid_input) {
        cout << "Минимальная продолжительность - " << min_duration << "ч. " << min_year << "г. " << min_month << " мес." << endl;
    }

    delete[] clients;
}