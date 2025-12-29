// #include "tasks.h"
//
// void Sort11() {
//     cout << "Сортировка простыми вставками" << endl;
//
//     int n;
//
//     do {
//         cout << "Введите количество элементов массива: ";
//         cin >> n;
//         if (n<=0) {
//             cout << "Введите корректное число кол-ва элементов" << endl;
//         }
//     } while (n<=0);
//
//     vector<int> arr(n);
//     cout << "Введите " << n << " целых чисел:" << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//
//     ofstream f_out("sort_protocol.txt");
//
//     if (!f_out) {
//         cout << "Ошибка открытия файла!" << endl;
//         return;
//     }
//
//     f_out << "Исходный массив: ";
//     for (int i = 0; i < n; i++) {
//         f_out << arr[i] << " ";
//     }
//     f_out << "\n\nПротокол сортировки:" << endl;
//
//     for (int i = n-2; i >= 0; i--) {
//         int key = arr[i];
//         int j = i + 1;
//
//         while (j < n && arr[j] < key) {
//             arr[j-1] = arr[j];
//             j++;
//         }
//         arr[j-1] = key;
//
//         for (int k = 0; k < n; k++) {
//             if (k == i) {
//                 f_out << "| ";
//             }
//             f_out << arr[k] << " ";
//         }
//         f_out << "\n";
//     }
//
//     f_out << "\nОтсортированный массив: ";
//     for (int i = 0; i < n; i++) {
//         f_out << arr[i] << " ";
//     }
//
//     f_out.close();
//     cout << "Протокол сортировки сохранен в файл 'sort_protocol.txt'\n";
// }