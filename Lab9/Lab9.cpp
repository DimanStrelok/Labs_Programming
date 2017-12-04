#include <iostream>
#include <string>
#include <fstream>

void saveText(const std::string& text, const std::string& name) {
    std::ofstream file(name);
    file << text;
}

std::string loadText(const std::string& name) {
    std::ifstream file(name);
    std::string s, t;
    std::getline(file, t);
    s.append(t);
    while (!t.empty()) {
        std::getline(file, t);
        s.push_back('\n');
        s.append(t);
    }
    return s;
}

void reWriteText(const std::string& name) {
    std::string s = loadText(name);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            if (i == 0 || s[i - 1] == '\n' || (i - 2 >= 0 && s[i - 2] == '.') || s[i - 1] == '.') {
                s.erase(i, 1);
                i--;
                continue;
            }
            if (i - 1 >= 0 && s[i - 1] == ' ') {
                s.erase(i - 1, 1);
                i -= 2;
                continue;
            }
            if (s[i + 1] == ',') {
                s.erase(i + 1, 1);
                i--;
                continue;
            }
            if (s[i + 1] != ' ') {
                s.insert(i + 1, 1, ' ');
            }
        }
    }
    saveText(s, name);
}

int main() {
    //std::locale::global(std::locale(""));
    std::string s, t;
    std::getline(std::cin, t);
    s.append(t);
    while (!t.empty()) {
        std::getline(std::cin, t);
        s.push_back('\n');
        s.append(t);
    }
    saveText(s, "text1.txt");
    reWriteText("text1.txt");
    s = loadText("text1.txt");
    std::cout << s << std::endl;
    return 0;
}