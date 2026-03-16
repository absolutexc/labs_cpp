#include "head.h"

// Node

Node::Node(int value) : data(value), next(nullptr), prev(nullptr) {}

// task 1

CyclicList::CyclicList() : head_(nullptr), size_(0) {}

CyclicList::CyclicList(const CyclicList& other) : head_(nullptr), size_(0) {
    if (other.is_empty()) return;

    Node* temp = other.head_;
    do {
        push_back(temp->data);
        temp = temp->next;
    } while (temp != other.head_);
}

CyclicList::~CyclicList() {
    clear();
}

bool CyclicList::is_empty() const {
  return head_ == nullptr;
}

void CyclicList::push_back(int value) {
  Node* new_node = new Node(value);

  if (is_empty()) {
    head_ = new_node;
    new_node->next = head_;
  }
  else {
    Node* temp = head_;
    while (temp->next != head_) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head_;
  }
  size_++;
}

void CyclicList::push_front(int value) {
  Node* new_node = new Node(value);

  if (is_empty()) {
    head_ = new_node;
    new_node->next = head_;
  }
  else {
    Node* temp = head_;
    while (temp->next != head_) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head_;
    head_ = new_node;
  }
  size_++;
}

void CyclicList::pop_back() {
  if (is_empty()) return;

  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
  }
  else {
    Node* temp = head_;
    Node* prev = nullptr;
    while (temp->next != head_) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = head_;
    delete temp;
  }
  size_--;
}

void CyclicList::pop_front() {
  if (is_empty()) return;

  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
  }
  else {
    Node* temp = head_;
    Node* last = head_;
    while (last->next != head_) {
      last = last->next;
    }
    head_ = head_->next;
    last->next = head_;
    delete temp;
  }
  size_--;
}

void CyclicList::remove(Node* node) {
  if (is_empty() || node == nullptr) return;

  if (head_ == node && head_->next == head_) {
    delete head_;
    head_ = nullptr;
    size_--;
    return;
  }

  Node* temp = head_;
  Node* prev = nullptr;

  do {
    if (temp == node) {
      if (prev) {
        prev->next = temp->next;
      }
      else {
        Node* last = head_;
        while (last->next != head_) {
          last = last->next;
        }
        head_ = head_->next;
        last->next = head_;
      }
      delete temp;
      size_--;
      return;
    }
    prev = temp;
    temp = temp->next;
  } while (temp != head_);
}

void CyclicList::clear() {
  if (is_empty()) return;

  Node* current = head_;
  Node* next_node;

  do {
    next_node = current->next;
    delete current;
    current = next_node;
  } while (current != head_);

  head_ = nullptr;
  size_ = 0;
}

void CyclicList::print() const {
  if (is_empty()) {
    std::cout << "Список пуст" << std::endl;
    return;
  }

  Node* temp = head_;
  do {
    std::cout << temp->data;
    temp = temp->next;
    if (temp != head_) {
      std::cout << " ";
    }
  } while (temp != head_);
  std::cout << std::endl;
}

// task 2

DoublyCyclicList::DoublyCyclicList() : head_(nullptr), size_(0) {}

DoublyCyclicList::DoublyCyclicList(const DoublyCyclicList& other) : head_(nullptr), size_(0) {
  if (other.is_empty()) return;

  Node* temp = other.head_;
  do {
    push_back(temp->data);
    temp = temp->next;
  } while (temp != other.head_);
}

DoublyCyclicList::~DoublyCyclicList() {
  clear();
}

bool DoublyCyclicList::is_empty() const {
  return head_ == nullptr;
}

void DoublyCyclicList::push_back(int value) {
  Node* new_node = new Node(value);

  if (is_empty()) {
    head_ = new_node;
    new_node->next = head_;
    new_node->prev = head_;
  }
  else {
    Node* tail = head_->prev;

    tail->next = new_node;
    new_node->prev = tail;
    new_node->next = head_;
    head_->prev = new_node;
  }
  size_++;
}

