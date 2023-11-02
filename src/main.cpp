#include "../headers/message.h"
#include "../headers/perms.h"
#include "../headers/user.h"
#include <fstream>
#include <iostream>
#include <string>

void create_file(const std::string& name) {
    std::fstream file = std::fstream(name, std::ios::in | std::ios::out);
    if(!file) {
        file = std::fstream(name, std::ios::in | std::ios::out | std::ios::trunc);
    }
}

int main() {
    std::string name_userFile = "user_data.txt";
    std::string name_messageFile = "message_data.txt";

    //создаем файлы
    create_file(name_userFile);
    create_file(name_messageFile);

    //устанавливаем права доступа на файлы
    set_permissions(name_userFile);
    set_permissions(name_messageFile);

    // создаем объекты
    User user("Dan", "dan123", "12345");
    Message message("Hello!", "Masha", "Dan");

    // Сохраняем объекты в файл
    user.SaveState(name_userFile);
    message.SaveState(name_messageFile);

    // Очищаем объекты
    user = User();
    message = Message();

    // Загружаем объекты из файла
    user.LoadState(name_userFile);
    message.LoadState(name_messageFile);

    // Выводим информацию на консоль
    user.Show();
    message.Show();

    // создаем новые объекты
    User user2("Anton", "an114", "13457");
    Message message2("Hi!", "Max", "Anton");

    //сохраняем и загружаем объекты с использованием перегруженных оператров "<< и >>"
    std::fstream file(name_userFile,
                      std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
    if(file.is_open()) {
        // запишем данные по в файл
        file << user2 << std::endl;
        file << message2 << std::endl;

        // Очищаем объекты
        user2 = User();
        message2 = Message();

        // Считываем данные из файла
        file.seekg(0, std::ios_base::beg);
        file >> user2;
        file >> message2;
    }
    file.close();

    // Выводим информацию на консоль
    user2.Show();
    message2.Show();
    

    return 0;
}
