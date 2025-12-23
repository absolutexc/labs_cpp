#include "points_2d.h"
#include <iostream>
#include <cmath>
#include <iomanip>

double distance(const Point& a, const Point& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void coordinates(const Point& p) {
    using namespace std;
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

void to_move(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double square(const vector<Point>& polygon) {
    int n = polygon.size();
    if (n < 3) {
        return 0.0;
    }

    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y;
        area -= polygon[i].y * polygon[j].x;
    }

    return abs(area) / 2.0;
}

void print_points_menu() {
    using namespace std;
    cout << "Работа с точками в 2D пространстве." << endl;
    cout << "\n1. Добавить точку\n";
    cout << "2. Вычислить расстояние между двумя точками\n";
    cout << "3. Вывести координаты точки\n";
    cout << "4. Переместить точку\n";
    cout << "5. Вычислить площадь многоугольника\n";
    cout << "6. Показать все точки\n";
    cout << "0. Выход из программы\n";
    cout << endl;
    cout << "Выберите действие: \n";
}