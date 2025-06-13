#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>

class Serie : public Video {
private:
    vector<Episodio> episodios;

public:
    Serie();
    Serie(int, string, double, string);
    void agregarEpisodio(Episodio);
    void mostrarInfo() const override;
};

#endif
