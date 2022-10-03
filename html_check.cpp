#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include"stack.hpp"

int main(){
    const std::string filename("Error3.html");
    std::ifstream f_in(filename);
    std::stringstream nombre_out;
    // f_in.open(filename);
    int largo = filename.size();
    nombre_out << filename.substr(0,largo-4) <<"log";
    std::ofstream f_out(nombre_out.str());
    char symbol = '\0';
    char symbol_prev = '\0';
    bool tag = false;
    bool closing = false;
    bool opening = false;
    bool error = false;
    std::stringstream words;
    std::string p;
    stack * s = new stack();
    int linea = 1;
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
                        f_out<<"Error en linea "<<linea<<" : Se esperaba </"<<(s->top())->getData()<<"> en lugar de </"<<p<<">"<<std::endl;
                        error = true;
                        break;
                    }
                    if(p.compare((s->top())->getData()) != 0){
                        f_out<<"Error en linea "<<linea<<" : Se esperaba </"<<(s->top())->getData()<<"> en lugar de </"<<p<<">"<<std::endl;
                        error = true;
                        break;
                    }
                    if(p.compare((s->top())->getData()) == 0){
                        f_out<<"tag <"<<(s->top())->getData()<<"> ok"<<std::endl;
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
            if(symbol == '\n'){
                linea ++;
            }
        }
    }
    else std::cout<< "Error al leer " << filename << std::endl;
    if(!(s->isEmpty()) && error == false){
        f_out<<"¡Hubo un error! Los siguientes tag no están cerrados: "<<std::endl;
        while(!(s->isEmpty())){
            f_out<<(s->top())->getData()<<std::endl;
            s->pop();
        }
        error = true;
    }
    if(error == false) f_out<<"0 errores encontrados"<<std::endl;
    else f_out<<"Se encontraron errores"<<std::endl;
    delete s;
    f_in.close();
    f_out.close();
    return 0;
}
