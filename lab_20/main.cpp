// #include "head.h"
//
// void print_cat() {
//     std::cout << "\n";
//     std::cout << "  /\\_/\\\n";
//     std::cout << " ( o.o )\n";
//     std::cout << "  > ^ <\n";
//     std::cout << "\n  Мяу!\n";
// }
//
// int main() {
//     using namespace std;
//     cout << "Вариант 11. LineSegment" << endl;
//
//     cout << "\nЗадание 1." << endl;
//     cout << "Создание первого отрезка:" << endl;
//     int choice = showInputMenu();
//     LineSegment segment1 = create1LineSegmentFromChoice(choice);
//
//     cout << "Создание второго отрезка:" << endl;
//     int choice2 = showInputMenu();
//     LineSegment segment2 = create2LineSegmentFromChoice(choice2);
//
//     cout << "\nРезультат проверки пересечения:" << endl;
//     cout << "Первый отрезок: " << segment1 << endl;
//     cout << "Второй отрезок: " << segment2 << endl;
//     cout << "Отрезки пересекаются? " << (segment1.is_crossing(segment2) ? "\nДа, отрезки пересекаются" : "\nНет, отрезки не пересекаются") << endl;
//
//     cout << "\nЗадача 2." << endl;
//     cout << "Отрезок: " << segment1 << endl;
//
//     showOperationsMenu(segment1, segment2);
//
//     print_cat();
//
//     return 0;
// }