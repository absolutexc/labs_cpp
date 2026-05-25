#include "head.h"

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

Node::~Node() {}

int Node::get_value() const {
    return value;
}

Node* Node::get_left() const {
    return left;
}

Node* Node::get_right() const {
    return right;
}

void Node::set_value(int val) {
    value = val;
}

void Node::set_left(Node* node) {
    left = node;
}

void Node::set_right(Node* node) {
    right = node;
}

bool Node::is_operator() const {
    return value < 0 && value != -100;
}

bool Node::is_operand() const {
    return value >= 0 || value == -100;
}

bool Node::is_variable_x() const {
    return value == -100;
}


void PrintTree::print_tree(Node* root) {
    if (!root) {
        std::cout << "Дерево пустое" << std::endl;
        return;
    }
    std::cout << "Графическое представление дерева:" << std::endl;
    print_recursive(root, 0, "", true);
}

void PrintTree::print_recursive(Node* node, int level, std::string prefix, bool is_last) {
    if (!node) return;

    std::cout << prefix;

    if (level > 0) {
        if (is_last) {
            std::cout << "└── ";
        } else {
            std::cout << "├── ";
        }
    }

    std::string val_str;
    if (node->is_variable_x()) {
        val_str = "x";
    } else if (node->is_operand()) {
        val_str = std::to_string(node->get_value());
    } else {
        // Выводим код операции (-1, -2, -3, -4, -5)
        val_str = std::to_string(node->get_value());
    }

    std::cout << "[" << val_str << "]" << std::endl;

    std::string new_prefix = prefix;
    if (level > 0) {
        if (is_last) {
            new_prefix += "    ";
        } else {
            new_prefix += "│   ";
        }
    } else {
        new_prefix += "    ";
    }

    bool has_right = (node->get_right() != nullptr);

    if (node->get_left()) {
        print_recursive(node->get_left(), level + 1, new_prefix, !has_right);
    }

    if (node->get_right()) {
        print_recursive(node->get_right(), level + 1, new_prefix, true);
    }
}

void PrintTree::print_sideways(Node* root, int width) {
    if (!root) {
        std::cout << "Дерево пустое" << std::endl;
        return;
    }
    std::cout << "Дерево на боку:" << std::endl;
    std::vector<std::string> lines;
    print_sideways_recursive(root, 0, width, lines);
    for (const auto& line : lines) {
        std::cout << line << "\n";
    }
}

void PrintTree::print_sideways_recursive(Node* node, int level, int width,
                                          std::vector<std::string>& output) {
    if (!node) return;

    print_sideways_recursive(node->get_right(), level + 1, width, output);

    std::string val_str;
    if (node->is_variable_x()) {
        val_str = "x";
    } else if (node->is_operand()) {
        val_str = std::to_string(node->get_value());
    } else {
        // Выводим код операции (-1, -2, -3, -4, -5)
        val_str = std::to_string(node->get_value());
    }

    std::string indent = std::string(level * width, ' ');
    output.push_back(indent + val_str);

    print_sideways_recursive(node->get_left(), level + 1, width, output);
}

std::string PrintTree::infix_to_string(Node* node) {
    if (!node) return "";
    if (node->is_operand()) {
        if (node->is_variable_x()) return "x";
        return std::to_string(node->get_value());
    }

    std::string left_str = infix_to_string(node->get_left());
    std::string right_str = infix_to_string(node->get_right());

    // Для инфиксной формы выводим код операции
    std::string op_str = std::to_string(node->get_value());

    return "(" + left_str + " " + op_str + " " + right_str + ")";
}

std::string PrintTree::prefix_to_string(Node* node) {
    if (!node) return "";
    if (node->is_operand()) {
        if (node->is_variable_x()) return "x";
        return std::to_string(node->get_value());
    }

    // Для префиксной формы выводим код операции
    return std::to_string(node->get_value()) + " " +
           prefix_to_string(node->get_left()) + " " +
           prefix_to_string(node->get_right());
}

std::string PrintTree::postfix_to_string(Node* node) {
    if (!node) return "";
    if (node->is_operand()) {
        if (node->is_variable_x()) return "x";
        return std::to_string(node->get_value());
    }

    // Для постфиксной формы выводим код операции
    return postfix_to_string(node->get_left()) + " " +
           postfix_to_string(node->get_right()) + " " +
           std::to_string(node->get_value());
}

