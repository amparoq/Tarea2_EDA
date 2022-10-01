#include"stack.hpp"
#include<string>
#include<sstream>
#include<iostream>

int main(){
    stack pila = stack();
    std::string s= "</hola>";
    std::string sl;
    sl = s.substr(2,5);
    std::cout<<sl<<std::endl;
    return 0;
}