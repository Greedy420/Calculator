#ifndef MEMHANDLER_H
#define MEMHANDLER_H
#include <string>

class MemoryHandler : public Stack<string> {
public:
    MemoryHandler();
    ~MemoryHandler();
    void PrintNMem(int n = 1);
    void PrintAll();
};

MemoryHandler::MemoryHandler() {
}

MemoryHandler::~MemoryHandler() {
}

void MemoryHandler::PrintNMem(int n) {
    Stack<string> temp;
    string item;
    int i = 1;

    while (i<=n && this->isEmpty()!=1) {
        this->Pop(item);
        temp.Push(item);
        std::cout << item + " ";
        i += 1;
    }
    while (temp.isEmpty()!=1) {
        temp.Pop(item);
        this->Push(item);
    }
}

void MemoryHandler::PrintAll() {
    Stack<string> temp;
    string item;

    while (this->isEmpty()!=1) {
        this->Pop(item);
        temp.Push(item);
        std::cout << item + " ";
    }
    while (temp.isEmpty()!=1) {
        temp.Pop(item);
        this->Push(item);
    }
}

#endif // MEMHANDLER_H
