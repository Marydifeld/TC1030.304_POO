#include "Pelicula.h"
#include "Serie.h"
#include <fstream>
#include <sstream>

int main() {
    vector<Video*> videos;
    Serie* serieActual = nullptr;
    int idCounter = 1;

    ifstream archivo("datos.txt");
    string linea;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        istringstream stream(linea);
        string tipo;
        getline(stream, tipo, ',');

        if (tipo == "Pelicula") {
            string nombre, genero;
            double duracion, calificacion;
            getline(stream, nombre, ',');
            getline(stream, genero, ',');
            stream >> duracion;
            stream.ignore();
            stream >> calificacion;

            Pelicula* p = new Pelicula(idCounter++, nombre, duracion, genero);
            p->agregarCalificacion(calificacion);
            videos.push_back(p);
        }
        else if (tipo == "Serie") {
            string nombre, genero;
            getline(stream, nombre, ',');
            getline(stream, genero, ',');

            serieActual = new Serie(idCounter++, nombre, 0, genero);
            videos.push_back(serieActual);
        }
        else if (tipo == "Episodio" && serieActual != nullptr) {
            string titulo;
            double duracion, calificacion;
            int temporada;
            getline(stream, titulo, ',');
            stream >> temporada;
            stream.ignore();
            stream >> duracion;
            stream.ignore();
            stream >> calificacion;

            Episodio ep(titulo, duracion, temporada, calificacion);
            serieActual->agregarEpisodio(ep);
        }
    }

    archivo.close();

    // Mostrar todo
    cout << "\n=== Todos los Videos ===\n";
    for (int i = 0; i < videos.size(); i++) {
        videos[i]->mostrarInfo();
        cout << endl;
    }

    // Mostrar solo películas por género
    cout << "\n=== Peliculas de genero 'Drama' ===\n";
    for (int i = 0; i < videos.size(); i++) {
        if (videos[i]->getGenero() == "Drama") {
            Pelicula* p = dynamic_cast<Pelicula*>(videos[i]);
            if (p != nullptr) {
                p->mostrarInfo();
            }
        }
    }

    // Mostrar solo series por género
    cout << "\n=== Series de genero 'Ciencia Ficcion' ===\n";
    for (int i = 0; i < videos.size(); i++) {
        if (videos[i]->getGenero() == "Ciencia Ficcion") {
            Serie* s = dynamic_cast<Serie*>(videos[i]);
            if (s != nullptr) {
                s->mostrarInfo();
            }
        }
    }

    for (int i = 0; i < videos.size(); i++) {
        delete videos[i];
    }

    return 0;
}
