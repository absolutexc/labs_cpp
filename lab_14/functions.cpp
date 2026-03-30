#include "head.h"

void menu() {
    std::cout << "Главное меню.\n";
    std::cout << "1. STL5Assoc2\n";
    std::cout << "2. STL5Assoc17\n";
    std::cout << "3. STL5Assoc21\n";
    std::cout << "0. Выход из программы." << std::endl;
    std::cout << std::endl;
    std::cout << "Выберите пункт меню:" << std::endl;
}

void clear_input() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int get_not_neg() {
    int number;
    bool valid_input = false;

    do {
        if (std::cin >> number) {
            if (number >= 0) {
                valid_input = true;
            }
            else {
                std::cout << "Ошибка: введите положительное число.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!valid_input);

    return number;
}

int get_positive() {
    int number;
    bool valid_input = false;

    do {
        if (std::cin >> number) {
            if (number > 0) {
                valid_input = true;
            }
            else {
                std::cout << "Ошибка: введите положительное число.\n";
            }
        }
        else {
            std::cout << "Ошибка: введите корректное число.\n";
            clear_input();
        }
    } while (!valid_input);

    return number;
}

std::vector<int> fill_console() {
    int size;
    std::cout << "Введите размер вектора: ";
    size = get_not_neg();

    std::vector<int> vec;
    std::cout << "Введите " << size << " целых чисел:" << std::endl;
    for (int i = 0; i < size; ++i) {
        int element;
        std::cin >> element;
        vec.push_back(element);
    }

    return vec;
}

std::vector<int> fill_random() {
    int size;
    std::cout << "Введите размер вектора: ";
    size = get_not_neg();

    int min_val, max_val;
    std::cout << "Введите минимальное значение: ";
    std::cin >> min_val;
    std::cout << "Введите максимальное значение: ";
    std::cin >> max_val;

    // Инициализация генератора случайных чисел
    static bool seeded = false;
    if (!seeded) {
        std::srand(0);
        seeded = true;
    }

    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        int random_num = min_val + std::rand() % (max_val - min_val + 1);
        vec.push_back(random_num);
    }

    std::cout << "Сгенерированный вектор: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return vec;
}

std::vector<int> fill_file() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return std::vector<int>();
    }

    std::vector<int> vec;
    int num;
    while (file >> num) {
        vec.push_back(num);
    }

    file.close();

    if (vec.empty()) {
        std::cout << "Файл пуст или не содержит чисел." << std::endl;
    } else {
        std::cout << "Загружено " << vec.size() << " чисел из файла." << std::endl;
    }

    return vec;
}

std::vector<std::string> fill_string_console() {
    int size;
    std::cout << "Введите количество слов: ";
    size = get_positive();

    std::vector<std::string> vec;
    std::cout << "Введите " << size << " английское(-их) слов(-о) заглавными буквами:" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::string word;
        bool valid_word = false;

        do {
            std::cout << "Слово " << i + 1 << ": ";
            std::cin >> word;

            bool all_upper = true;
            for (char c : word) {
                if (!std::isupper(c)) {
                    all_upper = false;
                    break;
                }
            }

            if (!all_upper) {
                std::cout << "ОШИБКА: Слово должно быть набрано английскими заглавными буквами. Повторите ввод." << std::endl;
                clear_input();
                continue;
            }

            valid_word = true;
        } while (!valid_word);

        vec.push_back(word);
    }

    return vec;
}

std::vector<std::string> fill_string_file() {
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return std::vector<std::string>();
    }

    std::vector<std::string> vec;
    std::string word;
    while (file >> word) {
        bool all_upper = true;
        for (char c : word) {
            if (!std::isupper(c)) {
                all_upper = false;
                break;
            }
        }

        if (!all_upper) {
            std::cout << "Ошибка: слово \"" << word << "\" не состоит из заглавных букв. Оно будет пропущено." << std::endl;
            continue;
        }

        vec.push_back(word);
    }

    file.close();

    if (vec.empty()) {
        std::cout << "Файл пуст или не содержит корректных слов." << std::endl;
    }
    else {
        std::cout << "Загружено " << vec.size() << " слов из файла." << std::endl;
    }

    return vec;
}

