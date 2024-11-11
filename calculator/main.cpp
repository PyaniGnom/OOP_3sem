#include <iostream>
#include <climits>

double Calculate(double a, double b, char sign) {
    double result;
    switch (sign) {
        case (1):
            result = a + b;
            break;
        case (2):
            result = a - b;
            break;
        case(3):
            result = a * b;
            break;
        case(4):
            result = a / b;
            break;
        default:
            result = -1337;
            break;
    }

    return result;
}

double Input(int min = INT_MIN, int max = INT_MAX) {
    double number;
    while(true) {
        if ((std::cin >> number).good() && (number <= max) && (number >= min)) {
            return number;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Неверный ввод! Повторите ещё раз" << std::endl;
        }
        std::cin.ignore(100, '\n');
    }
}

char Reset() {
    std::cout << "Хотите начать сначала? (y/n) - ";
    char answer;
    while (true) {
        if ((std::cin >> answer).good() && (answer == 'y' || answer == 'n')) {
            return answer;
        }
        if (std::cin.fail()) {
            std::cin.clear();
        }
        std::cin.ignore(100, '\n');
    }
}

int main() {
    double first_value, second_value;

    while (true) {
        std::cout << "Введите первое число: ";
        first_value = Input();

        std::cout << "Введите второе число: ";
        second_value = Input();

        std::cout << "Выберите операцию (число от 1 до 4)" << std::endl;
        std::cout << "1. Сложение (+)" << std::endl;
        std::cout << "2. Вычитание (-)" << std::endl;
        std::cout << "3. Умножение (*)" << std::endl;
        std::cout << "4. Деление (/)" << std::endl;
        double sign = Input(1, 4);

        if (second_value == 0 && sign == 4) {
            std::cout << "На ноль делить нельзя!";
        }
        else {
            double result = Calculate(first_value, second_value, sign);
            std::cout << "\nРезультат: " << result << std::endl;
        }

        char rejectChar = 'n';
        if (Reset() == rejectChar) break;
    }

    return 0;
}