void PrintTree::print_to_file(Node* root, int x_value, int result, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл " << filename << " для записи\n";
        return;
    }

    file << "Значение выражения при x = " << x_value << ": " << result << "\n\n";

    file << "Дерево выражений (после замены поддеревьев без x):\n";

    file << "Графическое представление:\n";
    std::vector<std::string> lines;
    print_sideways_recursive(root, 0, 8, lines);
    for (const auto& line : lines) {
        file << line << "\n";
    }

    file.close();
    std::cout << "Результат записан в файл " << filename << std::endl;
}

ExpressionTree::ExpressionTree() : root(nullptr), error_flag(false) {}

ExpressionTree::~ExpressionTree() {
    clear_tree();
}

void ExpressionTree::clear_tree() {
    delete root;
    root = nullptr;
    error_flag = false;
}

int ExpressionTree::get_operator_code(char op) {
    switch (op) {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '%': return -5;
        default: return 0;
    }
}

char ExpressionTree::get_operator_char(int code) {
    switch (code) {
        case -1: return '+';
        case -2: return '-';
        case -3: return '*';
        case -4: return '/';
        case -5: return '%';
        default: return '?';
    }
}

char ExpressionTree::get_random_operator() {
    const char ops[] = {'+', '-', '*', '/', '%'};
    return ops[std::rand() % 5];
}

int ExpressionTree::get_random_operand() {
    return std::rand() % 10;
}

std::string ExpressionTree::generate_random_rpn(int depth) {
    if (depth <= 0) {
        return std::to_string(get_random_operand());
    }

    std::string left = generate_random_rpn(depth - 1);
    std::string right = generate_random_rpn(depth - 1);
    char op = get_random_operator();

    return left + " " + right + " " + op;
}

// ввод

void ExpressionTree::input_console() {
    clear_tree();

    std::cout << "Введите выражение в ЛПК: ";
    std::string expr;
    std::cin.ignore();
    std::getline(std::cin, expr);

    build_from_rpn(expr);
}

void ExpressionTree::input_random() {
    clear_tree();

    int depth;
    std::cout << "Введите максимальную глубину (1-5): ";
    depth = get_positive();
    depth = std::min(5, std::max(1, depth));

    std::string rpn_expr = generate_random_rpn(depth);
    std::cout << "Сгенерированное выражение: " << rpn_expr << std::endl;

    build_from_rpn(rpn_expr);
}

void ExpressionTree::input_file() {
    clear_tree();

    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    if (!Validator::file_exists(filename)) {
        std::cout << "Ошибка: файл не найден!" << std::endl;
        return;
    }

    std::ifstream file(filename);
    std::string content, line;
    while (std::getline(file, line)) {
        content += line;
    }
    file.close();

    build_from_rpn(content);
}

// функции для CalcTree3

void ExpressionTree::build_from_rpn(const std::string& expr) {
    clear_tree();

    std::stack<Node*> st;
    std::string token;
    std::stringstream ss(expr);

    while (ss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            st.push(new Node(token[0] - '0'));
        } else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' ||
                                            token[0] == '*' || token[0] == '/' ||
                                            token[0] == '%')) {
            if (st.size() < 2) {
                std::cout << "Ошибка: неверное выражение!" << std::endl;
                return;
            }
            Node* node = new Node(get_operator_code(token[0]));
            node->set_right(st.top()); st.pop();
            node->set_left(st.top()); st.pop();
            st.push(node);
        } else {
            for (char c : token) {
                if (isdigit(c)) {
                    st.push(new Node(c - '0'));
                } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
                    if (st.size() < 2) {
                        std::cout << "Ошибка: неверное выражение!" << std::endl;
                        return;
                    }
                    Node* node = new Node(get_operator_code(c));
                    node->set_right(st.top()); st.pop();
                    node->set_left(st.top()); st.pop();
                    st.push(node);
                }
            }
        }
    }

    if (!st.empty()) {
        root = st.top();
    }
}

int ExpressionTree::evaluate_node(Node* node) {
    if (!node) return 0;
    if (error_flag) return 0;
    if (node->is_operand()) return node->get_value();

    int left_val = evaluate_node(node->get_left());
    int right_val = evaluate_node(node->get_right());

    switch (node->get_value()) {
        case -1: return left_val + right_val;
        case -2: return left_val - right_val;
        case -3: return left_val * right_val;
        case -4:
            if (right_val == 0) {
                std::cout << "Ошибка: деление на ноль" << std::endl;
                error_flag = true;
                return 0;
            }
            return left_val / right_val;
        case -5:
            if (right_val == 0) {
                std::cout << "Ошибка: остаток от деления на ноль" << std::endl;
                error_flag = true;
                return 0;
            }
            return left_val % right_val;
        default: return 0;
    }
}

