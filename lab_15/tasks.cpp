#include "head.h"

void task1() {
    std::cout << "Задача 1. Точка координат" << std::endl;

    int choice;
    std::vector<Point> points;

    do {
        point_menu();
        std::cin >> choice;

        if (std::cin.fail()) {
            clear_input();
            std::cout << "Ошибка! Введите корректное число.\n";
            continue;
        }

        switch (choice) {
            case 1:
                points = input_point_cons();
                break;
            case 2:
                points = input_point_random();
                break;
            case 3:
                points = input_point_file();
                break;
            default:
                std::cout << "Ошибка! Введите число от 1 до 3.\n";
                continue;
        }

        if (!points.empty()) {
            print_points(points);
        }
        else {
            std::cout << "Не удалось создать точки.\n";
        }

        break;

    } while (true);

    std::cout << std::endl;
}

void task2() {
    std::cout << "Задача 2. Точка координат" << std::endl;

    std::cout << "\nВвод линии 1\n";
    Line line1 = line_from_points();

    std::cout << "\nВвод линии 2 (горизонтальная)\n";
    Line line2 = horizontal_line();

    Line line3(line1.get_start(), line2.get_end());

    std::cout << "Все линии\n";
    std::cout << "Линия 1: ";
    line1.print();
    std::cout << std::endl;

    std::cout << "Линия 2: ";
    line2.print();
    std::cout << std::endl;

    std::cout << "Линия 3 (зависит от линии 1 и линии 2): ";
    line3.print();
    std::cout << std::endl;

    std::cout << "Изменение координат линии 1 и линии 2\n";

    std::cout << "\nВведите новые координаты для линии 1\n";
    Line new_line1 = line_from_points();
    line1.set_start(new_line1.get_start());
    line1.set_end(new_line1.get_end());

    std::cout << "\nВведите новые координаты для линии 2 (горизонтальная)\n";
    Line new_line2 = horizontal_line();
    line2.set_start(new_line2.get_start());
    line2.set_end(new_line2.get_end());

    line3 = Line(line1.get_start(), line2.get_end());

    std::cout << "\nЛинии после изменени\n";
    std::cout << "Линия 1: ";
    line1.print();
    std::cout << std::endl;

    std::cout << "Линия 2: ";
    line2.print();
    std::cout << std::endl;

    std::cout << "Линия 3 (обновлённая): ";
    line3.print();
    std::cout << std::endl;

    std::cout << "Изменяем линию 1 так, чтобы линия 3 не изменилась\n";

    Line saved_line3 = line3;

    std::cout << "\nВведите новые координаты для линии 1\n";
    Line another_line1 = line_from_points();
    line1.set_start(another_line1.get_start());
    line1.set_end(another_line1.get_end());

    std::cout << "\nРезультат\n";
    std::cout << "Линия 1 после изменения: ";
    line1.print();
    std::cout << std::endl;

    std::cout << "Линия 3 (не изменилась): ";
    saved_line3.print();
    std::cout << std::endl;
}

void task3() {
    std::cout << "Задача 3. Студент" << std::endl;

    clear_input();

    std::cout << "\nСоздание первого студента\n";
    std::cout << "Введите имя студента: ";
    std::string name1 = input_name();

    std::cout << "Введите количество оценок: ";
    int n = get_positive();

    std::vector<int> grades1;
    for (int i = 0; i < n; i++) {
        std::cout << "Оценка " << i + 1 << ": ";
        int grade = get_positive();
        grades1.push_back(grade);
    }

    Student vasya(name1, grades1);

    clear_input();

    std::cout << "Создание второго студента\n";
    std::cout << "Введите имя студента: ";
    std::string name2 = input_name();

    Student petya(name2, vasya.GetGrades());

    std::cout << "Исходные студенты\n";
    vasya.print();
    std::cout << std::endl;
    petya.print();
    std::cout << std::endl;

    std::cout << "\nЗамена первой оценки Пети на 5\n";
    std::vector<int> petya_grades = petya.GetGrades();
    if (!petya_grades.empty()) {
        petya_grades[0] = 5;
        petya.SetGrades(petya_grades);
    }

    std::cout << "\nПосле замены\n";
    vasya.print();
    std::cout << std::endl;
    petya.print();
    std::cout << std::endl;

    std::cout << "\nСоздание третьего студента\n";
    std::cout << "Введите имя студента: ";
    std::string name3 = input_name();

    Student andrey(name3, vasya.GetGrades());

    std::cout << "Студент Андрей\n";
    vasya.print();
    std::cout << std::endl;
    petya.print();
    std::cout << std::endl;
    andrey.print();
    std::cout << std::endl;

    std::cout << "\nИзменение оценок студента: Вася\n";
    std::vector<int> new_grades;
    std::cout << "Введите количество новых оценок для студента: Вася\n";
    int m = get_positive();

    for (int i = 0; i < m; i++) {
        int grade;
        std::cout << "Новая оценка " << i + 1 << ": ";
        std::cin >> grade;
        new_grades.push_back(grade);
    }
    vasya.SetGrades(new_grades);

    std::cout << "После изменения оценок Васи\n";
    vasya.print();
    std::cout << std::endl;
    andrey.print();
    std::cout << std::endl;
    std::cout << std::endl;
}

