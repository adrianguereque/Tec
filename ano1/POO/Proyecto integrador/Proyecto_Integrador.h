#include <iostream>
using namespace std;
class Video{
    private:
        string tipovideo, nombrevideo, genero;
        int aniolanzamiento, duracion, calificacion=0;
    public:
        Video(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion);
        Video(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _calificacion);
    void calificaVideo(int _calificacion);
    virtual void muestraDatos();
    void muestraFiltroCalificacion(int cal);
};
class Pelicula:public Video{
    public:
        Pelicula(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _nominaciones, int _calificacion);
        Pelicula(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _nominaciones);
        void muestraDatos();
    private:
        int nominaciones=0;
};
class Serie:public Video{
    public:
        Serie(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _temporadas, int _capitulos, int _calificacion);
        Serie(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion,  int _temporadas, int _capitulos);
        void muestraDatos();
    private:
        int temporadas, capitulos;
};