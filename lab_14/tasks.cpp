#include "head.h"

void task1(){
    std::cout << "\nЗадача 1. STL5Assoc2\n" << std::endl;

    std::cout << "Заполнение вектора v0" << std::endl;
    std::cout << "Выберите способ заполнения:" << std::endl;
    std::cout << "1. Ввод с консоли" << std::endl;
    std::cout << "2. Случайные числа" << std::endl;
    std::cout << "3. Загрузка из файла" << std::endl;
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    std::vector<int> V0;

    switch (choice) {
        case 1:
            V0 = fill_console();
            break;
        case 2:
            V0 = fill_random();
            break;
        case 3:
            V0 = fill_file();
            if (V0.empty()) {
                std::cout << "Не удалось загрузить данные из файла. Завершение задачи." << std::endl;
                return;
            }
            break;
        default:
            std::cout << "Неверный выбор. Используется ввод с консоли." << std::endl;
            V0 = fill_console();
            break;
    }

    std::cout << "\nЗаполнение векторов V1...VN:" << std::endl;

    int N;
    std::cout << "Введите количество векторов V1...VN: ";
    N = get_not_neg();

    std::vector<std::vector<int>> vectors = fill_vectors(N, V0.size());

    std::set<int> setV0(V0.begin(), V0.end());
    int count = 0;

    for (const auto& vec : vectors) {
        std::set<int> setVec(vec.begin(), vec.end());

        if (std::includes(setVec.begin(), setVec.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }

    std::cout << std::endl;
    std::cout << "Результат: " << count << " вектор(-а)(-ов) содержит(-ат) все элементы V0" << std::endl;
    std::cout << std::endl;
}

void task2() {
    std::cout << "\nЗадача 2. STL5Assoc17\n" << std::endl;

    std::cout << "Заполнение вектора слов" << std::endl;
    std::cout << "Выберите способ заполнения:" << std::endl;
    std::cout << "1. Ввод с консоли" << std::endl;
    std::cout << "2. Загрузка из файла" << std::endl;
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    std::vector<std::string> V;

    switch (choice) {
        case 1:
            V = fill_string_console();
            break;
        case 2:
            V = fill_string_file();
            if (V.empty()) {
                std::cout << "Не удалось загрузить данные из файла. Завершение задачи." << std::endl;
                return;
            }
            break;
        default:
            std::cout << "Неверный выбор. Используется ввод с консоли." << std::endl;
            V = fill_string_console();
            break;
    }

    std::map<char, int> M;

    for (std::vector<std::string>::iterator it = V.begin(); it != V.end(); it++) {
        char first_letter = (*it)[0];
        M[first_letter] += (*it).size();
    }

    std::cout << "Результат:" << std::endl;

    if (M.empty()) {
        std::cout << "Нет данных для вывода." << std::endl;
    }
    else {
        for (std::map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
    std::cout << std::endl;
}

void task3() {
    std::cout << "\nЗадача 3. STL5Assoc21\n" << std::endl;

    std::cout << "Заполнение вектора чисел:" << std::endl;
    std::cout << "Выберите способ заполнения:" << std::endl;
    std::cout << "1. Ввод с консоли" << std::endl;
    std::cout << "2. Случайные числа" << std::endl;
    std::cout << "3. Загрузка из файла" << std::endl;
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    std::vector<int> V;

    switch (choice) {
        case 1:
            V = fill_console();
            break;
        case 2:
            V = fill_random();
            break;
        case 3:
            V = fill_file();
            if (V.empty()) {
                std::cout << "Не удалось загрузить данные из файла. Завершение задачи." << std::endl;
                return;
            }
            break;
        default:
            std::cout << "Неверный выбор. Используется ввод с консоли." << std::endl;
            V = fill_console();
            break;
    }

    std::multimap<int, int> M;

    for (std::vector<int>::iterator it = V.begin(); it != V.end(); it++) {
        int last = std::abs(*it) % 10;
        M.insert(std::pair<int, int>(last, *it));
    }

    std::cout << "Результат:" << std::endl;

    if (M.empty()) {
        std::cout << "Нет данных для вывода." << std::endl;
    }
    else {
        for (std::multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
    std::cout << std::endl;
}