void DoublyCyclicList::push_front(int value) {
  Node* new_node = new Node(value);

  if (is_empty()) {
    head_ = new_node;
    new_node->next = head_;
    new_node->prev = head_;
  }
  else {
    Node* tail = head_->prev;

    new_node->next = head_;
    new_node->prev = tail;
    head_->prev = new_node;
    tail->next = new_node;
    head_ = new_node;
  }
  size_++;
}

void DoublyCyclicList::pop_back() {
  if (is_empty()) return;

  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
  }
  else {
    Node* tail = head_->prev;
    Node* new_tail = tail->prev;

    new_tail->next = head_;
    head_->prev = new_tail;

    delete tail;
  }
  size_--;
}

void DoublyCyclicList::pop_front() {
  if (is_empty()) return;

  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
  }
  else {
    Node* tail = head_->prev;
    Node* new_head = head_->next;

    tail->next = new_head;
    new_head->prev = tail;

    delete head_;
    head_ = new_head;
  }
  size_--;
}

void DoublyCyclicList::remove(Node* node) {
  if (is_empty() || node == nullptr) return;

  if (head_->next == head_ && head_ == node) {
    delete head_;
    head_ = nullptr;
    size_--;
    return;
  }

  Node* temp = head_;
  do {
    if (temp == node) {
      Node* prev_node = temp->prev;
      Node* next_node = temp->next;

      prev_node->next = next_node;
      next_node->prev = prev_node;

      if (temp == head_) {
        head_ = next_node;
      }

      delete temp;
      size_--;
      return;
    }
    temp = temp->next;
  } while (temp != head_);
}

void DoublyCyclicList::clear() {
  if (is_empty()) return;

  Node* current = head_;
  Node* next_node;

  do {
    next_node = current->next;
    delete current;
    current = next_node;
  } while (current != head_);

  head_ = nullptr;
  size_ = 0;
}

Node* DoublyCyclicList::process_task_42() {
  if (is_empty()) return nullptr;
  if (size_ < 2) return head_->prev;

  bool changed;
  do {
    changed = false;
    Node* current = head_;
    int current_size = size_;

    for (int i = 0; i < current_size; i++) {
      Node* next_node = current->next;

      if (current->prev->data == current->next->data) {
        remove(current);
        changed = true;
      }

      current = next_node;
      if (is_empty()) break;
    }
  } while (changed && !is_empty());

  return is_empty() ? nullptr : head_->prev;
}

void DoublyCyclicList::print() const {
  if (is_empty()) {
    std::cout << "Список пуст" << std::endl;
    return;
  }

  Node* temp = head_;
  do {
    std::cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head_);
  std::cout << std::endl;
}

// task 3

DoublyList::DoublyList() : head_(nullptr), tail_(nullptr), size_(0) {}

DoublyList::DoublyList(const DoublyList& other) : head_(nullptr), tail_(nullptr), size_(0) {
  if (other.is_empty()) return;

  Node* temp = other.head_;
  while (temp != nullptr) {
    push_back(temp->data);
    temp = temp->next;
  }
}

DoublyList::~DoublyList() {
  clear();
}

bool DoublyList::is_empty() const {
  return head_ == nullptr;
}

void DoublyList::push_back(int value) {
  Node* new_node = new Node(value);

  if (is_empty()) {
    head_ = tail_ = new_node;
  }
  else {
    tail_->next = new_node;
    new_node->prev = tail_;
    tail_ = new_node;
  }
  size_++;
}

void DoublyList::push_front(int value) {
  Node* new_node = new Node(value);

  if (is_empty()) {
    head_ = tail_ = new_node;
  }
  else {
    head_->prev = new_node;
    new_node->next = head_;
    head_ = new_node;
  }
  size_++;
}

void DoublyList::pop_back() {
  if (is_empty()) return;

  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  }
  else {
    Node* new_tail = tail_->prev;
    new_tail->next = nullptr;
    delete tail_;
    tail_ = new_tail;
  }
  size_--;
}

void DoublyList::pop_front() {
  if (is_empty()) return;

  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  }
  else {
    Node* new_head = head_->next;
    new_head->prev = nullptr;
    delete head_;
    head_ = new_head;
  }
  size_--;
}

