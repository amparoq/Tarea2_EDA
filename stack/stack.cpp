#include"stack.hpp"
#include<string>
#include<iostream>

// class stack{
//     private:
//         node * head;
//     public:
//         stack();
//         void push(node *);
//         void pop();
//         node * top();
// }

stack::stack(){
    head = nullptr;
}

void stack::push(std::string data){
    node * n = new node(data);
    n->setNext(head);
    head = n;
}

void stack::push(node * n){
    n->setNext(head);
    head = n;
}

void stack::pop(){
    node * nhead = head->getNext();
    node * ohead = head;
    head = nhead;
    delete ohead;
}

node * stack::top(){
    return head;
}

void stack::print(){
    node * ptr = head;
    while(ptr != nullptr){
        ptr->print();
        ptr = ptr -> getNext();
    }
    std::cout<<std::endl;
}

bool stack::isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}

void stack::clear(){
    while(!isEmpty()){
        pop();
    }
}