// #include "tasks.h"
//
// void ExamTaskC15() {
//     cout << "Фитнес-центр" << endl;
//
//     int k, n;
//     do {
//         cout << "Введите код клиента: " << endl;
//         cin >> k;
//
//         if (k < 10 || k > 99) {
//             cout << "Код клиента лежит в диапазоне от 10 до 99!" << endl;
//         }
//     } while (k < 10 || k > 99);
//
//     do {
//         cout << "Введите количество записей: " << endl;
//         cin >> n;
//
//         if (n < 1) {
//             cout << "Кол-во записей число положительное!" << endl;
//         }
//     } while (n < 1);
//
//     Fitness* data = new Fitness[n];
//
//     cout << "Заполнение строк в формате:" << endl;
//     cout << "<Код клиента (10-99)> <Продолжительность занятий (в часах) (1-30)> <Год (2000-2010)> <Номер месяца (1-12)>\n" << endl;
//
//     for (int i = 0; i < n; i++) {
//         do {
//             cout << "Запись " << (i+1) << ": ";
//             cin >> data[i].k >> data[i].duration >> data[i].year >> data[i].month;
//             if (data[i].k > 99 || data[i].k < 1 ||
//             data[i].duration < 1 || data[i].duration > 30 ||
//             data[i].year < 2000 || data[i].year > 2010 ||
//             data[i].month < 1 || data[i].month > 12) {
//                 cout << "Неверный ввод. Обратитесь к формату строк и повторите еще раз!" << endl;
//             }
//         } while (data[i].k > 99 || data[i].k < 1 ||
//             data[i].duration < 1 || data[i].duration > 30 ||
//             data[i].year < 2000 || data[i].year > 2010 ||
//             data[i].month < 1 || data[i].month > 12);
//
//     }
//
//     const int start_year = 2000;
//     const int end_year = 2010;
//     const int year_cnt = end_year - start_year + 1;
//
//     int best_duration[year_cnt] = {0};
//     int best_month[year_cnt] = {0};
//
//     for (int i = 0; i < n; i++) {
//         if (data[i].k == k && data[i].year >= start_year && data[i].year <= end_year) {
//             int index = data[i].year - start_year;
//
//             // обновление максимума для этого года
//             if (data[i].duration > best_duration[index]) {
//                 best_duration[index] = data[i].duration;
//                 best_month[index] = data[i].month;
//             }
//
//             else if (data[i].duration == best_duration[index] && data[i].month < best_month[index]){
//             best_month[index] = data[i].month;
//             }
//         }
//     }
//
//     cout << "\nРезультаты\n";
//
//     bool has_id = false;
//     for (int i = year_cnt; i>=0 ; i--) {
//         if (best_duration[i] > 0) {
//             cout << best_duration[i] << " " << (start_year + i) << " " << best_month[i] << endl;
//             has_id = true;
//         }
//     }
//
//     if (!has_id) {
//         cout << "Нет данных\n";
//     }
//
//     delete[] data;
// }
//
// // входные данные
// // k=99 n=9
// // 1 - 99 15 2005 6
// // 2 - 99 16 2005 7
// // 3 - 99 17 2005 8
// // 4 - 99 18 2006 5
// // 5 - 99 19 2006 4
// // 6 - 99 19 2006 3
// // 7 - 99 19 2006 2
// // 8 - 98 18 2005 9
// // 9 - 97 19 2005 10