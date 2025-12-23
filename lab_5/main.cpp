#include <iostream>
#include "head.h"

int main() {
    using namespace std;
    int choice;
    do {
        main_menu();
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7:
                cout << "Выход из программы. До свидания!" << endl;
                break;
            default: cout << "Неверный выбор! Выберите число от 1 до 7." << endl;
                cout << endl;
                cin.clear();
                cin.ignore(1000, '\n');
        }

    } while (choice != 7);

    return 0;
}