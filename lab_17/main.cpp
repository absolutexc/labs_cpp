#include "head.h"

void print_cat() {
    std::cout << "\n";
    std::cout << "  /\\_/\\\n";
    std::cout << " ( o.o )\n";
    std::cout << "  > ^ <\n";
    std::cout << "\n  Мяу!\n";
}

int main() {
    std::srand(std::time(0));

    ExpressionTree my_tree;
    int choice;

    do {
        show_menu();
        choice = get_not_neg();

        switch (choice) {
            case 1:
                task1(my_tree);
                break;
            case 2:
                task2(my_tree);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Выберите число от 0 до 2!\n";
                std::cout << std::endl;
                break;
        }
    } while (choice != 0);

    print_cat();

    return 0;
}