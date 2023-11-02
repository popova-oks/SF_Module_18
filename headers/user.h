#pragma once

#include <iostream>
#include <fstream>
#include <string>

class User {
private:
    std::string _name;
    std::string _login;
    std::string _pass;

public:
    User ();
    User (std::string name, std::string login, std::string pass);

    friend std::ostream &operator<< (std::ostream &os, const User &user);
    friend std::fstream &operator>> (std::fstream &is, User &user);

    void SaveState(const std::string& name);
    void LoadState(const std::string& filename);

    void Show();
};