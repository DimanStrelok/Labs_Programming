#include <string>
#include <locale>
#include <iostream>
#include <vector>

enum class Gender {
    Man = 0,
    Women
};

struct Employee {
    int t_num;
    std::string name;
    int salary;
    std::string post;
    Gender gender;

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "Номер: " << employee.t_num << "; "
           << "ФИО: " << employee.name << "; "
           << "Оклад: " << employee.salary << "; "
           << "Должность: " << employee.post << "; ";
        if (employee.gender == Gender::Man) {
            os << "Пол: Мужчина" << ".";
        } else {
            os << "Пол: Женщина" << ".";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Employee& employee) {
        is >> employee.t_num;
        is >> employee.name; // std::getline(is >> std::ws, employee.name);
        is >> employee.salary;
        is >> employee.post;
        std::string str;
        is >> str;
        if (str == "Мужчина") {
            employee.gender = Gender::Man;
        } else {
            employee.gender = Gender::Women;
        }
        return is;
    }
};

int sum_salary(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        res += employee.salary;
    }
    return res;
}

int sum_m(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == Gender::Man) {
            res++;
        }
    }
    return res;
}

int sum_f(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == Gender::Women) {
            res++;
        }
    }
    return res;
}

int sum_salary_m(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == Gender::Man) {
            res += employee.salary;
        }
    }
    return res;
}

int sum_salary_f(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == Gender::Women) {
            res += employee.salary;
        }
    }
    return res;
}

std::vector<Employee> enterEmployees() {
    std::vector<Employee> res;
    std::cout << "Введите кол-во работников" << std::endl;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        Employee temp;
        std::cin >> temp;
        res.push_back(temp);
    }
    return res;
}

void printEmployees(const std::vector<Employee>& employees) {
    std::cout << "Список" << std::endl;
    for (const Employee& employee : employees) {
        std::cout << employee << std::endl;
    }
}

// Type 1
/*
4
1 Вася 15500 Грузчик Мужчина
2 Катя 25000 Менеджер Женщина
3 Саня 35000 Программист Мужчина
4 Даша 15000 Кассир Женщина
*/

// Type 2
/*
4
1 Вася Пупкин
15500 Грузчик Мужчина
2 Катя Печкина
25000 Менеджер Женщина
3 Саня Петров
35000 Программист Мужчина
4 Даша Ельцина
15000 Кассир Женщина
*/

int main() {
    std::locale::global(std::locale(""));
    // Test
    std::vector<Employee> employees1 = {
            {1, "Вася", 5500,  "Грузчик",      Gender::Man},
            {2, "Петя", 7500,  "Строитель",    Gender::Women},
            {3, "Катя", 13000, "Менеджер",     Gender::Man},
            {4, "Даша", 25000, "Руководитель", Gender::Women}
    };
    std::vector<Employee> employees = enterEmployees();
    printEmployees(employees);
    std::cout << "Сумма окладов: " << sum_salary(employees) << std::endl;
    std::cout << "Кол-во мужчин: " << sum_m(employees) << std::endl;
    std::cout << "Кол-во женщин: " << sum_f(employees) << std::endl;
    std::cout << "Сумма окладов мужчин: " << sum_salary_m(employees) << std::endl;
    std::cout << "Сумма окладов женщин: " << sum_salary_f(employees) << std::endl;
    return 0;
}