void task4() {
    std::cout << "Задача 4. Точка координат" << std::endl;
    std::cout << "\nСоздание точек (с помощью координат)\n";

    std::cout << "Создание точки 1\n";
    std::cout << "Введите координаты точки (X Y): ";
    int x1, y1;
    std::cin >> x1 >> y1;
    PointSec p1(x1, y1);

    std::cout << "Создание точки 2\n";
    std::cout << "Введите координаты точки (X Y): ";
    int x2, y2;
    std::cin >> x2 >> y2;
    PointSec p2(x2, y2);

    std::cout << "Создание точки 3\n";
    std::cout << "Введите координаты точки (X Y): ";
    int x3, y3;
    std::cin >> x3 >> y3;
    PointSec p3(x3, y3);

    std::cout << "Созданные точки:\n";
    std::cout << "Точка 1: ";
    p1.print();
    std::cout << std::endl;
    std::cout << "Точка 2: ";
    p2.print();
    std::cout << std::endl;
    std::cout << "Точка 3: ";
    p3.print();
    std::cout << std::endl;

    std::cout << "\nСоздание линий\n";

    std::cout << "\nСоздание Линии 1 (через две точки)\n";
    std::cout << "Введите координаты начала (X Y): ";
    int xs1, ys1;
    std::cin >> xs1 >> ys1;
    std::cout << "Введите координаты конца (X Y): ";
    int xe1, ye1;
    std::cin >> xe1 >> ye1;
    LineSec line1(PointSec(xs1, ys1), PointSec(xe1, ye1));

    std::cout << "\nСоздание Линии 2 (горизонтальная)\n";
    std::cout << "Введите Y (высота): ";
    int y_horiz;
    std::cin >> y_horiz;
    std::cout << "Введите X начала: ";
    int x_start_horiz;
    std::cin >> x_start_horiz;
    std::cout << "Введите X конца: ";
    int x_end_horiz;
    std::cin >> x_end_horiz;
    LineSec line2(x_start_horiz, y_horiz, x_end_horiz, y_horiz);

    LineSec line3(line1.get_start(), line2.get_end());

    std::cout << "Созданные линии\n";
    std::cout << "Линия 1: ";
    line1.print();
    std::cout << std::endl;

    std::cout << "Линия 2: ";
    line2.print();
    std::cout << std::endl;

    std::cout << "Линия 3: ";
    line3.print();
    std::cout << std::endl;
    std::cout << std::endl;
}

void task5() {
    std::cout << "Задача 5. Длина линии" << std::endl;

    std::cout << "\nВычисление длины линии\n";

    std::cout << "\nСоздание линии для вычисления длины\n";
    std::cout << "Введите координаты начала линии (X Y): ";
    int x1, y1;
    std::cin >> x1 >> y1;

    std::cout << "Введите координаты конца линии (X Y): ";
    int x2, y2;
    std::cin >> x2 >> y2;

    PointSec start(x1, y1);
    PointSec end(x2, y2);
    LineSec line(start, end);

    std::cout << "Созданная линия: ";
    line.print();
    std::cout << std::endl;

    int length = line.Length();
    std::cout << "Длина линии: " << length << std::endl;

    std::cout << std::endl;
}