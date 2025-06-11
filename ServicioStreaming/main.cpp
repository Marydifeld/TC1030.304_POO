#include "Pelicula.h"
#include "Serie.h"
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    vector<Video *> videos;
    Serie *serieActual = nullptr;
    int idCounter = 1;

    ifstream archivo("datos.txt");
    string linea;

    while (getline(archivo, linea))
    {
        if (linea.empty())
            continue;

        string tipo;
        istringstream stream(linea);
        getline(stream, tipo, ',');

        if (tipo == "Pelicula")
        {
            string nombre, genero;
            double duracion;
            double calificacion;

            getline(stream, nombre, ',');
            getline(stream, genero, ',');
            stream >> duracion;
            stream.ignore();
            stream >> calificacion;

            Pelicula *pelicula = new Pelicula(idCounter, nombre, duracion, genero);
            idCounter++;

            pelicula->agregarCalificacion(calificacion);
            videos.push_back(pelicula);
        }
        else if (tipo == "Serie")
        {
            string nombre, genero;
            double duracion = 0.0;

            getline(stream, nombre, ',');
            getline(stream, genero, ',');

            serieActual = new Serie(idCounter, nombre, duracion, genero);
            idCounter++;

            videos.push_back(serieActual);
        }
        else if (tipo == "Episodio" && serieActual != nullptr)
        {
            string titulo;
            int temporada;
            double duracion, calificacion;

            getline(stream, titulo, ',');
            stream >> temporada;
            stream.ignore();
            stream >> duracion;
            stream.ignore();
            stream >> calificacion;

            Episodio ep(temporada, titulo, duracion, temporada, calificacion);
            serieActual->agregarEpisodio(ep);
        }
    }

    archivo.close();

    cout << "=== VIDEOS REGISTRADOS ===" << endl;
    for (int i = 0; i < videos.size(); i++)
    {
        videos[i]->mostrarInfo();
        cout << endl;
    }

    for (int i = 0; i < videos.size(); i++)
    {
        delete videos[i];
    }

    return 0;
}
