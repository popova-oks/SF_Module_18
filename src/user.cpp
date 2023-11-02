#include "../headers/user.h"

User::User() : _name{}, _login{}, _pass{} {}

User::User(std::string name, std::string login, std::string pass)
    : _name(name), _login(login), _pass(pass) {}

// Функция для сохранения объекта User в файл
void User::SaveState(const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
    if(file.is_open()) {
        file.write(_name.data(), _name.size());
        file.put('\0');
        file.write(_login.data(), _login.size());
        file.put('\0');
        file.write(_pass.data(), _pass.size());
        file.put('\0');
        file.close();
        std::cout << "User state saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

// Функция для загрузки объекта User из файла
void User::LoadState(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if(file.is_open()) {
        std::getline(file, _name, '\0');
        std::getline(file, _login, '\0');
        std::getline(file, _pass, '\0');
        file.close();
        std::cout << "User state loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the file for reading." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user._name;
    os << ' ';
    os << user._login;
    os << ' ';
    os << user._pass;
    os << ' ';
    return os;
}

std::fstream& operator>>(std::fstream& is, User& user) {
    is >> user._name;
    is >> user._login;
    is >> user._pass;
    return is;
}

void User::Show() {
    std::cout << "\nName:\t\t" << _name;
    std::cout << "\nLogin:\t\t" << _login;
    std::cout << "\nPassword:\t" << _pass << std::endl;
}