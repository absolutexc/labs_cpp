#ifndef CPP_HEAD_H
#define CPP_HEAD_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

// функции

void point_menu();
void line_menu();
void menu();
void clear_input();
int get_positive();
int get_not_neg();
std::string input_name();

// классы

class Point {
public:
    Point(int x, int y);
    Point(const Point& other);
    void print() const;

    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
private:
    int x_coord;
    int y_coord;
};

std::vector<Point> input_point_cons();
std::vector<Point> input_point_random();
std::vector<Point> input_point_file();
void print_points(const std::vector<Point>& points);

class Line {
public:
    Line(const Point& start, const Point& end);
    Line(int x1, int y1, int x2, int y2);
    Line(const Line& other);

    void print() const;

    Point get_start() const;
    Point get_end() const;

    void set_start(const Point& p);
    void set_end(const Point& p);
private:
    Point point_start, point_end;
};

Line line_from_points();
Line horizontal_line();

class Student {
public:
    Student(const std::string& name);
    Student(const std::string& name, const std::vector<int>& grades);
    Student(const Student& other);

    void print() const;

    std::string GetName() const;
    std::vector<int> GetGrades() const;

    void SetName(const std::string& name);
    void SetGrades(const std::vector<int>& grades);
private:
    std::string stud_name;
    std::vector<int> stud_grades;
};

class PointSec {
public:
    PointSec(int x, int y);
    PointSec(const PointSec& other);

    void print() const;

    int GetX() const;
    int GetY() const;

private:
    int x_coord;
    int y_coord;
};

class LineSec {
public:
    LineSec(const PointSec& start, const PointSec& end);
    LineSec(int x1, int y1, int x2, int y2);
    LineSec(const LineSec& other);

    void print() const;

    PointSec get_start() const;
    PointSec get_end() const;

    void set_start(const PointSec& p);
    void set_end(const PointSec& p);

    double Length() const;

private:
    PointSec point_start;
    PointSec point_end;
};

// задачи

void task1();
void task2();
void task3();
void task4();
void task5();

#endif