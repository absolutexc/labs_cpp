// #include "head.h"
//
// // menu
//
// void print_menu() {
//     std::cout << "Меню:" << std::endl;
//     std::cout << "1. STL2Seq2." << std::endl;
//     std::cout << "2. STL2Seq10." << std::endl;
//     std::cout << "3. STL2Seq33." << std::endl;
//     std::cout << "4. STL1Iter9." << std::endl;
//     std::cout << "0. Выход из программы." << std::endl;
//     std::cout << std::endl;
//     std::cout << "Выберите пункт меню:" << std::endl;
// }
//
// // Функции для заполнения контейнеров ---------------------------------
//
// void fill_from_file(std::list<int>& lst) {
//     lst.clear();
//
//     std::string filename;
//     std::cout << "Введите имя файла: ";
//     std::cout << std::endl;
//     std::cin >> filename;
//
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cout << "Файл " << filename << " не найден. Введите название ещё раз." << std::endl;
//         fill_from_file(lst);
//     }
//
//     std::copy(std::istream_iterator<int>(file),
//               std::istream_iterator<int>(),
//               std::back_inserter(lst));
//     file.close();
//
//     if (lst.empty()) {
//         std::cout << "Файл пуст." << std::endl;
//     }
//     else {
//         std::cout << "Кол-во чисел файла: " << filename << ": "<< lst.size() << std::endl;
//     }
// }
//
// void fill_from_console(std::list<int>& lst) {
//     lst.clear();
//     std::cout << "Сколько чисел вы хотите ввести?" << std::endl;
//
//     int count = get_positive();
//
//     std::cout << "Введите " << count << " целых чисел:\n";
//
//     for (int i = 0; i < count; ++i) {
//         int num;
//         bool validInput = false;
//
//         do {
//             if (std::cin >> num) {
//                 lst.push_back(num);
//                 validInput = true;
//             }
//             else {
//                 std::cout << "Ошибка: введите корректные числа. Попробуйте снова: ";
//                 clear_input();
//             }
//         } while (!validInput);
//     }
// }
//
// void fill_random(std::list<int>& lst) {
//     lst.clear();
//
//     std::cout << "Сколько чисел вы хотите ввести?" << std::endl;
//
//     int count = get_positive();
//
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 100);
//
//     for (int i = 0; i < count; ++i) {
//         lst.push_back(dis(gen));
//     }
// }
//
// // Функции для заполнения файла ---------------------------------
//
// void fill_file_cons() {
//     std::ofstream file("name.txt");
//     if (!file.is_open()) {
//         std::cout << "Ошибка: не удалось создать файл name\n";
//         return;
//     }
//
//     std::cout << "Сколько чисел вы хотите ввести?" << std::endl;
//
//     int count = get_positive();
//
//     std::cout << "Введите " << count << " целых чисел:\n";
//
//     std::vector<int> numbers;
//     for (int i = 0; i < count; ++i) {
//         int num;
//         bool validInput = false;
//
//         do {
//             if (std::cin >> num) {
//                 numbers.push_back(num);
//                 validInput = true;
//             }
//             else {
//                 std::cout << "Ошибка: введите корректное число. Попробуйте снова: ";
//                 clear_input();
//             }
//         } while (!validInput);
//     }
//
//     // Записываем числа в файл
//     for (int num : numbers) {
//         file << num << " ";
//     }
//
//     file.close();
//     std::cout << "Записано " << numbers.size() << " чисел в файл name\n";
// }
//
// void fill_file_random(){
//     std::ofstream file("name.txt");
//     if (!file.is_open()) {
//         std::cout << "Ошибка: не удалось создать файл name\n";
//         return;
//     }
//
//     std::cout << "Сколько чисел вы хотите сгенерировать?" << std::endl;
//
//     int count = get_positive();
//
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 100);
//
//     for (int i = 0; i < count; ++i) {
//         file << dis(gen) << " ";
//     }
//
//     file.close();
//     std::cout << "Сгенерировано " << count << " случайных чисел (от 1 до 100) в файл name\n";
// }
//
// void fill_by_file() {
//     std::string sourceFilename;
//     std::cout << "Введите имя исходного файла: ";
//     std::cin >> sourceFilename;
//
//     std::ifstream sourceFile(sourceFilename);
//     if (!sourceFile.is_open()) {
//         std::cout << "Ошибка: не удалось открыть файл " << sourceFilename << std::endl;
//         return;
//     }
//
//     std::ofstream destFile("name");
//     if (!destFile.is_open()) {
//         std::cout << "Ошибка: не удалось создать файл name\n";
//         sourceFile.close();
//         return;
//     }
//
//     std::copy(std::istream_iterator<int>(sourceFile),
//               std::istream_iterator<int>(),
//               std::ostream_iterator<int>(destFile, " "));
//
//     sourceFile.close();
//     destFile.close();
//
//     std::cout << "Данные скопированы из файла " << sourceFilename << " в файл name\n";
// }
//
// int get_file_choice() {
//     int choice;
//     bool validInput = false;
//
//     do {
//         std::cout << "\nВыберите способ заполнения файла name:\n";
//         std::cout << "1. Ввести с консоли\n";
//         std::cout << "2. Сгенерировать случайные числа\n";
//         std::cout << "3. Скопировать из другого файла\n";
//         std::cout << "Ваш выбор: ";
//         std::cout << std::endl;
//
//         if (std::cin >> choice) {
//             if (choice >= 1 && choice <= 3) {
//                 validInput = true;
//             }
//             else {
//                 std::cout << "Ошибка: введите число от 1 до 3.\n";
//             }
//         }
//         else {
//             std::cout << "Ошибка: введите корректное число.\n";
//             clear_input();
//         }
//     } while (!validInput);
//
//     return choice;
// }
//
// void fill_file() {
//     int choice = get_file_choice();
//
//     switch(choice) {
//         case 1:
//             fill_file_cons();
//             break;
//         case 2:
//             fill_file_random();
//             break;
//         case 3:
//             fill_by_file();
//             break;
//     }
// }
//
// void print_file(std::string& filename) {
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cout << "Не удалось открыть файл " << filename << std::endl;
//         return;
//     }
//
//     std::cout << "Содержимое файла " << filename << ":\n";
//     std::cout << "Все числа: ";
//     std::copy(std::istream_iterator<int>(file),
//               std::istream_iterator<int>(),
//               std::ostream_iterator<int>(std::cout, " "));
//     std::cout << std::endl;
//     file.close();
// }
//
// // Вспомогательные функции --------------------------------
//
// void clear_input() {
//     std::cin.clear();
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }
//
// int get_positive() {
//     int number;
//     bool validInput = false;
//
//     do {
//         if (std::cin >> number) {
//             if (number > 0) {
//                 validInput = true;
//             }
//             else {
//                 std::cout << "Ошибка: введите положительное число.\n";
//             }
//         }
//         else {
//             std::cout << "Ошибка: введите корректное число.\n";
//             clear_input();
//         }
//     } while (!validInput);
//
//     return number;
// }
//
// void print_list(const std::list<int>& L, const std::string& title) {
//     std::cout << title << ": ";
//     for (auto it = L.begin(); it != L.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }
//
// // Функции для выбора способа заполнения с проверкой ввода
//
// int get_data_choice() {
//     int choice;
//     bool validInput = false;
//
//     do {
//         std::cout << "\nВыберите способ заполнения:\n";
//         std::cout << "1. Из консоли\n";
//         std::cout << "2. Случайными числами\n";
//         std::cout << "3. Из файла\n";
//         std::cout << "Ваш выбор:\n";
//
//         if (std::cin >> choice) {
//             if (choice >= 1 && choice <= 3) {
//                 validInput = true;
//             } else {
//                 std::cout << "Ошибка: введите число от 1 до 3.\n";
//             }
//         }
//         else {
//             std::cout << "Ошибка: введите корректное число.\n";
//             clear_input();
//         }
//     } while (!validInput);
//
//     return choice;
// }
//
// void fill_list(std::list<int>& lst, int choice) {
//     switch (choice) {
//         case 1:
//             fill_from_console(lst);
//             std::cout << "Список заполнен из консоли." << std::endl;
//             break;
//         case 2:
//             fill_random(lst);
//             std::cout << "Список заполнен случайными числами." << std::endl;
//             break;
//         case 3:
//             fill_from_file(lst);
//             std::cout << "Список заполнен из файла." << std::endl;
//             break;
//     }
// }
//
// // Для задания 2
//
// bool is_divisible_by_3(int number){
//     return number % 3 == 0;
// }
//
// // Для задания 3
//
// bool is_even(int number) {
//     return number % 2 == 0;
// }
