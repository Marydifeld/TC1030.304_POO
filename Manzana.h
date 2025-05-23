#ifndef MANZANA_H
#define MANZANA_H
#include "Frutero.h"

#include <string>

//Sin terminar
using namespace std;

class Manzana : public Frutero {
    private:
        string tipo; //puede ser de tipo Gala, Golden, etc

    public:
        Manzana();
        Manzana(string color, string tipo);
        ~Manzana();

        void setTipo(string);
        string getTipo();

        void ShowFruit() override; //override checa si hay errores en la clase
    

};

#endif