#include "head.h"

void task1() {
    std::cout << "Задача 1: STL3Alg5\n";

    std::list<int> list_l;
    request_fill(list_l, false);

    std::cout << "Исходный список L: ";
    print_list(list_l);

    IsNegative is_negative;
    IsPositive is_positive;

    auto first_negative = std::find_if(list_l.begin(), list_l.end(),
                                        is_negative);

    auto last_positive = std::find_if(list_l.rbegin(), list_l.rend(),
                                       is_positive);

    if (first_negative != list_l.end()) {
        auto insert_position = std::next(first_negative);
        list_l.insert(insert_position, 0);
        std::cout << "После вставки 0 после первого отрицательного:\n";
        print_list(list_l);
    }
    else {
        std::cout << "Отрицательных элементов нет, вставка не выполнена.\n";
    }

    if (last_positive != list_l.rend()) {
        auto insert_position = --last_positive.base();
        list_l.insert(insert_position, 0);
        std::cout << "После вставки 0 перед последним положительным:\n";
        print_list(list_l);
    }
    else {
        std::cout << "Положительных элементов нет, вставка не выполнена.\n";
    }

    std::cout << std::endl;
}

void task2() {
    std::cout << "Задача 2: STL3Alg26\n";

    std::list<int> list_l;

    while (true) {
        request_fill(list_l, false);

        if (is_even(list_l)) {
            break;
        }

        std::cout << "Ошибка: список должен содержать четное количество элементов.\n";
        std::cout << "Текущий размер: " << list_l.size() << "\n";
        std::cout << "Пожалуйста, повторите ввод.\n";
        list_l.clear();
    }

    std::cout << "Исходный список L: ";
    print_list(list_l);

    auto mid = list_l.begin();
    std::advance(mid, list_l.size() / 2);

    IsNegativeReplace is_negative;

    std::replace_copy_if(std::reverse_iterator(mid),
                         std::reverse_iterator(list_l.rend()),
                         std::back_inserter(list_l), // куда копировать
                         is_negative, 0);

    std::cout << "Итоговый список L: ";
    print_list(list_l);
    std::cout << std::endl;
}

void task3() {
    std::cout << "Задача 3: STL3Alg40\n";

    std::list<int> list_l;
    request_fill(list_l, false);

    std::cout << "Исходный список L: ";
    print_list(list_l);

    IsEven is_even;

    auto partition_point = std::partition(list_l.begin(), list_l.end(),
                                           is_even);

    int even_count = std::distance(list_l.begin(), partition_point);
    int odd_count = std::distance(partition_point, list_l.end());

    std::cout << "Количество четных чисел: " << even_count << std::endl;
    std::cout << "Количество нечетных чисел: " << odd_count << std::endl;
    std::cout << std::endl;
}

void task4() {
    std::cout << "Задача 4: STL3Alg60\n";

    std::list<int> list_l;
    request_fill(list_l, true);

    std::cout << "Исходный список L: ";
    print_list(list_l);

    if (list_l.size() < 2) {
        std::cout << "Ошибка: список должен содержать не менее 2 элементов.\n";
        std::cout << "Текущий размер: " << list_l.size() << "\n";
        return;
    }

    std::vector<double> vector_v;

    Average average;

    std::adjacent_difference(list_l.begin(), list_l.end(),
                             std::back_inserter(vector_v),
                             average);

    vector_v.erase(vector_v.begin());

    std::cout << "Вектор средних арифметических V: ";
    print_vector(vector_v);
    std::cout << std::endl;
}