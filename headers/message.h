#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Message {
private:
    std::string _text;
    std::string _sender;
    std::string _receiver;

public:
    Message ();
    Message(std::string text, std::string sender, std::string receiver);

    friend std::ostream& operator<<(std::ostream& os, const Message& message);
    friend std::fstream& operator>>(std::fstream& is, Message &obj);

    void SaveState(const std::string& filename);
    void LoadState(const std::string& filename);
    
    void Show();
};
