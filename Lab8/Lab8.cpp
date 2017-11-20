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
        }
        if (text == ">=") {
            lexeme.name = "Больше или равно";
            lexeme.text = text;
            return lexeme;
        }
        if (text == ":=") {
            lexeme.name = "Присвоить";
            lexeme.text = text;
            return lexeme;
        }
    }
    return lexeme;
}

int main() {
    //std::locale::global(std::locale(""));
    std::vector<Lexeme> lexemes;
    std::string str;
    std::getline(std::cin, str);
    while (!str.empty()) {
        Lexeme lexeme = parse(str.substr(0, str.find(' ')));
        if (lexeme.name == "Error") {
            std::cout << "Error: " << lexeme.text << std::endl;
        } else {
            lexemes.push_back(lexeme);
        }
        if (str.find(' ') != std::string::npos) {
            str = str.substr(str.find(' ') + 1, str.size());
        } else {
            str.clear();
        }
    }
    for (const Lexeme& lexeme : lexemes) {
        std::cout << "Тип лексемы: " << lexeme.name << std::endl;
        std::cout << "Текст: " << lexeme.text << std::endl;
    }
    //std::system("pause");
    return 0;
}