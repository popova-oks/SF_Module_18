#include "../headers/message.h"

Message::Message() : _text{}, _sender{}, _receiver{} {}

Message::Message(std::string text, std::string sender, std::string receiver)
    : _text(text), _sender(sender), _receiver(receiver) {}

// Функция для сохранения объекта Message в файл
void Message::SaveState(const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
    if(file.is_open()) {
        file.write(_text.data(), _text.size());
        file.put('\0');
        file.write(_sender.data(), _sender.size());
        file.put('\0');
        file.write(_receiver.data(), _receiver.size());
        file.put('\0');
        file.close();
        std::cout << "Message state saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

// Функция для загрузки объекта Message из файла
void Message::LoadState(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if(file.is_open()) {
        std::getline(file, _text, '\0');
        std::getline(file, _sender, '\0');
        std::getline(file, _receiver, '\0');
        file.close();
        std::cout << "Message state loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open the file for reading." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Message& message) {
    os << message._text;
    os << ' ';
    os << message._sender;
    os << ' ';
    os << message._receiver;
    os << ' ';
    return os;
}

std::fstream& operator>>(std::fstream& is, Message& obj) {
    is >> obj._text;
    is >> obj._sender;
    is >> obj._receiver;
    return is;
}

void Message::Show() {
    std::cout << "\nMessage:\t" << _text;
    std::cout << "\nSender:\t\t" << _sender;
    std::cout << "\nReceiver:\t" << _receiver << std::endl;
}