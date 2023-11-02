#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem; //создаем псевдоним

void demo_perms(fs::perms p) //функция для демонстрации прав доступа к файлу
{
    std::cout << "\n";
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-") << '\n';
}

void set_permissions(const std::string& name) {
    // Устанавливаем права доступа только для владельца
    fs::permissions(name, fs::perms::owner_read | fs::perms::owner_write,
                    fs::perm_options::replace);

    demo_perms(fs::status(name).permissions());
}