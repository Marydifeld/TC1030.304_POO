#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>

class Serie : public Video
{
private:
    vector<Episodio> episodios;

public:
    Serie();
    Serie(int, string, double, string);
    void agregarEpisodio(const Episodio &);
    int calculaEpisodios() const;
    double calculaDuracion() const;
    double calculaPromedio() const;
    void mostrarInfo() const override;
};

#endif
