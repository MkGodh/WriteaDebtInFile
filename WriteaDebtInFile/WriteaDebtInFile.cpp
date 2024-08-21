#include <iostream>
#include <fstream>
#include <string>

std::string getValidName() {
    std::string nameSurname;
    bool valid = false;
    while (!valid) {
        std::cout << "Please input name and surname: " << std::endl;
        std::getline(std::cin, nameSurname);
        if (nameSurname.empty()) {
            std::cerr << "Name cannot be empty!" << std::endl;
            continue;
        }
        valid = true;
        for (char c : nameSurname) {
            if (!isalpha(c) && !isspace(c)) {
                std::cerr << "Name contains invalid symbols" << std::endl;
                valid = false;
                break;
            }
        }

    }
    return nameSurname;
}
std::string getValidDate() {
    std::string date;
    bool valid = false;

    while (!valid) {
        std::cout << "Please input a date: " << std::endl;
        std::getline(std::cin, date);
        if (date.length() != 10 || date[2] != '.' || date[5] != '.') {
            std::cerr << "Incorrect date format! Please use dd.mm.yyyy." << std::endl;
            continue;
        }

        int day = std::stoi(date.substr(0, 2));
        if (day > 31 || day < 1)
        {
            std::cerr << "Incorrect day!" << std::endl;
            continue;
        }
        int month = std::stoi(date.substr(3, 2));
        if (month < 1 || month > 12)
        {
            std::cerr << "Incorrect month!" << std::endl;
            continue;
        }

        int year = std::stoi(date.substr(6, 4));
        if (year < 1900 || year > 2024)
        {
            std::cerr << "Incorrect year!" << std::endl;
            continue;
        }
        valid = true;

    }
    return date;
}
std::string getValidSum() {
    std::string sum;
    bool valid = false;

    while (!valid) {
        std::cout << "Please input a debt: " << std::endl;
        std::getline(std::cin, sum);

        bool hasDot = false;
        valid = true;
        for (char c : sum) {
            if (!isdigit(c)) {
                if (c == '.' && !hasDot) {
                    hasDot = true;
                }
                else {
                    std::cerr << "Debt contains invalid characters" << std::endl;
                    valid = false;
                    break;
                }
            }
        }
    }
    return sum;
}

int main()
{
    std::string nameSurname = getValidName();
    std::string date = getValidDate();
    std::string sum = getValidSum();
    std::ofstream ved("C:\\tutorial-data\\vedom.txt", std::ios::app);
    if (!ved.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    ved << nameSurname << " ";
    ved << date << " ";
    ved << sum << "\n";

    return  0;
}
