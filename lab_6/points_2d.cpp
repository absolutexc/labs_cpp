#include <iostream>
#include <vector>
#include <iomanip>
#include "points_2d.h"

void points_2d_task() {
    vector<Point> points;
    int choice;

    do {
        print_points_menu();
        cin >> choice;

        switch (choice) {

            case 0: {
                cout << "Выход из программы.\n";
                break;
            }

            case 1: {
                cout << "Добавление точки." << endl;
                Point newPoint;
                cout << "Введите координату x: " << endl;
                cin >> newPoint.x;
                cout << "Введите координату y: " << endl;
                cin >> newPoint.y;

                points.push_back(newPoint);

                cout << "Точка добавлена. Всего точек: " << points.size() << endl;
                cout << endl;
                break;
            }

            case 2: {
                cout << "Вычисление расстояния между двумя точками" << endl;
                if (points.size() < 2) {
                    cout << "Недостаточно точек. Добавьте хотя бы 2 точки.\n";
                    break;
                }

                cout << "Выберите индекс первой точки (0 - " << points.size() - 1 << "): ";
                int index1;
                cin >> index1;

                cout << "Выберите индекс второй точки (0 - " << points.size() - 1 << "): ";
                int index2;
                cin >> index2;

                if (index1 < 0 || index1 >= points.size() || index2 < 0 || index2 >= points.size()) {
                    cout << "Неверный индекс точки!\n";
                    break;
                }

                double dist = distance(points[index1], points[index2]);
                cout << "Расстояние между точкой " << index1 << " и точкой " << index2 << " = "
                     << fixed << setprecision(2) << dist << endl;
                break;
            }

            case 3: {
                cout << "Вывод координат точки." << endl;

                if (points.empty()) {
                    cout << "Список точек пуст.\n";
                    break;
                }

                cout << "Выберите точку (0 - " << points.size() - 1 << "): ";
                int index;
                cin >> index;

                if (index < 0 || index >= points.size()) {
                    cout << "Неверный индекс точки!\n";
                    break;
                }

                cout << "Координаты точки " << index << ": ";
                coordinates(points[index]);
                break;
            }

            case 4: {
                cout << "Перемещение точки." << endl;

                if (points.empty()) {
                    cout << "Список точек пуст.\n";
                    break;
                }

                cout << "Выберите точку для перемещения (0 - " << points.size() - 1 << "): ";
                int index;
                cin >> index;

                if (index < 0 || index >= points.size()) {
                    cout << "Неверный индекс точки!\n";
                    break;
                }

                double dx, dy;
                cout << "Введите смещение по оси x: ";
                cin >> dx;
                cout << "Введите смещение по оси y: ";
                cin >> dy;

                cout << "До перемещения: ";
                coordinates(points[index]);
                to_move(points[index], dx, dy);
                cout << "После перемещения: ";
                coordinates(points[index]);
                break;
            }

            case 5: {
                cout << "Вычисление площади многоугольника" << endl;

                if (points.size() < 3) {
                    cout << "Для вычисления площади нужно минимум 3 точки.\n";
                    break;
                }

                double area = square(points);
                cout << "Площадь многоугольника из " << points.size()
                     << " точек = " << fixed << setprecision(2) << area << endl;
                break;
            }

            case 6: {
                cout << "Вывод списка введённых точек." << endl;
                if (points.empty()) {
                    cout << "Список точек пуст.\n";
                    break;
                }

                cout << "\nСписок всех точек (" << points.size() << "):\n";
                for (int i = 0; i < points.size(); i++) {
                    cout << "Точка № " << i << ": ";
                    coordinates(points[i]);
                }
                break;
            }

            default: {
                cout << "Неверный выбор. Выберите действие от 0 до 6.\n";
                break;
            }
        }

    } while (choice != 0);
}