#include"node.hpp"
#include<string>
#pragma once

class stack{
    private:
        node * head;
    public:
        stack();
        void push(std::string);
        void push(node *);
        void pop();
        node * top();
        bool isEmpty();
        void clear();
        void print();
};