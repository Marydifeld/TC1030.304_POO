#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
using namespace std;

class Episodio
{
private:
    int numEpisodio;
    string tituloEpisodio;
    double duracion;
    int temporada;
    double calificacion;

public:
    Episodio();
    Episodio(int, string, double, int, double);
    double getDuracion() const;
    double getCalificacion() const;
    void mostrar() const;
};

#endif
