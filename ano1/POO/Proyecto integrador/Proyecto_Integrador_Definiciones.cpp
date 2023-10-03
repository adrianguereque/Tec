#include "Proyecto_Integrador.h"
#include <iostream>
// .................Definiciones Super-clase Video......................
 Video::Video(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion){
            tipovideo = _tipovideo; nombrevideo = _nombrevideo; genero = _genero;
            aniolanzamiento = _aniolanzamiento; duracion = _duracion;
        };
Video::Video(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _calificacion){
            tipovideo = _tipovideo; nombrevideo = _nombrevideo; genero = _genero;
            aniolanzamiento = _aniolanzamiento; duracion = _duracion;
            calificacion=_calificacion;
        };
     void Video::calificaVideo(int _calificacion){
        calificacion = _calificacion;
    };
  void Video::muestraDatos(){
        cout<<nombrevideo<<" es un/una "<<tipovideo<< " genero "<<genero<<endl;
        cout<<"publicado en "<<aniolanzamiento<<" con duracion de "<<duracion<<" minutos"<<endl<<endl;
        if(calificacion>0){
            cout<<"Su calificacion es de "<<calificacion<<"/10"<<endl<<endl;
        };
    };
     void Video::muestraFiltroCalificacion(int cal){
            if(calificacion>=cal){
                this->muestraDatos();
            }
        }
//.............Definiciones Subclase Pelicula....................//
 Pelicula::Pelicula(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _nominaciones, int _calificacion):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion, _calificacion){
            nominaciones = _nominaciones;
        };
 Pelicula::Pelicula(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _nominaciones):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion){
            nominaciones = _nominaciones;
        };
  void Pelicula::muestraDatos(){
            Video::muestraDatos();
            if(nominaciones>0){
                cout<<"La pelicula tiene "<<nominaciones<<" nominacion(es)"<<endl<<endl;
            }
            else{
                cout<<"La pelicula no tiene nominaciones"<<endl<<endl;
            };
        };
//..............Definiciones Subclase Serie........................
 Serie::Serie(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _temporadas, int _capitulos, int _calificacion):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion, _calificacion){
            temporadas = _temporadas;
            capitulos = _capitulos;
        };
 Serie::Serie(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion,  int _temporadas, int _capitulos):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion){
            temporadas = _temporadas;
            capitulos = _capitulos;
        };
void Serie::muestraDatos(){
            Video::muestraDatos();
            cout<<"Tiene "<<temporadas<<" temporadas y "<<capitulos<<" capitulos"<<endl<<endl;
        }