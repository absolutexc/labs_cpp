#include "head.h"

void menu() {
    std::cout << "Главное меню.\n";
    std::cout << "1. Точка координат\n";
    std::cout << "2. Прямая\n";
    std::cout << "3. Студент\n";
    std::cout << "4. Создаем точку, линию\n";
    std::cout << "5. Длина линии\n";
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

bool is_valid_name(const std::string& name) {
    if (name.empty()) {
        return false;
    }

    std::string allowed = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
                          "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
                          "abcdefghijklmnopqrstuvwxyz"
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    for (char c : name) {
        if (allowed.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}

std::string input_name() {
    std::string name;
    bool valid_input = false;

    do {
        std::getline(std::cin, name);

        size_t start = name.find_first_not_of(" \t");
        size_t end = name.find_last_not_of(" \t");

        if (start == std::string::npos) {
            std::cout << "Ошибка: имя не может быть пустым!" << std::endl;
            continue;
        }

        name = name.substr(start, end - start + 1);

        if (is_valid_name(name)) {
            valid_input = true;
        }
        else {
            std::cout << "Ошибка: имя должно содержать только буквы!" << std::endl;
        }
    } while (!valid_input);

    return name;
}

// Point

std::vector<Point> input_point_cons() {
    std::vector<Point> points;

    std::cout << "Введите количество точек: ";

    int n = get_positive();

    if (std::cin.fail() || n <= 0) {
        clear_input();
        std::cout << "Ошибка! Введите положительное число.\n";
        return points;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cout << "Точка " << i + 1 << " - введите X и Y: ";
        std::cin >> x >> y;

        if (std::cin.fail()) {
            clear_input();
            std::cout << "Ошибка ввода! Попробуйте снова.\n";
            --i;
            continue;
        }

        points.push_back(Point(x, y));
    }

    return points;
}

std::vector<Point> input_point_random() {
    std::vector<Point> points;
    int n;
    int min_coord, max_coord;

    std::cout << "Введите количество точек: ";
    std::cin >> n;

    if (std::cin.fail() || n <= 0) {
        clear_input();
        std::cout << "Ошибка! Введите положительное число.\n";
        return points;
    }

    std::cout << "Введите минимальную координату: ";
    std::cin >> min_coord;
    std::cout << "Введите максимальную координату: ";
    std::cin >> max_coord;

    if (std::cin.fail() || min_coord > max_coord) {
        clear_input();
        std::cout << "Ошибка! Проверьте диапазон координат.\n";
        return points;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min_coord, max_coord);

    for (int i = 0; i < n; ++i) {
        points.push_back(Point(dis(gen), dis(gen)));
    }

    return points;
}

std::vector<Point> input_point_file() {
    std::vector<Point> points;
    std::string filename;

    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка! Не удалось открыть файл " << filename << std::endl;
        return points;
    }

    int n;
    file >> n;

    if (file.fail() || n <= 0) {
        std::cout << "Ошибка! Неверный формат файла.\n";
        return points;
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        file >> x >> y;

        if (file.fail()) {
            std::cout << "Ошибка! Неверный формат данных в файле.\n";
            return points;
        }

        points.push_back(Point(x, y));
    }

    file.close();
    std::cout << "Успешно загружено " << n << " точек из файла.\n";

    return points;
}

void print_points(const std::vector<Point>& points) {
    std::cout << "Созданные точки:\n";
    for (int i = 0; i < points.size(); i++) {
        std::cout << "Точка " << i + 1 << ": ";
        points[i].print();
    }
}

void point_menu() {
    std::cout << "\nВыберите способ создания точек\n";
    std::cout << "1. Ввод с клавиатуры\n";
    std::cout << "2. Рандомно\n";
    std::cout << "3. Из файла\n";
    std::cout << "Ваш выбор: \n";
}

// Line

Line line_from_points() {
    int x1, y1, x2, y2;

    std::cout << "Введите координаты начала линии (X Y): ";
    std::cin >> x1 >> y1;

    std::cout << "Введите координаты конца линии (X Y): ";
    std::cin >> x2 >> y2;

    Point start(x1, y1);
    Point end(x2, y2);

    return Line(start, end);
}

Line horizontal_line() {
    int y, x1, x2;

    std::cout << "Введите Y (высота): ";
    std::cin >> y;
    std::cout << "Введите X начала: ";
    std::cin >> x1;
    std::cout << "Введите X конца: ";
    std::cin >> x2;

    return Line(x1, y, x2, y);
}