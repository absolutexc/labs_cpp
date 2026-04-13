#include "head.h"

// Point
Point::Point(int x, int y) : x_coord(x), y_coord(y) {}

Point::Point(const Point& other) : x_coord(other.x_coord), y_coord(other.y_coord) {}

void Point::print() const{
    std::cout << "{" << x_coord << ";" << y_coord << "}" << std::endl;
}

int Point::GetX() const { return x_coord; }
int Point::GetY() const { return y_coord; }
void Point::SetX(int x) { x_coord = x; }
void Point::SetY(int y) { y_coord = y; }

// Line
Line::Line(const Point& start, const Point& end) : point_start(start), point_end(end) {}

Line::Line(int x1, int y1, int x2, int y2) : point_start(x1, y1), point_end(x2, y2) {}

Line::Line(const Line& other) : point_start(other.point_start), point_end(other.point_end) {}

void Line::print() const {
    std::cout << "Линия от ";
    point_start.print();
    std::cout << " до ";
    point_end.print();
}

Point Line::get_start() const { return point_start; }
Point Line::get_end() const { return point_end; }

void Line::set_start(const Point& p) { point_start = p; }
void Line::set_end(const Point& p) { point_end = p; }

// Student

Student::Student(const std::string& name, const std::vector<int>& grades)
    : stud_name(name), stud_grades(grades) {}

Student::Student(const Student& other)
    : stud_name(other.stud_name), stud_grades(other.stud_grades) {}

void Student::print() const {
    std::cout << stud_name << ": [";
    for (int i = 0; i < stud_grades.size(); i++) {
        std::cout << stud_grades[i];
        if (i != stud_grades.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

std::string Student::GetName() const { return stud_name; }
std::vector<int> Student::GetGrades() const { return stud_grades; }

void Student::SetName(const std::string& name) { stud_name = name; }
void Student::SetGrades(const std::vector<int>& grades) { stud_grades = grades; }

// PointSec
PointSec::PointSec(int x, int y) : x_coord(x), y_coord(y) {}

PointSec::PointSec(const PointSec& other) : x_coord(other.x_coord), y_coord(other.y_coord) {}

void PointSec::print() const {
    std::cout << "{" << x_coord << ";" << y_coord << "}";
}

int PointSec::GetX() const { return x_coord; }
int PointSec::GetY() const { return y_coord; }

// LineSec
LineSec::LineSec(const PointSec& start, const PointSec& end)
    : point_start(start), point_end(end) {}

LineSec::LineSec(int x1, int y1, int x2, int y2)
    : point_start(x1, y1), point_end(x2, y2) {}

LineSec::LineSec(const LineSec& other)
    : point_start(other.point_start), point_end(other.point_end) {}

void LineSec::print() const {
    std::cout << "Линия от ";
    point_start.print();
    std::cout << " до ";
    point_end.print();
}

PointSec LineSec::get_start() const { return point_start; }
PointSec LineSec::get_end() const { return point_end; }

void LineSec::set_start(const PointSec& p) { point_start = p; }
void LineSec::set_end(const PointSec& p) { point_end = p; }

double LineSec::Length() const {
    int dx = point_end.GetX() - point_start.GetX();
    int dy = point_end.GetY() - point_start.GetY();
    return std::sqrt(dx * dx + dy * dy);
}