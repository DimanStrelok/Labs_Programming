#include <locale>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

int sum(const std::vector<int>& mas) {
    int res = 0;
    for (size_t i = 0; i < mas.size(); i++) {
        res += mas[i];
    }
    return res;
}

int mul(const std::vector<int>& mas) {
    int res = 1;
    for (size_t i = 0; i < mas.size(); i++) {
        res *= mas[i];
    }
    return res;
}

int sumd(const std::vector<std::vector<int>>& mat) {
    int res = 0;
    for (size_t i = 0; i < mat.size() && i < mat[0].size(); i++) {
        res += mat[i][i];
    }
    return res;
}

int sumdu(const std::vector<std::vector<int>>& mat) {
    int res = 0;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[0].size(); j++) {
            if (i < j) {
                res += mat[i][j];
            }
        }
    }
    return res;
}

int sumdd(const std::vector<std::vector<int>>& mat) {
    int res = 0;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[0].size(); j++) {
            if (i > j) {
                res += mat[i][j];
            }
        }
    }
    return res;
}

int mulpd(const std::vector<std::vector<int>>& mat) {
    int res = 1;
    for (size_t j = 0; j < mat[0].size() && mat.size() - j > 0; j++) {
        res *= mat[mat.size() - j - 1][j];
    }
    return res;
}

std::vector<int> max_ch_str(const std::vector<std::vector<int>>& mat) {
    std::vector<int> res;
    for (size_t i = 1; i < mat.size(); i += 2) {
        res.push_back(0);
        for (size_t j = 0; j < mat[0].size(); j++) {
            res.back() = std::max<int>(res.back(), mat[i][j]);
        }
    }
    return res;
}

std::vector<int> min_noch_stlb(const std::vector<std::vector<int>>& mat) {
    std::vector<int> res;
    for (size_t j = 0; j < mat[0].size(); j += 2) {
        res.push_back(999999);
        for (size_t i = 0; i < mat.size(); i++) {
            res.back() = std::min<int>(res.back(), mat[i][j]);
        }
    }
    return res;
}

std::vector<std::vector<int>> mulMatMat(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    if (mat1[0].size() != mat2.size()) {
        return {};
    }
    std::vector<std::vector<int>> res(mat1.size(), std::vector<int>(mat2[0].size(), 0));
    for (size_t i = 0; i < mat1.size(); i++) {
        for (size_t l = 0; l < mat2[0].size(); l++) {
            for (size_t j = 0; j < mat1[0].size(); j++) {
                res[i][l] += mat1[i][j] * mat2[j][l];
            }
        }
    }
    return res;
}

void printMas(const std::vector<int>& mas) {
    std::cout << "Massive size = " << mas.size() << std::endl;
    for (size_t i = 0; i < mas.size(); i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}

void printMat(const std::vector<std::vector<int>>& mat) {
    std::cout << "Matrix " << mat.size() << "x" << mat[0].size() << std::endl;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[0].size(); j++) {
            std::cout << std::setw(3) << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void testMas() {
    std::vector<int> mas = {1, 2, 3, 4, 5};
    printMas(mas);
    std::cout << "Сумма элементов = " << sum(mas) << std::endl;
    std::cout << "Произведение элементов = " << mul(mas) << std::endl;
}

void testMat() {
    std::vector<std::vector<int>> mat = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
    printMat(mat);
    std::cout << "Сумма элементов главной диагонали = " << sumd(mat) << std::endl;
    std::cout << "Сумма элементов выше главной диагонали = " << sumdu(mat) << std::endl;
    std::cout << "Сумма элементов ниже главной диагонали = " << sumdd(mat) << std::endl;
    std::cout << "Произведение элементов побочной диагонали = " << mulpd(mat) << std::endl;
    std::vector<int> res1 = max_ch_str(mat);
    std::cout << "Максимумы чётных строк матрицы" << std::endl;
    printMas(res1);
    std::vector<int> res2 = min_noch_stlb(mat);
    std::cout << "Минимумы нечётных столбцов матрицы" << std::endl;
    printMas(res2);
    std::cout << "Произведение двух матриц" << std::endl;
    std::vector<std::vector<int>> mat1 = {
            {1, 2},
            {3, 4}
    };
    std::cout << "1 матрица" << std::endl;
    printMat(mat1);
    std::vector<std::vector<int>> mat2 = {
            {4, 3},
            {2, 1}
    };
    std::cout << "2 матрица" << std::endl;
    printMat(mat2);
    std::vector<std::vector<int>> res = mulMatMat(mat1, mat2);
    if (!res.empty()) {
        std::cout << "Результат" << std::endl;
        printMat(res);
    } else {
        std::cout << "Умножение невозможно" << std::endl;
    }
}

int main() {
    std::locale::global(std::locale(""));
    testMas();
    testMat();
    return 0;
}
