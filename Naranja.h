#ifndef NARANJA_H
#define NARANJA_H
#include "Frutero.h"

#include <string>

//Sin terminar
using namespace std;

class Naranja : public Frutero {
    private:
        string carrera;

    public:
        Naranja(float peso);
        virtual ~Naranja();


        virtual string sabor();

        

};

#endif