std::vector<std::vector<int>> fill_vectors(int N, int v0_size) {
    std::vector<std::vector<int>> vectors;

    // Меню выбора способа заполнения для всех векторов V1...VN
    std::cout << "\nВыберите способ заполнения для всех векторов V1...VN:" << std::endl;
    std::cout << "1. Ввод с консоли (все векторы одинакового размера)" << std::endl;
    std::cout << "2. Случайные числа (все векторы одинакового размера)" << std::endl;
    std::cout << "3. Загрузка из файла (каждый вектор из своего файла)" << std::endl;
    std::cout << "Ваш выбор: ";

    int fill_method;
    std::cin >> fill_method;

    // Общий размер для всех векторов (для методов 1 и 2)
    int common_size = 0;
    bool valid_size = false;

    if (fill_method == 1 || fill_method == 2) {
        // Повторяем ввод размера, пока он не станет >= v0_size
        do {
            std::cout << "Введите размер для всех векторов V1...V" << N << ": ";
            common_size = get_not_neg();

            if (common_size >= v0_size) {
                valid_size = true;
            } else {
                std::cout << "ОШИБКА: Размер векторов (" << common_size
                          << ") меньше размера вектора V0 (" << v0_size << ")!" << std::endl;
                std::cout << "Размер векторов должен быть не меньше " << v0_size
                          << ". Повторите ввод." << std::endl;
            }
        } while (!valid_size);
    }

    // Заполнение векторов в зависимости от выбранного метода
    switch (fill_method) {
        case 1: // Ввод с консоли
            std::cout << "\n=== ВВОД ВЕКТОРОВ V1...V" << N << " ===" << std::endl;
            for (int i = 0; i < N; ++i) {
                std::cout << "\n--- Вектор V" << i + 1 << " ---" << std::endl;

                std::vector<int> vec;
                std::cout << "Введите " << common_size << " целых чисел:" << std::endl;
                for (int j = 0; j < common_size; ++j) {
                    int element;
                    std::cin >> element;
                    vec.push_back(element);
                }
                vectors.push_back(vec);
            }
            break;

        case 2: // Случайные числа
            {
                int min_val, max_val;
                std::cout << "Введите минимальное значение для случайных чисел: ";
                std::cin >> min_val;
                std::cout << "Введите максимальное значение для случайных чисел: ";
                std::cin >> max_val;

                // Инициализация генератора случайных чисел
                static bool seeded = false;
                if (!seeded) {
                    std::srand(0);
                    seeded = true;
                }

                std::cout << "\n=== ГЕНЕРАЦИЯ ВЕКТОРОВ V1...V" << N << " ===" << std::endl;
                for (int i = 0; i < N; ++i) {
                    std::cout << "\n--- Вектор V" << i + 1 << " ---" << std::endl;

                    std::vector<int> vec;
                    for (int j = 0; j < common_size; ++j) {
                        int random_num = min_val + std::rand() % (max_val - min_val + 1);
                        vec.push_back(random_num);
                    }

                    std::cout << "Сгенерированный вектор: ";
                    for (size_t k = 0; k < vec.size(); ++k) {
                        std::cout << vec[k] << " ";
                    }
                    std::cout << std::endl;

                    vectors.push_back(vec);
                }
            }
            break;

        case 3: // Загрузка из файлов
            std::cout << "\n=== ЗАГРУЗКА ВЕКТОРОВ ИЗ ФАЙЛОВ ===" << std::endl;
            for (int i = 0; i < N; ++i) {
                std::cout << "\n--- Вектор V" << i + 1 << " ---" << std::endl;

                bool valid_vector = false;
                std::vector<int> vec;

                // Повторяем загрузку, пока не получим вектор с размером >= v0_size
                do {
                    vec = fill_file();

                    if (vec.empty()) {
                        std::cout << "Файл пуст. Попробуйте другой файл." << std::endl;
                        continue;
                    }

                    if (vec.size() >= static_cast<size_t>(v0_size)) {
                        valid_vector = true;
                    } else {
                        std::cout << "ОШИБКА: Размер вектора V" << i + 1 << " (" << vec.size()
                                  << ") меньше размера вектора V0 (" << v0_size << ")!" << std::endl;
                        std::cout << "Размер вектора должен быть не меньше " << v0_size
                                  << ". Повторите загрузку." << std::endl;
                        vec.clear();
                    }
                } while (!valid_vector);

                vectors.push_back(vec);
            }
            break;

        default:
            std::cout << "Неверный выбор. Заполнение отменено." << std::endl;
            break;
    }

    return vectors;
}