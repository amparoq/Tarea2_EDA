#include"node.hpp"
#include<string>
#include<iostream>

node::node(){
    this->data="";
    this->ptrNext=nullptr;
}

node::node(std::string data){
    this->data=data;
    this->ptrNext=nullptr;
}

node::node(std::string data, node * ptrNext){
    this->data=data;
    this->ptrNext=ptrNext;
}

void node::setData(std::string data){
    this->data=data;
}

void node::setNext(node * ptrNext){
    this->ptrNext=ptrNext;
}

std::string node::getData(){
    return this->data;
}

node * node::getNext(){
    return this->ptrNext;
}

void node::print(){
    std::cout<<this->data<<" ";
}