Node* ExpressionTree::remove_multiplication(Node* node) {
    if (!node) return nullptr;

    node->set_left(remove_multiplication(node->get_left()));
    node->set_right(remove_multiplication(node->get_right()));

    if (node->is_operator() && node->get_value() == -3) {
        int left_val = evaluate_node(node->get_left());
        int right_val = evaluate_node(node->get_right());
        int result = left_val * right_val;

        delete node->get_left();
        delete node->get_right();
        delete node;

        return new Node(result);
    }
    return node;
}

void ExpressionTree::transform_remove_multiplication() {
    if (!root) return;
    root = remove_multiplication(root);
}

int ExpressionTree::evaluate() {
    error_flag = false;
    return evaluate_node(root);
}

// функции для CalcTree25

int ExpressionTree::get_priority(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

bool ExpressionTree::is_right_associative(char op) {
    return op == '^';
}

std::vector<std::string> ExpressionTree::infix_to_rpn(const std::string& infix) {
    std::vector<std::string> output;
    std::stack<char> operators;
    size_t i = 0;

    while (i < infix.length()) {
        char c = infix[i];
        if (isdigit(c)) {
            output.push_back(std::string(1, c));
        } else if (c == 'x') {
            output.push_back("x");
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/' ||
                   c == '%' || c == '^') {
            while (!operators.empty() && operators.top() != '(' &&
                   (get_priority(operators.top()) > get_priority(c) ||
                    (get_priority(operators.top()) == get_priority(c) &&
                     !is_right_associative(c)))) {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(c);
        }
        i++;
    }
    while (!operators.empty()) {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }
    return output;
}

Node* ExpressionTree::build_from_rpn_tokens(const std::vector<std::string>& tokens) {
    std::stack<Node*> st;
    for (const auto& token : tokens) {
        if (token == "x") {
            st.push(new Node(-100));
        } else if (token.length() == 1 && isdigit(token[0])) {
            int val = token[0] - '0';
            st.push(new Node(val));
        } else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' ||
                                            token[0] == '*' || token[0] == '/' ||
                                            token[0] == '%' || token[0] == '^')) {
            Node* node = new Node(get_operator_code(token[0]));
            node->set_right(st.top()); st.pop();
            node->set_left(st.top()); st.pop();
            st.push(node);
        }
    }
    return st.top();
}

void ExpressionTree::build_from_infix(const std::string& expr) {
    clear_tree();

    std::string cleaned = expr;
    cleaned.erase(std::remove_if(cleaned.begin(), cleaned.end(), ::isspace), cleaned.end());

    std::vector<std::string> rpn_tokens = infix_to_rpn(cleaned);
    root = build_from_rpn_tokens(rpn_tokens);
}

bool ExpressionTree::has_variable_x(Node* node) {
    if (!node) return false;
    if (node->is_variable_x()) return true;
    return has_variable_x(node->get_left()) || has_variable_x(node->get_right());
}

Node* ExpressionTree::evaluate_subtree(Node* node, int x_value) {
    if (!node) return nullptr;
    if (error_flag) return nullptr;

    node->set_left(evaluate_subtree(node->get_left(), x_value));
    node->set_right(evaluate_subtree(node->get_right(), x_value));

    if (node->is_operand()) {
        return node;
    }

    if (!has_variable_x(node)) {
        int result = evaluate_node(node);
        if (error_flag) return nullptr;
        delete node->get_left();
        delete node->get_right();
        delete node;
        return new Node(result);
    }

    return node;
}

void ExpressionTree::transform_replace_non_x_subtrees(int x_value) {
    if (!root) return;
    error_flag = false;
    root = evaluate_subtree(root, x_value);
}

int ExpressionTree::evaluate_with_x_recursive(Node* node, int x_value) {
    if (!node) return 0;
    if (error_flag) return 0;
    if (node->is_variable_x()) return x_value;
    if (node->is_operand()) return node->get_value();

    int left_val = evaluate_with_x_recursive(node->get_left(), x_value);
    int right_val = evaluate_with_x_recursive(node->get_right(), x_value);

    switch (node->get_value()) {
        case -1: return left_val + right_val;
        case -2: return left_val - right_val;
        case -3: return left_val * right_val;
        case -4:
            if (right_val == 0) {
                error_flag = true;
                return 0;
            }
            return left_val / right_val;
        case -5:
            if (right_val == 0) {
                error_flag = true;
                return 0;
            }
            return left_val % right_val;
        default: return 0;
    }
}

