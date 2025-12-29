#include <iostream>
#include "tasks.h"

void print_menu() {
    using namespace std;
    cout << "\n1. Квадратичная сортировка." << endl;
    cout << "2. EXAMTASKC" << endl;
    cout << "3. Данные в текстовом формате" << endl;
    cout << "0. Выход" << endl;
    cout << endl;
    cout << "Выберите задачу: " << endl;
}

int main() {
    using namespace std;
    int choice;

    do {
        print_menu();
        cin >> choice;

        switch (choice) {
            case 0: cout << "Выход из программы."; break;
            case 1: Sort11(); break;
            case 2: ExamTaskC15(); break;
            case 3: Five11(); break;
            default: cout << "Введите число от 0 до 3!" << endl;
        }
    } while (choice != 0);

    return 0;
}