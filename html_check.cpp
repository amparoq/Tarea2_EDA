#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

int main(){
    const string filename("ej1.html");
    ifstream f_in(filename);
    // f_in.open(filename);
    char symbol = '\0';
    char symbol_prev = '\0';
    bool tag = false;
    bool closing = false;
    bool opening = false;
    stringstream words;
    if (f_in.is_open()){
        while (f_in.get(symbol)){
            if(symbol_prev == '<'){
                tag = true;
                opening = true;
                closing = false;
            }
            if(symbol_prev == '/' && tag == true){
                opening = false;
                closing = true;
            }
            if(symbol == '>' && tag == true){
                tag = false;
                opening = false;
                closing = false;
                cout<<words.str()<<endl;
                words.str("");
            }
            if(tag == true){
                words<<symbol;
            }
            symbol_prev = symbol;
        }
    }
    else{
        cout<< "Error al leer " << filename << endl;
    }
    f_in.close();
    return 0;
}
