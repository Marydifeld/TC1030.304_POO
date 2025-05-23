#include "Manzana.h"
#include <iostream>
using namespace std;
Manzana::Manzana(): Frutero(){
    tipo = "Sin datos";
}
Manzana::Manzana(string col, string tip): Frutero(col){
    tipo = tip; 
}
void Manzana::setTipo(string tip){
    tipo = tip; 
}
string Manzana::getTipo(){
    return tipo; 
}
void Manzana::ShowFruit(){
    cout << "Esto es una manzana.";
}

