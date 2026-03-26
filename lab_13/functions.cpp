#include "head.h"

void menu() {
    std::cout << "Главное меню:" << std::endl;
    std::cout << "1. STL3Alg5\n";
    std::cout << "2. STL3Alg26\n";
    std::cout << "3. STL3Alg40\n";
    std::cout << "4. STL3Alg60\n";
    std::cout << "0. Выход\n";
    std::cout << std::endl;
    std::cout << "Выберите задание: ";
    std::cout << std::endl;
}

// вспомогательные -----------------------------------

void clear_input() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

// проверка ввода для меню
int get_not_neg() {
    int number;
    bool validInput = false;

    do {
        if (std::cin >> number) {
            if (number >= 0) {
                validInput = true;
            }
            else {
                std::cout << "Ошибка: введите неотрицательное число.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!validInput);

    return number;
}

// проверка ввода для 4 задания
int get_positive() {
    int number;
    bool validInput = false;

    do {
        if (std::cin >> number) {
            if (number > 0) {
                validInput = true;
            }
            else {
                std::cout << "Ошибка: введите положительное число.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!validInput);

    return number;
}

// проверка ввода для 1-3 заданий
int get_any_int() {
    int number;

    while (!(std::cin >> number)) {
        std::cout << "Ошибка: введите корректное целое число: " << std::endl;
        clear_input();
    }

    return number;
}

int get_size() {
    int size;
    bool valid_input = false;

    do {
        if (std::cin >> size) {
            if (size > 0) {
                valid_input = true;
            } else {
                std::cout << "Ошибка: размер должен быть положительным: ";
            }
        } else {
            std::cout << "Ошибка: введите корректное целое число: ";
            clear_input();
        }
    } while (!valid_input);

    return size;
}

bool is_even(const std::list<int>& list) {
    return list.size() % 2 == 0;
}

// вывод структур -------------------------------------

void print_list(const std::list<int>& list) {
    for (const auto& value : list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void print_vector(const std::vector<double>& vector) {
    for (const auto& value : vector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// заполнение списков

int get_data_choice() {
    int choice;
    bool validInput = false;

    do {
        std::cout << "\nВыберите способ заполнения:\n";
        std::cout << "1. Из консоли\n";
        std::cout << "2. Случайными числами\n";
        std::cout << "3. Из файла\n";
        std::cout << "Ваш выбор:\n";

        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 3) {
                validInput = true;
            } else {
                std::cout << "Ошибка: введите число от 1 до 3.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!validInput);

    return choice;
}

void request_fill(std::list<int> &list, bool need_positive) {
    int fill_method = get_data_choice();
    int size;
    switch (fill_method) {
        case 1:
            fill_list_console(list, need_positive);
            break;
        case 2:
            std::cout << "Введите количество элементов: " << std::endl;
            size = get_size();
            fill_list_random(list, size);
            break;
        case 3:
            std::string filename;
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            fill_list_file(list, filename, need_positive);
            break;
    }
}

void fill_list_console(std::list<int>& list, bool need_positive) {
    std::cout << "Введите количество элементов: " << std::endl;
    int size = get_size();
    std::cout << "Введите " << size << " элементов (целые числа): " << std::endl;
    for (int i = 0; i < size; ++i) {
        int value;
        value = get_any_int();

        // if (need_positive) {
        //     value = get_positive();
        // }
        // else {
        //     value = get_any_int();
        // }

        list.push_back(value);
    }
}

void fill_list_random(std::list<int>& list, int size) {
    std::random_device random_device;
    std::mt19937 generator(random_device());

    std::uniform_int_distribution<int> distribution(-100, 100);

    for (int i = 0; i < size; ++i) {
        list.push_back(distribution(generator));
    }

    std::cout << "Сгенерировано " << size << " случайных чисел в диапазоне [-100, 100]\n";
}

void fill_list_file(std::list<int>& list, const std::string& filename, bool need_positive) {
    std::ifstream input_file(filename);

    if (!input_file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл " << filename << std::endl;
        std::cout << "Будет использован ввод с консоли.\n";
        fill_list_console(list, need_positive);
        return;
    }
    int value;
    bool has_error = false;

    while (input_file >> value) {
        if (need_positive && value <= 0) {
            std::cout << "Предупреждение: в файле найдено неподходящее значение " << value
                      << " (требуются положительные числа). Оно будет пропущено.\n";
            has_error = true;
            continue;
        }
        list.push_back(value);
    }

    input_file.close();

    if (list.empty()) {
        if (has_error) {
            std::cout << "Файл не содержит подходящих положительных чисел. Будет использован ввод с консоли.\n";
        }
        else {
            std::cout << "Файл пуст или содержит некорректные данные. Будет использован ввод с консоли.\n";
        }
        fill_list_console(list, need_positive);
    }
    else {
        std::cout << "Успешно загружено " << list.size() << " элементов из файла.\n";
        if (has_error) {
            std::cout << "Некоторые элементы были пропущены (требуются положительные числа).\n";
        }
    }
}