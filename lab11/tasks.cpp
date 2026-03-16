#include "head.h"

void task_listwork68() {
  std::cout << "Задача 1. ListWork68" << std::endl;

  std::vector<int> data = get_data_method();

  if (data.empty()) {
    std::cout << "Нет данных для работы!" << std::endl;
    return;
  }

  CyclicList list;
  std::cout << "/Заполнение списка/" << std::endl;
  for (int num : data) {
    list.push_back(num);
    std::cout << "Добавлен элемент " << num << std::endl;
  }

  std::cout << "\n/Исходный список/" << std::endl;
  if (list.is_empty()) {
    std::cout << "Список пуст" << std::endl;
  }
  else {
    Node* temp = list.get_head();
    do {
      std::cout << temp->data << " ";
      temp = temp->next;
    } while (temp != list.get_head());
    std::cout << std::endl;
  }
  std::cout << "Размер списка: " << list.get_size() << std::endl;

  std::ofstream out_file("output_listwork68.txt");
  if (!out_file.is_open()) {
    std::cout << "Ошибка создания файла output_listwork68.txt!" << std::endl;
    return;
  }

  Node* current = list.get_head();
  int count = 0;

  std::vector<int> result;

  while (!list.is_empty()) {
    for (int i = 0; i < count * 4; i++) {
      current = current->next;
    }

    result.push_back(current->data);

    out_file << current->data;

    Node* to_remove = current;
    current = current->next;
    list.remove(to_remove);
    count++;

    if (!list.is_empty()) {
      out_file << " ";
    }
    else {
      out_file << std::endl;
    }
  }

  out_file.close();

  std::cout << "\n/Результат/" << std::endl;
  std::cout << "Последовательность, записанная в файл: ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i];
    std::cout << " ";
  }
  std::cout << std::endl;

  std::cout << "Результат сохранен в файл output_listwork68.txt" << std::endl;

  std::cout << std::endl;
  std::cout << "/Список после обработки/";
  std::cout << std::endl;
  if (list.is_empty()) {
    std::cout << "Список пуст" << std::endl;
  }
  else {
    std::cout << "Список не пуст" << std::endl;
  }

  std::cout << std::endl;
}

void task_listwork42() {
  std::cout << "Задача 2. ListWork42" << std::endl;

  std::vector<int> data = get_data_method();

  if (data.empty()) {
    std::cout << "Нет данных для работы!" << std::endl;
    return;
  }

  DoublyCyclicList list;
  std::cout << "\n/Заполнение списка/" << std::endl;
  for (int num : data) {
    list.push_back(num);
    std::cout << "Добавлен элемент " << num << std::endl;
  }

  std::cout << "\n/Исходный список/" << std::endl;
  list.print();
  std::cout << "Размер списка: " << list.get_size() << std::endl;
  std::cout << "Указатель на первый элемент: " << list.get_head() << std::endl;

  if (!list.is_empty()) {
    std::cout << "Последний элемент до обработки: " << list.get_head()->prev->data << std::endl;
    std::cout << "Указатель на последний элемент: " << list.get_head()->prev << std::endl;
  }

  std::cout << "\n/Обработка списка/" << std::endl;

  Node* last_element = list.process_task_42();

  std::cout << "\n/Результат/" << std::endl;
  std::cout << "Результирующий список: ";
  list.print();
  std::cout << "Размер списка после обработки: " << list.get_size() << std::endl;

  if (last_element != nullptr) {
    std::cout << "Последний элемент: " << last_element->data << std::endl;
    std::cout << "Указатель на последний элемент (P2): " << last_element << std::endl;
  }
  else {
    std::cout << "Список пуст после обработки" << std::endl;
  }

  std::cout << "\n/Анализ/" << std::endl;
  if (data.size() != list.get_size()) {
    std::cout << "Было удалено " << data.size() - list.get_size() << " элементов" << std::endl;

    std::cout << "Элементы, у которых левый и правый сосед совпадают: ";
    for (int i = 0; i < data.size(); i++) {
      int left = data[(i - 1 + data.size()) % data.size()];
      int right = data[(i + 1) % data.size()];
      if (left == right) {
        std::cout << data[i] << " ";
      }
    }
    std::cout << std::endl;
  }
  else {
    std::cout << "Ни один элемент не был удален" << std::endl;
  }

  std::cout << std::endl;
}

