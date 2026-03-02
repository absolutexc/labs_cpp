#include "head.h"

// TStack и Dynamic13 -------------------------------------

TStack::TStack() : top_(nullptr) {}

// Конструктор копирования
TStack::TStack(const TStack& other) : top_(nullptr) {
    if (other.is_empty()) return;

    int size = other.get_size();
    int* temp_array = new int[size];

    TNode* current = other.top_;
    for (int i = size - 1; i >= 0; i--) {
        temp_array[i] = current->Data;
        current = current->Next;
    }

    for (int i = 0; i < size; i++) {
        push(temp_array[i]);
    }

    delete[] temp_array;
}

// Деструктор
TStack::~TStack() {
    clear();
}

// Добавление элемента на вершину стека
void TStack::push(int value) {
    TNode* new_node = new TNode(value, top_);
    top_ = new_node;
}

// Удаление элемента с вершины стека
int TStack::pop() {
    if (is_empty()) {
        std::cout << "Ошибка: стек пуст!" << std::endl;
        return -1;
    }

    TNode* temp = top_;
    int value = temp->Data;
    top_ = top_->Next;
    delete temp;

    return value;
}

// Просмотр вершины без удаления
int TStack::peek() const {
    if (is_empty()) {
        std::cout << "Ошибка: стек пуст!" << std::endl;
        return -1;
    }
    return top_->Data;
}

// Проверка на пустоту
bool TStack::is_empty() const {
    return top_ == nullptr;
}

// Получение размера стека
int TStack::get_size() const {
    int size = 0;
    TNode* current = top_;
    while (current) {
        size++;
        current = current->Next;
    }
    return size;
}

// Очистка стека
void TStack::clear() {
    while (!is_empty()) {
        pop();
    }
}

// Вывод всех элементов стека
void TStack::print() const {
    if (is_empty()) {
        std::cout << "Стек пуст" << std::endl;
        return;
    }

    std::cout << "Стек (вершина -> конец): ";
    TNode* current = top_;
    while (current) {
        std::cout << current->Data << " ";
        current = current->Next;
    }
    std::cout << std::endl;
}

// TQueue и Dynamic14 -------------------------------------

// Конструктор по умолчанию
TQueue::TQueue() : head(nullptr), tail(nullptr) {}

// Конструктор копирования
TQueue::TQueue(const TQueue& other) : head(nullptr), tail(nullptr) {
    if (other.is_empty()) return;

    TNode* current = other.head;
    while (current) {
        enqueue(current->Data);
        current = current->Next;
    }
}

// Деструктор
TQueue::~TQueue() {
    clear();
}

// Добавление элемента в конец очереди
void TQueue::enqueue(int value) {
    TNode* new_node = new TNode(value);

    if (is_empty()) {
        head = tail = new_node;
    }
    else {
        tail->Next = new_node;
        tail = new_node;
    }
}

// Удаление элемента из начала очереди
int TQueue::dequeue() {
    if (is_empty()) {
        std::cout << "Ошибка: очередь пуста!" << std::endl;
        return -1;
    }

    TNode* temp = head;
    int value = temp->Data;
    head = head->Next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    return value;
}

// Просмотр первого элемента без удаления
int TQueue::first() const {
    if (is_empty()) {
        std::cout << "Ошибка: очередь пуста!" << std::endl;
        return -1;
    }
    return head->Data;
}

// Просмотр последнего элемента без удаления
int TQueue::last() const {
    if (is_empty()) {
        std::cout << "Ошибка: очередь пуста!" << std::endl;
        return -1;
    }
    return tail->Data;
}

// Проверка на пустоту
bool TQueue::is_empty() const {
    return head == nullptr;
}

// Получение размера очереди
int TQueue::get_size() const {
    int size = 0;
    TNode* current = head;
    while (current) {
        size++;
        current = current->Next;
    }
    return size;
}

// Очистка очереди
void TQueue::clear() {
    while (!is_empty()) {
        dequeue();
    }
}

// Вывод всех элементов очереди
void TQueue::print() const {
    if (is_empty()) {
        std::cout << "Очередь пуста" << std::endl;
        return;
    }

    std::cout << "Очередь (начало -> конец): ";
    TNode* current = head;
    while (current) {
        std::cout << current->Data << " ";
        current = current->Next;
    }
    std::cout << std::endl;
}

// TList и задания 3,4 -------------------------------------

// Конструктор по умолчанию
TList::TList() : head(nullptr) {}

// Конструктор копирования
TList::TList(const TList& other) : head(nullptr) {
    if (other.head == nullptr) return;

    TNode* current = other.head;
    while (current) {
        insert_at_end(current->Data);
        current = current->Next;
    }
}

// Деструктор
TList::~TList() {
    clear();
}

// Вставка элемента в конец списка
void TList::insert_at_end(int value) {
    TNode* new_node = new TNode(value);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    TNode* current = head;
    while (current->Next) {
        current = current->Next;
    }
    current->Next = new_node;
}

// Вставка элемента в начало списка
void TList::insert_at_beginning(int value) {
    TNode* new_node = new TNode(value, head);
    head = new_node;
}

// Вывод всех элементов списка
void TList::print() const {
    if (head == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    std::cout << "Список: ";
    TNode* current = head;
    while (current) {
        std::cout << current->Data << " ";
        current = current->Next;
    }
    std::cout << std::endl;
}

// Очистка списка
void TList::clear() {
    while (head) {
        TNode* temp = head;
        head = head->Next;
        delete temp;
    }
}

// Получение размера списка
int TList::get_size() const {
    int size = 0;
    TNode* current = head;
    while (current) {
        size++;
        current = current->Next;
    }
    return size;
}

TNode* TList::find_first_multiple_of(int divisor) const {
    TNode* current = head;
    while (current) {
        if (current->Data % divisor == 0) {
            return current;
        }
        current = current->Next;
    }
    return nullptr;
}

TNode* TList::get_last() const {
    if (head == nullptr) return nullptr;

    TNode* current = head;
    while (current->Next) {
        current = current->Next;
    }
    return current;
}

void TList::insert_after_every_fourth(int value) {
    if (head == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    int count = 0;
    TNode* current = head;

    while (current) {
        count++;
        if (count % 4 == 0) {
            TNode* new_node = new TNode(value, current->Next);
            current->Next = new_node;
            current = new_node->Next;
        }
        else {
            current = current->Next;
        }
    }
}