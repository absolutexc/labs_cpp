#include "head.h"

void task_dynamic13() {
    std::cout << "Задача 1. Dynamic13" << std::endl;

    std::vector<int> data = get_data_method();

    if (data.empty()) {
        std::cout << "Нет данных для работы!" << std::endl;
        return;
    }

    TStack stack;
    std::cout << "\nЗаполнение стека" << std::endl;
    for (int num : data) {
        stack.push(num);
        std::cout << "Добавлен элемент " << num << std::endl;
    }

    std::cout << "\n--- Исходный стек ---" << std::endl;
    stack.print();
    std::cout << "Размер стека: " << stack.get_size() << std::endl;
    std::cout << "Вершина стека: " << stack.peek() << std::endl;
    std::cout << "Адрес вершины: " << stack.get_top() << std::endl;

    std::cout << "\n--- Проверка is_empty ---" << std::endl;
    std::cout << "Стек пуст? " << (stack.is_empty() ? "Да" : "Нет") << std::endl;

    // Извлекаем элементы
    int elements_to_extract = std::min(5, stack.get_size());
    std::cout << "\n--- Извлечение элементов ---" << std::endl;

    for (int i = 0; i < elements_to_extract; i++) {
        if (!stack.is_empty()) {
            int value = stack.pop();
            std::cout << "Извлечен элемент " << value << std::endl;
        }
    }

    std::cout << "\n--- Результат после извлечения ---" << std::endl;
    std::cout << "Стек пуст? " << (stack.is_empty() ? "Да" : "Нет") << std::endl;

    if (!stack.is_empty()) {
        std::cout << "Значение новой вершины: " << stack.peek() << std::endl;
        std::cout << "Адрес новой вершины: " << stack.get_top() << std::endl;
        std::cout << "Оставшиеся элементы: ";
        stack.print();
    }
    else {
        std::cout << "Стек стал пустым" << std::endl;
    }

    std::cout << std::endl;
}

void task_dynamic14() {
    std::cout << "Задача 2. Dynamic14" << std::endl;

    std::vector<int> data = get_data_method();

    if (data.empty()) {
        std::cout << "Нет данных для работы!" << std::endl;
        return;
    }

    std::vector<int> queue_data = data;
    if (queue_data.size() > 10) {
        queue_data.resize(10);
        std::cout << "\nИспользуем первые 10 чисел для очереди." << std::endl;
    }
    else {
        std::cout << "\nИспользуем все " << queue_data.size() << " чисел." << std::endl;
    }

    TQueue queue;
    std::cout << "\n--- Заполнение очереди ---" << std::endl;
    for (int num : queue_data) {
        queue.enqueue(num);
        std::cout << "Добавлен в конец: " << num << std::endl;
    }

    std::cout << "\n--- Созданная очередь ---" << std::endl;
    queue.print();
    std::cout << "Размер очереди: " << queue.get_size() << std::endl;
    std::cout << "Первый элемент: " << queue.first() << std::endl;
    std::cout << "Последний элемент: " << queue.last() << std::endl;

    std::cout << "\n--- Указатели ---" << std::endl;
    std::cout << "Указатель на начало (P1): " << queue.get_head() << std::endl;
    std::cout << "Указатель на конец (P2): " << queue.get_tail() << std::endl;

    std::cout << "\n--- Демонстрация операций с очередью ---" << std::endl;

    int elements_to_extract = std::min(3, queue.get_size());
    std::cout << "Извлекаем " << elements_to_extract << " элемента из начала:" << std::endl;

    for (int i = 0; i < elements_to_extract; i++) {
        if (!queue.is_empty()) {
            int value = queue.dequeue();
            std::cout << "Извлечен: " << value << std::endl;
        }
    }

    std::cout << "\nОчередь после извлечения:" << std::endl;
    queue.print();

    std::cout << "\nДобавляем новые элементы:" << std::endl;
    queue.enqueue(99);
    std::cout << "Добавлен 99" << std::endl;
    queue.enqueue(100);
    std::cout << "Добавлен 100" << std::endl;

    std::cout << "\nОчередь после добавления:" << std::endl;
    queue.print();
    std::cout << "Новый указатель на конец: " << queue.get_tail() << std::endl;

    std::cout << std::endl;
}

void task_listwork11() {
    std::cout << "Задача 3. ListWork11" << std::endl;

    std::vector<int> data = get_data_method();

    if (data.empty()) {
        std::cout << "Нет данных для работы!" << std::endl;
        return;
    }

    TList list;
    std::cout << "\n--- Создание списка ---" << std::endl;
    for (int num : data) {
        list.insert_at_end(num);
    }

    std::cout << "\n--- Исходный список ---" << std::endl;
    list.print();
    std::cout << "Указатель P1 (голова списка): " << list.get_head() << std::endl;

    std::cout << "\n--- Поиск первого элемента, кратного 5 ---" << std::endl;
    TNode* px = list.find_first_multiple_of(5);

    if (px) {
        std::cout << "Элемент найден!" << std::endl;
        std::cout << "Значение: " << px->Data << std::endl;
        std::cout << "Указатель Px: " << px << std::endl;

        int position = 1;
        TNode* current = list.get_head();
        while (current && current != px) {
            position++;
            current = current->Next;
        }
        std::cout << "Позиция в списке: " << position << std::endl;

    }
    else {
        std::cout << "Элемент, кратный 5, не найден!" << std::endl;
        std::cout << "Указатель Px = nullptr" << std::endl;
    }

    std::cout << std::endl;
}

void task_listwork24() {
    std::cout << "Задача 4. ListWork24" << std::endl;

    std::vector<int> data = get_data_method();

    if (data.empty()) {
        std::cout << "Нет данных для работы!" << std::endl;
        return;
    }

    TList list;
    for (int num : data) {
        list.insert_at_end(num);
    }

    std::cout << "\n--- Исходный список ---" << std::endl;
    list.print();
    std::cout << "Указатель P1 (голова списка): " << list.get_head() << std::endl;
    std::cout << "Размер списка: " << list.get_size() << std::endl;

    int value_to_insert;
    std::cout << "\nВведите значение для вставки после каждого 4-го элемента: ";
    std::cin >> value_to_insert;

    std::cout << "\n--- Вставка значения " << value_to_insert
              << " после каждого четвертого элемента ---" << std::endl;
    list.insert_after_every_fourth(value_to_insert);

    std::cout << "\n--- Результирующий список ---" << std::endl;
    list.print();
    std::cout << "Новый размер списка: " << list.get_size() << std::endl;

    TNode* last = list.get_last();
    std::cout << "\n--- Результат (по заданию ListWork24) ---" << std::endl;
    std::cout << "Указатель на последний элемент P2: " << last << std::endl;
    if (last) {
        std::cout << "Значение последнего элемента: " << last->Data << std::endl;
    }

    std::cout << "Элементы, после которых были вставки:" << std::endl;

    int pos = 1;
    TNode* current = list.get_head();
    while (current) {
        if (pos % 5 == 0) {
            std::cout << "  Позиция " << pos << ": " << current->Data
                      << " (вставленный)" << std::endl;
        }
        else {
            std::cout << "  Позиция " << pos << ": " << current->Data << std::endl;
        }
        current = current->Next;
        pos++;
    }

    std::cout << std::endl;
}