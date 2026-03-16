#include "head.h"

// menu

void print_menu() {
    std::cout << "Выберите задачу:" << std::endl;
    std::cout << "1. ListWork68." << std::endl;
    std::cout << "2. ListWork42." << std::endl;
    std::cout << "3. ListWork64." << std::endl;
    std::cout << "4. ListWork47." << std::endl;
    std::cout << "5. 5" << std::endl;
    std::cout << "0. Выход из программы." << std::endl;
    std::cout << std::endl;
    std::cout << "Выберите задание:" << std::endl;
}

// Функции ввода данных -----------------------------------

std::vector<int> input_from_keyboard() {
    std::vector<int> numbers;
    int n, value;

    while (true) {
        std::cout << "Сколько чисел хотите ввести?" << std::endl;
        std::cin >> n;

        if (std::cin.fail() || n<=0) {
            std::cout << "Ошибка! Введите положительное число." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            break;
        }
    }

    std::cout << "Введите числа:" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cin >> value;

        while (std::cin.fail()) {
            std::cout << "Ошибка! Введите целое число (элемент " << i + 1 << "): ";
            std::cout << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cin >> value;
        }

        numbers.push_back(value);
    }

    return numbers;
}

std::vector<int> generate_random(int count) {
    std::vector<int> numbers;
    srand(time(0));

    for (int i = 0; i < count; i++) {
        numbers.push_back(rand() % 100 + 1); // числа от 1 до 100
    }

    std::cout << "Сгенерировано " << count << " чисел: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return numbers;
}

std::vector<int> read_from_file(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream file(filename);
    int value;

    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл!" << std::endl;
        return numbers;
    }

    while (file >> value) {
        numbers.push_back(value);
    }

    file.close();

    std::cout << "Прочитано " << numbers.size() << " чисел из файла: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return numbers;
}

int select_input_method() {
    int method_choice;

    while (true) {
        std::cout << std::endl;
        std::cout << "Выберите способ заполнения:" << std::endl;
        std::cout << "1. Ввод с клавиатуры" << std::endl;
        std::cout << "2. Случайные числа" << std::endl;
        std::cout << "3. Чтение из файла" << std::endl;
        std::cout << "Ваш выбор:" << std::endl;
        std::cin >> method_choice;

        if (std::cin.fail() || method_choice < 1 || method_choice > 3) {
            std::cout << "Ошибка! Введите число от 1 до 3." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            break;
        }
    }

    return method_choice;
}

std::vector<int> get_data_method() {
    int choice = select_input_method();
    std::vector<int> data;

    switch(choice) {
        case 1:
            data = input_from_keyboard();
            break;
        case 2: {
            int count;
            while (true) {
                std::cout << "Сколько чисел сгенерировать? " << std::endl;
                std::cin >> count;

                if (std::cin.fail() || count <= 0) {
                    std::cout << "Ошибка! Введите положительное число." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    break;
                }
            }
            data = generate_random(count);
            break;
        }
        case 3: {
            std::string filename;
            std::cout << "Введите имя файла:" << std::endl;
            std::cin >> filename;
            data = read_from_file(filename);
            if (data.empty()) {
                std::cout << "Файл пуст или не найден. Используем ввод с клавиатуры." << std::endl;
                data = input_from_keyboard();
            }
            break;
        }
        default:
            std::cout << "Неверный выбор. Используем ввод с клавиатуры." << std::endl;
            data = input_from_keyboard();
    }

    return data;
}