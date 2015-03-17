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
private:
    int i;
    Stack<string> temp;
    string item;
};

CommandProcessor::CommandProcessor(){ i = 0; }

CommandProcessor::~CommandProcessor(){}

void CommandProcessor::Undo(int n){
    if(i<n && this->isEmpty()!=1){
        this->Pop(item);
        temp.Push(item);
        std::cout << item + " ";
        i++;
    }
}

void CommandProcessor::Redo(int n){
    if(i>=n && temp.isEmpty()!=1){
        temp.Pop(item);
        this->Push(item);
        std::cout << item + " ";
        i--;
    }
}

#endif
