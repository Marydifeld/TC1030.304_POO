#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
#include <iostream>
using namespace std;

class Episodio {
private:
    string titulo;
    double duracion;
    int temporada;
    double calificacion;

public:
    Episodio();
    Episodio(string, double, int, double);
    void mostrar() const;
    double getDuracion() const;
    double getCalificacion() const;
};

#endif
