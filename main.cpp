// Лабораторная работа № 1. Вариант 66.
// Выполнил: Бурбах И. Е., группа ПИ-53.
// Конвертер массы: килограммы <-> фунты.

#include <iostream>
#include <windows.h>   // для SetConsoleOutputCP (кириллица в консоли Windows)

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

// ===== Главная функция: меню =====
int main() {
    SetConsoleOutputCP(65001);   // вывод в UTF-8
    SetConsoleCP(65001);         // ввод в UTF-8

    int choice;
    double value;

    do {
        cout << "\n== Вариант 66: конвертер массы ==\n";
        cout << "1. Килограммы -> фунты\n";
        cout << "2. Фунты -> килограммы\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите массу в килограммах: ";
                cin >> value;
                cout << value << " кг = " << kgToLb(value) << " фунтов\n";
                break;

            case 2:
                cout << "Введите массу в фунтах: ";
                cin >> value;
                cout << value << " фунтов = " << lbToKg(value) << " кг\n";
                break;

            case 0:
                cout << "Работа завершена.\n";
                break;

            default:
                cout << "Такого пункта нет.\n";
        }
    } while (choice != 0);
}
