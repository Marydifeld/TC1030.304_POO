#include "Frutero.h"
#include <iostream>
using namespace std; 
Frutero::Frutero(){
    color = "Sin datos";
}
Frutero::Frutero(string col){
    color = col; 
}
string Frutero::getColor(){
    return color;
}
void Frutero::setColor(string col){
    color = col; 
}