int ExpressionTree::evaluate_with_x(int x_value) {
    error_flag = false;
    return evaluate_with_x_recursive(root, x_value);
}

Node* ExpressionTree::copy_tree(Node* node) {
    if (!node) return nullptr;
    Node* new_node = new Node(node->get_value());
    new_node->set_left(copy_tree(node->get_left()));
    new_node->set_right(copy_tree(node->get_right()));
    return new_node;
}

void ExpressionTree::input_console_infix() {
    clear_tree();

    std::string expr;
    std::cout << "Введите выражение с x (ЛКП): ";
    std::cin.ignore();
    std::getline(std::cin, expr);

    build_from_infix(expr);
}

// класс проверок

bool Validator::file_exists(const std::string& filename) {
    std::ifstream f(filename.c_str());
    return f.good();
}

bool Validator::validate_rpn(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return false;

    std::string content, line;
    while (std::getline(file, line)) {
        content += line;
    }
    file.close();

    return validate_rpn_string(content);
}

bool Validator::validate_rpn_string(const std::string& expr) {
    int operand_count = 0;
    std::string token;
    std::stringstream ss(expr);

    while (ss >> token) {
        if (token.length() == 1 && isdigit(token[0])) {
            operand_count++;
        } else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' ||
                                            token[0] == '*' || token[0] == '/' ||
                                            token[0] == '%')) {
            if (operand_count < 2) return false;
            operand_count--;
        } else {
            for (char c : token) {
                if (isdigit(c)) {
                    operand_count++;
                } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
                    if (operand_count < 2) return false;
                    operand_count--;
                } else {
                    return false;
                }
            }
        }
    }
    return operand_count == 1;
}

bool Validator::validate_infix(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return false;

    std::string content, line;
    while (std::getline(file, line)) {
        content += line;
    }
    file.close();

    return validate_infix_string(content);
}

bool Validator::validate_infix_string(const std::string& expr) {
    int bracket_balance = 0;
    bool last_was_operator = true;
    bool has_x = false;

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (c == 'x') {
            if (!last_was_operator) return false;
            has_x = true;
            last_was_operator = false;
        } else if (isdigit(c)) {
            if (!last_was_operator) return false;
            last_was_operator = false;
        } else if (c == '(') {
            bracket_balance++;
            last_was_operator = true;
        } else if (c == ')') {
            bracket_balance--;
            if (bracket_balance < 0) return false;
            last_was_operator = false;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' ||
                   c == '%' || c == '^') {
            if (last_was_operator) return false;
            last_was_operator = true;
        } else {
            return false;
        }
    }
    return bracket_balance == 0 && !last_was_operator && has_x;
}

bool Validator::check_division_by_zero(const std::string& expr, bool is_rpn) {

    if (is_rpn) {
        std::stringstream ss(expr);
        std::string token;
        std::stack<std::string> st;

        while (ss >> token) {
            if (token.length() == 1 && (token[0] == '/' || token[0] == '%')) {
                if (st.size() < 2) return false;
                std::string right = st.top(); st.pop();
                std::string left = st.top(); st.pop();

                // Проверяем, является ли правый операнд нулем
                if (right == "0") {
                    std::cout << "Ошибка: обнаружено деление на ноль в выражении!" << std::endl;
                    return false;
                }
                st.push("result");
            } else {
                st.push(token);
            }
        }
    } else {
        // Для инфиксной записи - проверка наличия "/ 0" или "% 0"
        size_t pos = 0;
        while (pos < expr.length()) {
            pos = expr.find_first_of("/%", pos);
            if (pos == std::string::npos) break;

            // Ищем ноль после оператора
            size_t next = pos + 1;
            while (next < expr.length() && isspace(expr[next])) next++;

            if (next < expr.length() && expr[next] == '0') {
                // Проверяем, что это не число 10, 20 и т.д.
                if (next + 1 >= expr.length() || !isdigit(expr[next + 1])) {
                    std::cout << "Ошибка: обнаружено деление на ноль в выражении!" << std::endl;
                    return false;
                }
            }
            pos++;
        }
    }
    return true;
}