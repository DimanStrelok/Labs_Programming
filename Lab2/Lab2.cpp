#include <string>
#include <iostream>
#include <algorithm>

int romanToArab(const std::string& roman) {
    bool ok = true;
    int n = 0, state = 1;
    for (char c : roman) {
        switch (c) {
            case 'X':
                switch (state) {
                    case 1:
                        n = 10;
                        state = 2;
                        break;
                    case 2:
                        n += 10;
                        state = 2;
                        break;
                    case 3:
                    case 4:
                    case 5:
                    case 7:
                        std::cout << "Error" << std::endl;
                        ok = false;
                        break;
                    case 6:
                        n += 8;
                        state = 7;
                        break;
                }
                break;
            case 'V':
                switch (state) {
                    case 1:
                        n = 5;
                        state = 3;
                        break;
                    case 2:
                        n += 5;
                        state = 3;
                        break;
                    case 3:
                    case 4:
                    case 5:
                    case 7:
                        std::cout << "Error" << std::endl;
                        ok = false;
                        break;
                    case 6:
                        n += 3;
                        state = 7;
                        break;
                }
                break;
            case 'I':
                switch (state) {
                    case 1:
                        n = 1;
                        state = 6;
                        break;
                    case 2:
                        n += 1;
                        state = 6;
                        break;
                    case 3:
                        n += 1;
                        state = 4;
                        break;
                    case 4:
                        n += 1;
                        state = 5;
                        break;
                    case 5:
                        n += 1;
                        state = 7;
                        break;
                    case 6:
                        n += 1;
                        state = 5;
                        break;
                    case 7:
                        std::cout << "Error" << std::endl;
                        ok = false;
                        break;
                }
                break;
            default:
                std::cout << "Error wrong char" << std::endl;
                ok = false;
                break;
        }
        if (!ok) {
            n = 0;
            break;
        }
    }
    return n;
}

int main() {
    std::cout << "Enter Roman number or QUIT" << std::endl;
    std::string s;
    do {
        std::cin >> s;
        std::transform(s.begin(), s.end(), s.begin(), toupper);
        if (s != "QUIT") {
            std::cout << romanToArab(s) << std::endl;
        }
    } while (s != "QUIT");
    return 0;
}