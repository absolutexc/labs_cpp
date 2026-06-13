// #include "head.h"
//
// double inputDouble(const std::string& prompt) {
//     double value;
//     std::cout << prompt;
//     while (!(std::cin >> value)) {
//         std::cout << "Ошибка! Введите число: ";
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     }
//     return value;
// }
//
// int inputInt(const std::string& prompt) {
//     int value;
//     std::cout << prompt;
//     while (!(std::cin >> value)) {
//         std::cout << "Ошибка! Введите целое число: ";
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     }
//     return value;
// }
//
// int showInputMenu() {
//     std::cout << "\nВыбор способа ввода" << std::endl;
//     std::cout << "1. Консоль" << std::endl;
//     std::cout << "2. Случайно" << std::endl;
//     std::cout << "3. Из файла" << std::endl;
//     std::cout << "Ваш выбор:\n ";
//
//     int choice;
//     while (!(std::cin >> choice) || choice < 1 || choice > 3) {
//         std::cout << "Ошибка! Введите число от 1 до 3: ";
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     }
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     return choice;
// }
//
// LineSegment create1LineSegmentFromChoice(int choice) {
//     switch (choice) {
//         case 1:
//             return inputFromConsole();
//         case 2:
//             return inputRandom();
//         case 3:
//             return inputFromFile("input1.txt");
//         default:
//             std::cout << "Неверный выбор, используется ввод с консоли." << std::endl;
//             return inputFromConsole();
//     }
// }
//
// LineSegment create2LineSegmentFromChoice(int choice) {
//     switch (choice) {
//         case 1:
//             return inputFromConsole();
//         case 2:
//             return inputRandom();
//         case 3:
//             return inputFromFile("input2.txt");
//         default:
//             std::cout << "Неверный выбор, используется ввод с консоли." << std::endl;
//             return inputFromConsole();
//     }
// }
//
// LineSegment inputFromConsole() {
//     double x, y;
//     bool valid = false;
//
//     while (!valid) {
//         x = inputDouble("Введите x (начало отрезка): ");
//         y = inputDouble("Введите y (конец отрезка): ");
//
//         if (x <= y) {
//             valid = true;
//         }
//         else {
//             std::cout << "\nНачальная координата (" << x << ") больше конечной (" << y << ")" << std::endl;
//             std::cout << "Требуется: x (начало) <= y (конец)" << std::endl;
//             std::cout << "Повторите ввод." << std::endl;
//         }
//     }
//
//     return LineSegment(x, y);
// }
//
// LineSegment inputRandom() {
//     srand(static_cast<unsigned>(time(nullptr)));
//
//     double x, y;
//     bool valid = false;
//
//     while (!valid) {
//         x = (rand() % 201 - 100) / 10.0;
//         y = (rand() % 201 - 100) / 10.0;
//
//         if (x <= y) {
//             valid = true;
//         }
//     }
//
//     return LineSegment(x, y);
// }
//
// LineSegment inputFromFile(const std::string& filename) {
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "\nНевозможно открыть файл '" << filename << "'" << std::endl;
//         std::cerr << "Проверьте, существует ли файл и имеет ли он правильный формат." << std::endl;
//         exit(1);
//     }
//
//     double x, y;
//     file >> x >> y;
//     file.close();
//
//     if (file.fail()) {
//         std::cerr << "\nФайл '" << filename << "' содержит некорректные данные." << std::endl;
//         std::cerr << "Файл должен содержать два числа (x и y) через пробел." << std::endl;
//         exit(1);
//     }
//
//     if (x > y) {
//         std::cerr << "Начальная координата (" << x << ") больше конечной (" << y << ")" << std::endl;
//         std::cerr << "Требуется: x (начало) <= y (конец)" << std::endl;
//         std::cerr << "Исправьте данные в файле и перезапустите программу." << std::endl;
//         exit(1);
//     }
//
//     std::cout << "Загружен отрезок из файла: [" << x << ", " << y << "]" << std::endl;
//     return LineSegment(x, y);
// }
//
// void showOperationsMenu(LineSegment& ls, LineSegment& ls2) {
//     while (true) {
//         std::cout << "\nУнарные операции:" << std::endl;
//         std::cout << "  1 - ! (вычислить длину отрезка)" << std::endl;
//         std::cout << "  2 - ++ (расширить отрезок на 1 вправо и влево)" << std::endl;
//         std::cout << "Операции приведения типа:" << std::endl;
//         std::cout << "  3 - int (неявное) - целая часть координаты x" << std::endl;
//         std::cout << "  4 - double (явное) - координата y" << std::endl;
//         std::cout << "Бинарные операции:" << std::endl;
//         std::cout << "  5 - - (целое число) - уменьшить y на число" << std::endl;
//         std::cout << "  6 - < LineSegment d" << std::endl;
//         std::cout << "  0 - Выход из тестирования" << std::endl;
//         std::cout << "Выберите операцию (0-6): ";
//
//         int operation = inputInt("");
//
//         if (operation == 0) {
//             std::cout << "Конец" << std::endl;
//             break;
//         }
//
//         switch (operation) {
//             case 1: {
//                 double length = !ls;
//                 std::cout << "Отрезок: " << ls << std::endl;
//                 std::cout << "Длина: " << length << std::endl;
//                 break;
//             }
//             case 2: {
//                 std::cout << "До ++: " << ls << std::endl;
//                 ++ls;
//                 std::cout << "После ++: " << ls << std::endl;
//                 break;
//             }
//             case 3: {
//                 int intPart = ls;
//                 std::cout << "Отрезок: " << ls << std::endl;
//                 std::cout << "int(отрезок) = " << intPart << " (целая часть координаты x)" << std::endl;
//                 break;
//             }
//             case 4: {
//                 double yCoord = static_cast<double>(ls);
//                 std::cout << "Отрезок: " << ls << std::endl;
//                 std::cout << "double(отрезок) = " << yCoord << " (координата y)" << std::endl;
//                 break;
//             }
//             case 5: {
//                 int d = inputInt("Введите целое число: ");
//                 LineSegment result = ls - d;
//                 std::cout << "Исходный отрезок: " << ls << std::endl;
//                 std::cout << "Вычитаем: " << d << std::endl;
//                 std::cout << "Результат: " << result << std::endl;
//                 break;
//             }
//             case 6: {
//                 std::cout << "Первый отрезок: " << ls << std::endl;
//                 std::cout << "Второй отрезок: " << ls2 << std::endl;
//
//                 bool intersect = (ls < ls2);
//                 std::cout << "Отрезки пересекаются? " << (intersect ? "\nДа, отрезки пересекаются" : "\nНет, отрезки не пересекаются") << std::endl;
//                 break;
//             }
//             default:
//                 std::cout << "Ошибка! Выберите операцию от 0 до 6." << std::endl;
//                 break;
//         }
//     }
// }