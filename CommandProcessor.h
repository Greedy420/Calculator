#ifndef COMPROCESSOR_H
#define COMPROCESSOR_H
#include "Stack.h"
#include <string>

class CommandProcessor : public Stack<string> {
public:
    CommandProcessor();
    ~CommandProcessor();
    void Undo();
    void Redo();
};

CommandProcessor::CommandProcessor(){}

CommandProcessor::~CommandProcessor(){}

int i = 0;

void CommandProcessor::Undo(int n){
    Stack<string> temp;
    string item;

    if(i<n && this->isEmpty()!=1){
        this->Pop(item);
        temp.Push(item);
        std::cout << item + " ";
        i++;
    }
}

void CommandProcessor::Redo(int n){
    Stack<string> temp;
    string item;

    if(i>=n && temp.isEmpty()!=1){
        temp.Pop(item);
        this->Push(item);
        std::cout << item + " ";
        i--;
    }
}

