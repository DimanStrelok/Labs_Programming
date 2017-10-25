#include <string>
#include <locale>
#include <iostream>
#include <vector>
#include <fstream>

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

std::vector<Employee> loadEmployees(const std::string& name) {
    std::vector<Employee> res;
    std::ifstream file(name);
    int n = 0;
    std::string str;
    file >> str >> n;
    for (int i = 0; i < n; i++) {
        Employee temp;
        file >> str >> temp.t_num
             >> str >> temp.name
             >> str >> temp.salary
             >> str >> temp.post;
        file >> str >> str;
        if (str == "Мужчина") {
            temp.gender = Gender::Man;
        } else {
            temp.gender = Gender::Women;
        }
        res.push_back(temp);
    }
    return res;
}

void saveEmployees(const std::vector<Employee>& employees, const std::string& name) {
    std::ofstream file(name);
    file << "Список " << employees.size() << std::endl;
    for (const Employee& employee : employees) {
        file << "Номер: " << employee.t_num << '\n'
             << "ФИО: " << employee.name << '\n'
             << "Оклад: " << employee.salary << '\n'
             << "Должность: " << employee.post << '\n';
        if (employee.gender == Gender::Man) {
            file << "Пол: Мужчина" << '\n';
        } else {
            file << "Пол: Женщина" << '\n';
        }
    }
}

int main() {
    //std::locale::global(std::locale(""));
    std::vector<Employee> employees1 = loadEmployees("employees.txt");
    saveEmployees(employees1, "employees1.txt");
    std::vector<Employee> employees2 = loadEmployees("employees1.txt");
    saveEmployees(employees2, "employees2.txt");
    std::cout << "Сумма окладов: " << sum_salary(employees2) << std::endl;
    std::cout << "Кол-во мужчин: " << sum_m(employees2) << std::endl;
    std::cout << "Кол-во женщин: " << sum_f(employees2) << std::endl;
    std::cout << "Сумма окладов мужчин: " << sum_salary_m(employees2) << std::endl;
    std::cout << "Сумма окладов женщин: " << sum_salary_f(employees2) << std::endl;
    return 0;
}