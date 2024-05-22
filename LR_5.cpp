#include "bankDeposit.h"   // Подключение заголовочного файла с описанием класса Bank_deposit

#include <list>
#include <vector>
#include <fstream> // Для работы с файлами, функция clear
#include <algorithm> // Для использования функции сортировки sort


#include <set>
#include <unordered_set>

// Функция для вывода объекта типа Bank_deposit в файл и на консоль
void CustomOutput(const Bank_deposit& bank_dep) {
    std::ofstream output("output.txt", std::ios::app);  // Открытие файла для записи

    output << bank_dep << std::endl;    // Запись объекта в файл
    std::cout << bank_dep << std::endl; // Вывод объекта на консоль

    output.close();  // Закрытие файла
}

// Перегруженная функция CustomOutput для работы с типом std::string
void CustomOutput(std::string& bank_dep) {
    std::ofstream output("output.txt", std::ios::app);  // Открытие файла для записи

    output << bank_dep << std::endl;    // Запись объекта в файл
    std::cout << bank_dep << std::endl; // Вывод объекта на консоль

    output.close(); // Закрытие файла
}

// Перегруженная функция CustomOutput для работы с типом double
void CustomOutput(double& bank_dep) {
    std::ofstream output("output.txt", std::ios::app);   // Открытие файла для записи

    output << bank_dep << std::endl;    // Запись объекта в файл
    std::cout << bank_dep << std::endl; // Вывод объекта на консоль

    output.close(); // Закрытие файла
}

//Структура для хеширования объектов класса Bank_deposit
struct Bank_deposit_Hash {
    size_t operator()(const Bank_deposit& bank_dep) const {
        return std::hash<double>()(bank_dep.Get_sum_dep());
    }
};


int main()
{
    std::ofstream clear("output.txt"); // Очистка файла вывода
    clear.close(); // Закрытие файла

    std::ifstream input("input.txt"); // Открытие файла для чтения

    std::list<Bank_deposit> BANK_LIST; // создание двусвязного списка
    std::set<Bank_deposit> setB; // создание множества set из уникальных элементов
    std::unordered_set<Bank_deposit, Bank_deposit_Hash> unsetB; // создание множество unordered_set
    

    for (size_t i = 0; i < 5; ++i) {
        Bank_deposit bank_dep;             // Создание временного объекта Bank_deposit
        input >> bank_dep; // Чтение данных из файла и инициализация объекта
        BANK_LIST.push_back(bank_dep);    // Добавление объекта в конец списка
        setB.insert(bank_dep); // Добавление объекта в конец множества set из уникальных элементов
        unsetB.insert(bank_dep); // Добавление объекта в unordered_set
    }

    // если не использовать переменную строкового типа, то по умолчанию будет char,
    // то по умолчанию будет char, для которого нет перегрузки функции CustomOutput

    std::string a = "   before SORT: ";
    CustomOutput(a);

    for (const auto& EL : BANK_LIST) CustomOutput(EL);

    a = "   after SORT: ";
    CustomOutput(a);

    BANK_LIST.sort();

    // Вывод отсортированных элементов
    for (auto& EL : BANK_LIST) CustomOutput(EL); // for (auto EL : BANK_LIST) CustomOutput(EL);

    a = "   Vector copied from List: ";
    CustomOutput(a);

    // Создание вектора объектов Bank_deposit
    std::vector<Bank_deposit> BANK_VEC;

    // Копирование элементов из списка в вектор
    std::copy(BANK_LIST.begin(), BANK_LIST.end(),std::back_inserter(BANK_VEC));

    // Вывод каждого элемента из скопированного списка
    for (const auto& EL : BANK_VEC) CustomOutput(EL);

    a = "   from set: ";
    CustomOutput(a);
    for (const auto& EL : setB) CustomOutput(EL);

    a = "   from unordored_set: ";
    CustomOutput(a);
    for (const auto& EL : unsetB) CustomOutput(EL);

    return 0;
}
