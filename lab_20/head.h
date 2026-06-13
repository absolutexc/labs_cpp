// #ifndef HEAD_H
// #define HEAD_H
//
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>
// #include <algorithm>
// #include <string>
// #include <limits>
// #include <iomanip>
//
//
// class LineSegment {
// private:
//     double x, y;
//
// public:
//     LineSegment();
//     LineSegment(double x1, double y1);
//     LineSegment(const LineSegment& other);
//
//     double getX() const;
//     double getY() const;
//     void setX(double newX);
//     void setY(double newY);
//
//     bool is_crossing(const LineSegment& other) const;
//
//     friend std::ostream& operator<<(std::ostream& os, const LineSegment& ls);
//
//     // Перегруженные операции (задача 2)
//     double operator!() const;                           // унарный ! - длина
//     LineSegment operator++();                           // префиксный ++
//     LineSegment operator++(int);                        // постфиксный ++
//     operator int() const;                               // неявное приведение к int
//     operator double() const;                   // явное приведение к double
//     LineSegment operator-(int d) const;                 // бинарный - (целое число)
//     bool operator<(const LineSegment& other) const;     // бинарный < (пересечение)
// };
//
// double inputDouble(const std::string& prompt);
// int inputInt(const std::string& prompt);
//
// int showInputMenu();
// LineSegment create1LineSegmentFromChoice(int choice);
// LineSegment create2LineSegmentFromChoice(int choice);
//
// LineSegment inputFromConsole();
// LineSegment inputRandom();
// LineSegment inputFromFile(const std::string& filename);
//
// void showOperationsMenu(LineSegment& ls, LineSegment& ls2);
//
// #endif