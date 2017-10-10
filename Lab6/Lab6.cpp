#include <string>
#include <locale>
#include <iostream>
#include <vector>
#include <algorithm>

struct Employee {
    int t_num;
    std::string name;
    int salary;
    std::string post;
    std::string gender;

    Employee() {}

    Employee(int t_num_, const std::string& name_, int salary_, const std::string& post_, const std::string& gender_)
            : t_num(t_num_), name(name_), salary(salary_), post(post_), gender(gender_) {}

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "Номер: " << employee.t_num << std::endl;
        os << "ФИО: " << employee.name << std::endl;
        os << "Оклад: " << employee.salary << std::endl;
        os << "Должность: " << employee.post << std::endl;
        os << "Пол: " << employee.gender << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Employee& employee) {
        is >> employee.t_num;
        is >> employee.name;
        is >> employee.salary;
        is >> employee.post;
        is >> employee.gender;
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
        if (employee.gender == "Мужчина") {
            res++;
        }
    }
    return res;
}

int sum_f(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == "Женщина") {
            res++;
        }
    }
    return res;
}

int sum_salary_m(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == "Мужчина") {
            res += employee.salary;
        }
    }
    return res;
}

int sum_salary_f(const std::vector<Employee>& employees) {
    int res = 0;
    for (const Employee& employee : employees) {
        if (employee.gender == "Женщина") {
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

/*
1 Вася 15500 Грузчик Мужчина
2 Катя 25000 Менеджер Женщина
3 Саня 35000 Программист Мужчина
4 Даша 15000 Кассир Женщина
*/

int main() {
    std::locale::global(std::locale(""));
    std::vector<Employee> employees1 = {
            {1, "Вася", 5500,  "Грузчик",      "Мужчина"},
            {2, "Петя", 7500,  "Строитель",    "Мужчина"},
            {3, "Катя", 13000, "Менеджер",     "Женщина"},
            {4, "Даша", 25000, "Руководитель", "Женщина"}
    };
    std::vector<Employee> employees = enterEmployees();
    std::cout << "Сумма окладов: " << sum_salary(employees) << std::endl;
    std::cout << "Кол-во мужчин: " << sum_m(employees) << std::endl;
    std::cout << "Кол-во женщин: " << sum_f(employees) << std::endl;
    std::cout << "Сумма окладов мужчин: " << sum_salary_m(employees) << std::endl;
    std::cout << "Сумма окладов женщин: " << sum_salary_f(employees) << std::endl;
    return 0;
}