#ifndef CPP_2D_POINTS_H
#define CPP_2D_POINTS_H

#include <vector>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b);
void coordinates(const Point& p);
void to_move(Point& p, double dx, double dy);
double square(const vector<Point>& polygon);
void print_points_menu();

void points_2d_task();

#endif //CPP_2D_POINTS_H