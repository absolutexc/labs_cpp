#include <iostream>
#include <fstream>
#include <string>
#include "figures.h"

void figures_task() {
    using namespace std;
    int n;
    cout << "Введите кол-во фигур:" << endl;
    cin >> n;

    Figure* f = new Figure[n];

    for (int i = 0; i < n; i++) {
        cout << "Фигура " << i+1 << "\nЦвет:";
        cin >> f[i].color;

        do {
            cout << "Тип (1 - круг, 2 - квадрат, 3 - отрезок): ";
            cin >> f[i].type;

            if (f[i].type < 1 || f[i].type > 3) {
                cout << "Ошибка! Введите число от 1 до 3." << endl;
            }
        } while (f[i].type < 1 || f[i].type > 3);

        if (f[i].type == 1) {
            do {
                cout << "Радиус: ";
                cin >> f[i].p.r;

                if (f[i].p.r <= 0) {
                    cout << "Ошибка! Радиус должен быть больше 0." << endl;
                }
            } while (f[i].p.r <= 0);
        }
        else if (f[i].type == 2) {
            do {
                cout << "Сторона: ";
                cin >> f[i].p.s;

                if (f[i].p.s <= 0) {
                    cout << "Ошибка! Сторона должна быть больше 0." << endl;
                }
            } while (f[i].p.s <= 0);
        }
        else if (f[i].type == 3) {
            do {
                cout << "Длина: ";
                cin >> f[i].p.l;

                if (f[i].p.l <= 0) {
                    cout << "Ошибка! Длина должна быть больше 0." << endl;
                }
            } while (f[i].p.l <= 0);
        }
    }

    ofstream out("figures.txt");
    out << "Тип\tЦвет\tПараметр-значение\t\n";
    for (int i = 0; i < n; i++) {
        out << (f[i].type == 1 ? "Круг" : f[i].type == 2 ? "Квадрат" : "Отрезок")
            << "\t" << f[i].color << "\t";

        if (f[i].type == 1) {
            out << "Радиус\t" << f[i].p.r;
        } else if (f[i].type == 2) {
            out << "Сторона\t" << f[i].p.s;
        } else {
            out << "Длина\t" << f[i].p.l;
        }
        out << "\n";
    }
    out.close();

    cout << "\nФайл figures.txt:\n";
    ifstream file("figures.txt");
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    cout << "\nКол-во фигур: " << n;

    delete[] f;
}