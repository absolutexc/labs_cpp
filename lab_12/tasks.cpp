// #include "head.h"
//
// void task1() {
//     std::cout << "Задача 1. STL2Seq2\n";
//
//     std::list<int> L;
//
//     int choice = get_data_choice();
//
//     fill_list(L, choice);
//
//     if (L.empty()) {
//         std::cout << "\nСписок пуст. Невозможно выполнить вывод." << std::endl;
//         return;
//     }
//
//     std::cout << "\nИсходный порядок:\n";
//     for (auto it = L.begin(); it != L.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
//
//     std::cout << "\nОбратный порядок:\n";
//     for (auto rit = L.rbegin(); rit != L.rend(); ++rit) {
//         std::cout << *rit << " ";
//     }
//     std::cout << std::endl;
//     std::cout << std::endl;
// }
//
// void task2() {
//     std::cout << "Задача 2. STL2Seq10\n";
//
//     std::list<int> L;
//     bool valid_size = false;
//
//     while (!valid_size) {
//         int choice = get_data_choice();
//         fill_list(L, choice);
//
//         if (L.empty()) {
//             std::cout << "Список пуст. Попробуйте снова.\n";
//             continue;
//         }
//
//         if (L.size() % 3 == 0) {
//             valid_size = true;
//             std::cout << "Размер списка: " << L.size() << "\n";
//         }
//         else {
//             std::cout << "Ошибка: размер списка = " << L.size() << ", он не кратен 3.\n";
//             std::cout << "Введите другое количество чисел.\n\n";
//             L.clear();
//         }
//     }
//
//     print_list(L, "Исходный список");
//
//     int tretb = L.size() / 3;
//     std::cout << "\nПервая треть: ";
//
//     auto it = L.begin();
//     for (int i = 0; i < tretb; ++i) {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << std::endl;
//
//     it = L.begin();
//     std::advance(it, tretb);
//     std::list<int> first_third(L.begin(), it);
//
//     L.insert(L.end(), first_third.rbegin(), first_third.rend());
//
//     // Результат
//     print_list(L, "L после добавления");
//     std::cout << std::endl;
// }
//
// void task3() {
//     std::cout << "Задание 3. STL2Seq33\n";
//
//     std::list<int> L;
//     bool valid_size = false;
//
//     while (!valid_size) {
//         int choice = get_data_choice();
//         fill_list(L, choice);
//
//         if (L.empty()) {
//             std::cout << "Список пуст. Попробуйте снова.\n";
//             continue;
//         }
//
//         if (is_even(L.size())) {
//             valid_size = true;
//             std::cout << "Размер списка: " << L.size() << " - четное число\n";
//         }
//         else {
//             std::cout << "Ошибка: размер списка " << L.size() << " не является четным.\n";
//             std::cout << "Введите четное количество чисел.\n\n";
//             L.clear();
//         }
//     }
//
//     print_list(L, "L");
//
//     auto i = L.begin();
//     auto r = --L.end();
//     int n = L.size();
//
//     // std::cout << "\nТрассировка:\n";
//
//     for (int k = 0; k < n / 2; ++k) {
//         // std::cout << "Шаг " << k + 1 << ":\n";
//         //
//         // std::cout << "  i указывает на: " << *i << " (A" << k + 1 << ")\n";
//         // std::cout << "  r указывает на: " << *r << " (A" << n - k << ")\n";
//
//         L.splice(i++, L, r--);
//     }
//
//     std::cout << "\nРезультат:\n";
//     print_list(L, "L после преобразования");
//
//     std::cout << std::endl;
// }
//
// void task4() {
//     std::cout << "Задача 4. STL1Iter9\n";
//
//     std::string filename = "name.txt";
//
//     fill_file();
//
//     std::cout << "\n";
//     print_file(filename);
//     std::cout << std::endl;
//
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cout << "Ошибка: не удалось открыть файл " << filename << std::endl;
//         return;
//     }
//
//     std::cout << "Числа с нечетными порядковыми номерами:\n";
//
//     int index = 0;
//     std::remove_copy_if(
//         std::istream_iterator<int>(file),     // начало
//         std::istream_iterator<int>(),         // конец
//         std::ostream_iterator<int>(std::cout, " "),  // вывод
//         [&index](int) {
//             ++index;
//             return index % 2 == 0;            // возвращает true для четных индексов
//         }
//     );
//
//     std::cout << std::endl;
//
//     if (index == 0) {
//         std::cout << "Файл пуст или не содержит чисел.\n";
//     }
//     else {
//         std::cout << "\nВсего чисел в файле: " << index << std::endl;
//         std::cout << "Выведено чисел: " << (index + 1) / 2 << std::endl;
//     }
//
//     file.close();
//     std::cout << std::endl;
// }