#include <iostream>
#include <string>

struct BookInfo {
    int ydk;
    std::string autorName;
    std::string name;
    int count;
    int year;
    std::string izdanie;
};

int main() {
    int size = 10;
    BookInfo* mas = new BookInfo[size];
    for (BookInfo* w = mas; w != &mas[size]; w++) {
        w->ydk = 123;
        w->autorName = "Tolstoi";
        w->name = "Voina i Mir";
        w->count = 100000;
        w->year = 2000;
        w->izdanie = "Peterbyrg Izd";
    }

    for (BookInfo* r = mas; r != &mas[size]; r++) {
        std::cout << r->ydk
                  << r->autorName
                  << r->name
                  << r->count
                  << r->year
                  << r->izdanie
                  << std::endl;
    }
    delete[] mas;
    return 0;
}