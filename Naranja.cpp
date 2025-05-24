#include "Naranja.h"
#include <iostream>
using namespace std;
Naranja::Naranja(): Frutero(){
    tipo = "Sin datos";
}
Naranja::Naranja(string col, string tip): Frutero(col){
    tipo = tip; 
}
void Naranja::setTipo(string tip){
    tipo = tip; 
}
string Naranja::getTipo(){
    return tipo; 
}
void Naranja::ShowFruit(){
    cout << "Esto es una naranja." << endl;
}