void DoublyList::remove(Node* node) {
  if (is_empty() || node == nullptr) return;

  if (node == head_) {
    pop_front();
  }
  else if (node == tail_) {
    pop_back();
  }
  else {
    Node* prev_node = node->prev;
    Node* next_node = node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    delete node;
    size_--;
  }
}

void DoublyList::clear() {
  while (!is_empty()) {
    pop_front();
  }
}

void DoublyList::print() const {
  if (is_empty()) {
    std::cout << "Список пуст" << std::endl;
    return;
  }

  Node* temp = head_;
  while (temp != nullptr) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

void DoublyList::process_task_64(const std::string& filename) {
  std::ofstream out_file(filename);
  if (!out_file.is_open()) {
    std::cout << "Ошибка создания файла " << filename << "!" << std::endl;
    return;
  }

  if (is_empty()) {
    out_file << "Список пуст" << std::endl;
    out_file.close();
    return;
  }

  Node* left = head_;
  Node* right = tail_;
  std::vector<int> result;

  while (left != right && left->prev != right) {
    result.push_back(left->data);

    result.push_back(right->data);

    Node* next_left = left->next;
    Node* next_right = right->prev;

    remove(left);
    remove(right);

    left = next_left;
    right = next_right;

    if (is_empty()) break;
  }

  if (!is_empty()) {
    result.push_back(head_->data);
  }

  for (size_t i = 0; i < result.size(); i++) {
    out_file << result[i];
    if (i != result.size() - 1) {
      out_file << " ";
    }
  }
  out_file << std::endl;
  out_file.close();

  std::cout << "Результат: ";
  for (size_t i = 0; i < result.size(); i++) {
    std::cout << result[i];
    if (i != result.size() - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
  std::cout << "Результат сохранен в файл " << filename << std::endl;
}

// task 4

TListB::TListB() : barrier(new Node()), current(nullptr) {
  barrier->next = barrier;
  barrier->prev = barrier;
}

TListB::TListB(const TListB& other) : barrier(new Node()), current(nullptr) {
  Node* temp = other.barrier->next;
  while (temp != other.barrier) {
    Node* new_node = new Node(temp->data);
    new_node->prev = barrier->prev;
    new_node->next = barrier;
    barrier->prev->next = new_node;
    barrier->prev = new_node;

    if (temp == other.current) {
      current = new_node;
    }

    temp = temp->next;
  }
}

TListB::~TListB() {
  clear();
  delete barrier;
}

bool TListB::is_empty() const {
  return barrier->next == barrier;
}

void TListB::clear() {
  while (!is_empty()) {
    Node* temp = barrier->next;
    barrier->next = temp->next;
    temp->next->prev = barrier;
    delete temp;
  }
  current = nullptr;
}

void BarrierLast::lb_insert_last(TListB& L, int D) {
  Node* new_node = new Node(D);

  new_node->prev = L.barrier->prev;
  new_node->next = L.barrier;
  L.barrier->prev->next = new_node;
  L.barrier->prev = new_node;

  L.current = new_node;
}

void BarrierLast::print(const TListB& L) {
    if (L.is_empty()) {
      std::cout << "Список пуст" << std::endl;
      return;
    }

    Node* temp = L.barrier->next;
    while (temp != L.barrier) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;

    if (L.current != nullptr) {
      std::cout << "Текущий элемент: " << L.current->data << std::endl;
      std::cout << "Адрес текущего элемента: " << L.current << std::endl;
    }
}

// task 5

std::vector<int> CyclicList::find_max_increasing() const {
  std::vector<int> result;
  if (is_empty()) return result;

  int max_len = 0;
  Node* best_start = nullptr;

  Node* start = head_;
  do {
    int len = 1;
    Node* current = start;

    while (current->next->data > current->data) {
      len++;
      current = current->next;
      if (current == start) break;
    }

    if (len > max_len) {
      max_len = len;
      best_start = start;
    }

    start = start->next;
  } while (start != head_);

  if (max_len == 0) {
    result.push_back(head_->data);
    return result;
  }

  Node* current = best_start;
  for (int i = 0; i < max_len; i++) {
    result.push_back(current->data);
    current = current->next;
  }

  return result;
}