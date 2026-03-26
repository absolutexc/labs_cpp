#include "head.h"
#include <iostream>

int main() {
    int choice;

    do {
        menu();
        choice = get_not_neg();

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Выберите число от 0 до 4!.\n";
                std::cout << std::endl;
                break;
        }

    } while (choice != 0);

    return 0;
}