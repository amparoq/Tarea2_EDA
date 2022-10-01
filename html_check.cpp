#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include"stack.hpp"

int main(){
    const std::string filename("Error3.html");
    std::ifstream f_in(filename);
    // f_in.open(filename);
    char symbol = '\0';
    char symbol_prev = '\0';
    bool tag = false;
    bool closing = false;
    bool opening = false;
    std::stringstream words;
    std::string p;
    stack * s = new stack();
    if (f_in.is_open()){
        while (f_in.get(symbol)){
            if(symbol_prev == '<'){
                tag = true;
                if(symbol == '/'){
                    opening = false;
                    closing = true;
                }
                else{
                    opening = true;
                    closing = false;
                }
            }
            if(symbol == '>' && tag == true){
                tag = false;
                p = words.str();
                if(opening == true){
                    s->push(p);
                }
                if(closing == true){
                    if(s->top()==nullptr){
                        std::cout<<"hubo un error con el tag: "<<p<<std::endl;
                        std::cout<<"No cierra nada"<<std::endl;
                        break;
                    }
                    if(p.compare((s->top())->getData()) != 0){
                        std::cout<<"hubo un error con el tag: "<<p<<std::endl;
                        std::cout<<"Se esperaba: "<<(s->top())->getData()<<std::endl;
                        break;
                    }
                    if(p.compare((s->top())->getData()) == 0){
                        s->pop();
                    }
                }
                opening = false;
                closing = false;
                // std::cout<<words.str()<<std::endl;
                words.str("");
            }
            if(tag == true && symbol != '/'){
                words<<symbol;
            }
            symbol_prev = symbol;
        }
    }
    else{
        std::cout<< "Error al leer " << filename << std::endl;
    }
    delete s;
    f_in.close();
    return 0;
}
