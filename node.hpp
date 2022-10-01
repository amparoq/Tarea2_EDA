#include<string>
#pragma once

class node{
    private:
        std::string data;
        node * ptrNext;
    public:
        node();
        node(std::string data);
        node(std::string data, node * ptrNext);
        void setData(std::string data);
        void setNext(node * ptrNext);
        std::string getData();
        node * getNext();
        void print();
};