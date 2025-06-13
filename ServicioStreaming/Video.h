#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Video {
protected:
    int id;
    string nombre;
    double duracion;
    string genero;
    vector<double> calificaciones;

public:
    Video();
    Video(int, string, double, string);
    virtual void mostrarInfo() const = 0;
    void agregarCalificacion(double);
    double obtenerPromedio() const;
    string getGenero() const;
    string getNombre() const;
    virtual ~Video() {}
};

#endif
