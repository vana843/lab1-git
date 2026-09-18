// Лабораторная работа № 1. Вариант 66.
// Выполнил: Бурбах И. Е., группа ПИ-53.
// Конвертер массы: килограммы <-> фунты.

// Компьютер 2. Синхронизация проверена.
// Студент: Бурбах И. Е., группа ПИ-53.
#include <iostream>
#include <iomanip>     // для setprecision, fixed
#include <windows.h>   // для SetConsoleOutputCP (кириллица)

using namespace std;

// ===== Расчётные функции варианта 66 =====

// Килограммы -> фунты
double kgToLb(double kg) {
    return kg * 2.20462;
}

// Фунты -> килограммы
double lbToKg(double lb) {
    return lb / 2.20462;
}

// ===== Вспомогательная функция: рамка =====
void printLine() {
    cout << "+------------------------------------------+\n";
}

void printHeader() {
    printLine();
    cout << "|   Вариант 66: Программа для расчетов            |\n";
    cout << "|   Килограммы <-> Фунты                   |\n";
    printLine();
}

// ===== Главная функция: меню =====
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Формат вывода чисел: 4 знака после запятой
    cout << fixed << setprecision(4);

    int choice;
    double value;
    double result;

    do {
        printHeader();
        cout << "| 1. Килограммы -> фунты                   |\n";
        cout << "| 2. Фунты -> килограммы                   |\n";
        cout << "| 0. Выход                                 |\n";
        printLine();
        cout << "Выберите пункт: ";
        cin >> choice;

        // Проверка на некорректный ввод
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n[Ошибка] Введите число, а не текст.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\nВведите массу в килограммах: ";
                cin >> value;
                if (cin.fail() || value < 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "[Ошибка] Масса не может быть отрицательной.\n";
                    break;
                }
                result = kgToLb(value);
                cout << "\nРезультат:\n";
                cout << "  " << value << " кг  =  " << result << " фунтов\n";
                cout << "  (коэффициент: 1 кг = 2.20462 фунта)\n";
                break;

            case 2:
                cout << "\nВведите массу в фунтах: ";
                cin >> value;
                if (cin.fail() || value < 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "[Ошибка] Масса не может быть отрицательной.\n";
                    break;
                }
                result = lbToKg(value);
                cout << "\nРезультат:\n";
                cout << "  " << value << " фунтов  =  " << result << " кг\n";
                cout << "  (коэффициент: 1 фунт = 0.453592 кг)\n";
                break;

            case 0:
                cout << "\nРабота завершена. До свидания!\n";
                break;

            default:
                cout << "\n[Ошибка] Такого пункта нет. Введите 0, 1 или 2.\n";
        }
    } while (choice != 0);

    return 0;
}