void task_listwork64() {
  std::cout << "Задача 3. ListWork64" << std::endl;

  std::vector<int> data = get_data_method();

  if (data.empty()) {
    std::cout << "Нет данных для работы!" << std::endl;
    return;
  }

  DoublyList list;
  std::cout << "/Заполнение списка/" << std::endl;
  for (int num : data) {
    list.push_back(num);
    std::cout << "Добавлен элемент " << num << std::endl;
  }

  std::cout << "\n/Исходный список/" << std::endl;
  list.print();
  std::cout << "Указатель на первый элемент: " << list.get_head() << std::endl;

  std::cout << "\n/Обработка списка/" << std::endl;

  list.process_task_64("output_listwork64.txt");

  std::cout << std::endl;
}

void task_listwork47() {
  std::cout << "Задача 4. ListWork47" << std::endl;

  TListB list;

  std::vector<int> data = get_data_method();

  if (data.empty()) {
    std::cout << "Нет данных для исходного списка!" << std::endl;
  }
  else {
    std::cout << "Добавление элементов в список:" << std::endl;
    for (int num : data) {
      BarrierLast::lb_insert_last(list, num);
      std::cout << "Добавлен элемент " << num << std::endl;
    }
  }

  std::cout << "\n/Исходный список/" << std::endl;
  std::cout << "Список: ";
  BarrierLast::print(list);
  std::cout << "Указатель на барьерный элемент (P1): " << list.barrier << std::endl;

  if (!list.is_empty()) {
    std::cout << "Первый элемент: " << list.barrier->next->data << std::endl;
    std::cout << "Последний элемент: " << list.barrier->prev->data << std::endl;
  }
  else {
    std::cout << "Исходный список пуст" << std::endl;
  }

  int N;
  std::cout << "\nВведите количество элементов для добавления (N > 0): ";
  std::cin >> N;

  if (N <= 0) {
    std::cout << "Ошибка! N должно быть положительным числом." << std::endl;
    return;
  }

  std::vector<int> new_numbers;
  std::cout << "Введите числа: ";
  std::cout << std::endl;
  for (int i = 0; i < N; i++) {
    int value;
    std::cin >> value;
    new_numbers.push_back(value);
  }

  std::cout << "/Добавление элементов/" << std::endl;
  for (int i = 0; i < N; i++) {
    BarrierLast::lb_insert_last(list, new_numbers[i]);
    std::cout << "Добавлен элемент " << new_numbers[i] << " в конец списка" << std::endl;
    std::cout << "Текущий элемент: " << list.current->data << " (адрес: " << list.current << ")" << std::endl;
  }

  std::cout << "\n/Результат/" << std::endl;
  if (list.current != nullptr) {
    BarrierLast::print(list);
    // std::cout << "Адрес текущего элемента: " << list.current << std::endl;
    std::cout << "Значение текущего элемента: " << list.current->data << std::endl;
    std::cout << "Это последний добавленный элемент." << std::endl;
  }
  else {
    std::cout << "Текущий элемент не определен (список пуст?)" << std::endl;
  }

  std::cout << std::endl;
}

void task5() {
  std::cout << "Задача 5.5\n";

  std::vector<int> data = get_data_method();

  if (data.empty()) {
    std::cout << "Нет данных для работы!" << std::endl;
    return;
  }

  CyclicList list;
  std::cout << "/Заполнение списка/" << std::endl;
  for (int num : data) {
    list.push_back(num);
    std::cout << "Добавлен элемент " << num << std::endl;
  }

  std::cout << "\n/Исходный список/" << std::endl;
  std::cout << "Список: ";
  list.print();
  std::cout << "Размер списка: " << list.get_size() << std::endl;

  std::cout << "\n/Поиск максимальной возрастающей последовательности/" << std::endl;

  std::vector<int> sequence = list.find_max_increasing();

  std::cout << "\n/Результат/" << std::endl;
  if (sequence.empty()) {
    std::cout << "Последовательность не найдена (список пуст)" << std::endl;
  }
  else {
    std::cout << "Максимальная возрастающая последовательность (длина " << sequence.size() << "):" << std::endl;
    for (size_t i = 0; i < sequence.size(); i++) {
      std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}