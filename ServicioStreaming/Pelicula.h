#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(int, string, double, string);
    void mostrarInfo() const override;
};

#endif
