#include <iostream>
#include "fitness_center.h"
#include "figures.h"
#include "points_2d.h"

void print_main_menu() {
    using namespace std;
    cout << "\n1. Фитнес-центр\n";
    cout << "2. Работа с фигурами\n";
    cout << "3. Точки в 2D пространстве\n";
    cout << "0. Выход\n";
    cout << endl;
    cout << "Выберите задачу: " << endl;
}

int main() {
    using namespace std;
    int choice;

    do {
        print_main_menu();
        cin >> choice;

        switch(choice) {
            case 1:
                fitness_center_task();
                break;
            case 2:
                figures_task();
                break;
            case 3:
                points_2d_task();
                break;
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Выберите число от 0 до 3.\n";
        }

    } while (choice != 0);

    return 0;
}