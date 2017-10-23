#include <string>
#include <locale>
#include <iostream>
#include <vector>

struct Lexeme {
    std::string name;
    std::string text;
};

Lexeme parse(const std::string& text) {
    Lexeme lexeme;
    lexeme.name = "Error";
    lexeme.text = text;
    if (std::isalpha(text[0])) {
        bool isIdent = true;
        for (char c : text) {
            if (!std::isalpha(c) && !std::isdigit(c)) {
                isIdent = false;
                break;
            }
        }
        if (isIdent) {
            lexeme.name = "Идентификатор";
            lexeme.text = text;
            return lexeme;
        }
    } else if (std::isdigit(text[0])) {
        bool isNumber = true;
        for (char c : text) {
            if (!std::isdigit(c)) {
                isNumber = false;
                break;
            }
        }
        if (isNumber) {
            lexeme.name = "Число";
            lexeme.text = text;
            return lexeme;
        }
    } else {
        if (text == "<=") {
            lexeme.name = "Меньше или равно";
            lexeme.text = text;
            return lexeme;
        } else if (text == ">=") {
            lexeme.name = "Больше или равно";
            lexeme.text = text;
            return lexeme;
        } else if (text == ":=") {
            lexeme.name = "Присвоить";
            lexeme.text = text;
            return lexeme;
        }
    }
    return lexeme;
}

int main() {
    std::locale::global(std::locale(""));
    std::vector<Lexeme> lexemes;
    int n;
    std::string str;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> str;
        Lexeme lexeme = parse(str);
        if (lexeme.name != "Error") {
            lexemes.push_back(lexeme);
        } else {
            std::cout << "Error: " << lexeme.text << std::endl;
        }
    }
    for (Lexeme& lexeme : lexemes) {
        std::cout << "Тип лексемы: " << lexeme.name << std::endl;
        std::cout << "Текст: " << lexeme.text << std::endl;
    }
    return 0;
}