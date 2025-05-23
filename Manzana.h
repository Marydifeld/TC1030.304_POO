#ifndef MANZANA_H
#define MANZANA_H
#include "Frutero.h"

#include <string>

//Sin terminar
using namespace std;

class Manzana : public Frutero {
    private:
        string carrera;

    public:
        Manzana(float peso);
        virtual ~Manzana();


        virtual string sabor();

        

};

#endif