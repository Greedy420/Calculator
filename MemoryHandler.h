#ifndef MEMORYHANDLER_H
#define MEMORYHANDLER_H
#include "Stack.h"
#include <string>
#include <fstream>

class MemoryHandler {
public:
    MemoryHandler();
    ~MemoryHandler();
    void PushToMem(string item);
    void PrintNMem(int n = 1);
    void PrintAll();
    void SaveMem();

private:
    Stack<string> Memory;
};

MemoryHandler::MemoryHandler() {
}

MemoryHandler::~MemoryHandler() {
}

void MemoryHandler::PushToMem(string item) {
    Memory.Push(item);
}

void MemoryHandler::PrintNMem(int n) {
    string item;
    Stack<string> temp;
    int i = 1;

    if (Memory.isEmpty() == 1)
        std::cout << "Memory is empty" << endl;

    while (i<=n && Memory.isEmpty()!=1) {
        Memory.Pop(item);
        temp.Push(item);
        std::cout << item << endl;
        i += 1;
    }
    while (temp.isEmpty()!=1) {
        temp.Pop(item);
        Memory.Push(item);
    }
}

void MemoryHandler::PrintAll() {
    string item;
    Stack<string> temp;

    if (Memory.isEmpty() == 1)
        std::cout << "Memory is empty" << endl;

    while (Memory.isEmpty()!=1) {
        Memory.Pop(item);
        temp.Push(item);
        std::cout << item << endl;
    }
    while (temp.isEmpty()!=1) {
        temp.Pop(item);
        Memory.Push(item);
    }
}

void MemoryHandler::SaveMem() {
    string item;
    Stack<string> temp;

    ofstream file("LastSavedMemory.txt");
    while (Memory.isEmpty()!=1) {
        Memory.Pop(item);
        temp.Push(item);
        file << item << std::endl;
    }
    while (temp.isEmpty()!=1) {
        temp.Pop(item);
        Memory.Push(item);
    }

    file.close();
    std::cout << "Memory saved to text file" << endl;
}

#endif // MEMORYHANDLER_H
