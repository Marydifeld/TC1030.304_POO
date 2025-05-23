#ifndef NARANJA_H
#define NARANJA_H
#include "Frutero.h"

#include <string>

//Sin terminar
using namespace std;

class Naranja : public Frutero {
    private:
        string tipo; //puede ser de tipo , etc

    public:
        Naranja();
        Naranja(string color, string tipo);

        void setTipo(string);
        string getTipo();

        void ShowFruit() override; //override checa si hay errores en la clase
    

};

#endif
