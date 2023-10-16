
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
};
// Definiciones......................
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
//..........................
class Pelicula:public Video{
    public:
        Pelicula(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _nominaciones, int _calificacion):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion, _calificacion){
            nominaciones = _nominaciones;
        };
        Pelicula(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _nominaciones):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion){
            nominaciones = _nominaciones;
        };
        void muestraDatos(){
            Video::muestraDatos();
            if(nominaciones>0){
                cout<<"La pelicula tiene "<<nominaciones<<" nominacion(es)"<<endl<<endl;
            }
            else{
                cout<<"La pelicula no tiene nominaciones"<<endl<<endl;
            };
        };
           
    private:
        int nominaciones=0;
};
//.................
class Serie:public Video{
    public:
        Serie(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion, int _temporadas, int _capitulos, int _calificacion):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion, _calificacion){
            temporadas = _temporadas;
            capitulos = _capitulos;
        };
        Serie(string _tipovideo, string _nombrevideo, string _genero, int _aniolanzamiento, int _duracion,  int _temporadas, int _capitulos):Video(_tipovideo, _nombrevideo, _genero, _aniolanzamiento, _duracion){
            temporadas = _temporadas;
            capitulos = _capitulos;
        };
        void muestraDatos(){
            Video::muestraDatos();
            cout<<"Tiene "<<temporadas<<" temporadas y "<<capitulos<<" capitulos"<<endl<<endl;
        }
    private:
        int temporadas, capitulos;
};
//..................Funciones que utilizare........................
string Opcion3(){
    string opcion;
    while (cin>>opcion){
        if(opcion=="1" || opcion=="2" || opcion =="3"){
            break;
        }
        cout<<"Esa no es una opcion, intente de muevo"<<endl;
    };
    return opcion;
};
string Opcion2(){
    string opcion;
    while (cin>>opcion){
        if(opcion=="1" || opcion=="2"){
            break;
        }
        cout<<"Esa no es una opcion, intente de muevo"<<endl;
    };
    cout<<endl;
    return opcion;
};

int CambiaCal(){
    cout<<"Introduce la calificacion: "<<endl;
    int cal; cin>>cal;
    return cal;
    cout<<endl;
    };
//...........................MAIN...................................
int main(){
    Video MiVideo1("cortometraje","El oso","Fabula",2015,9);
    Video MiVideo2("Gameplay","Ori and the Blind forest speedrun","speedrun",2019,23,10);
    Pelicula MiPelicula1("Pelicula","Shawshank Redemption","Drama",1994,142,4,10);
    Pelicula MiPelicula2("Pelicula","Silence of the Lambs","Suspenso",1991,118, 9, 10);
    Serie MiSerie1("Serie","Stranger Things","Suspenso/Horror",2018,800,4,40);
    Serie MiSerie2("Serie","Grey's Anatomy","Drama",2004,800000,16,800000,3);
    Serie MiSerie3("Serie","Attack On Titan","Accion",2014,900,4,90,10);
    string opcion_categoria;
    string op="s";
    int cal;
    while(op=="s"){
        cout<<"Videos misc (1)"<<endl<<endl;
        cout<<"Series (2)"<<endl<<endl;
        cout<<"Peliculas (3)"<<endl<<endl;
        opcion_categoria=Opcion3();
        string opcion_menu;
        if(opcion_categoria=="1"){
            cout<<"Consultar videos (1)"<<endl<<endl;
            cout<<"Calificar videos (2)"<<endl<<endl;
            opcion_menu=Opcion2();
            if(opcion_menu=="1"){
                MiVideo1.muestraDatos();
                MiVideo2.muestraDatos();
            }
            else{
                string cual_cambiar;
                cout<<"Cambiar MiVideo1 (1) o MiVideo2 (2)?"<<endl;
                cual_cambiar=Opcion2();
                cal=CambiaCal();
                if(cual_cambiar=="1"){
                    MiVideo1.calificaVideo(cal);
                }
                else{
                    MiVideo2.calificaVideo(cal);
                }
            }
        }
        else if(opcion_categoria=="2"){
            cout<<"Consultar series (1)"<<endl<<endl;
            cout<<"Calificar series (2)"<<endl<<endl;
            opcion_menu=Opcion2();
            if(opcion_menu=="1"){
                MiSerie1.muestraDatos();
                MiSerie2.muestraDatos();
                MiSerie3.muestraDatos();
            }
            else{
                string cual_cambiar;
                cout<<"Cambiar MiSerie1 (1), MiSerie2 (2) o MiSerie3 (3)?"<<endl;
                cual_cambiar=Opcion3();
                cal=CambiaCal();
                if(cual_cambiar=="1"){
                    MiSerie1.calificaVideo(cal);
                }
                else if(cual_cambiar=="2"){
                    MiSerie2.calificaVideo(cal);
                }
                else{
                    MiSerie3.calificaVideo(cal);
                }
            }
        }
        else if(opcion_categoria=="3"){
            cout<<"Consultar peliculas (1)"<<endl<<endl;
            cout<<"Calificar peliculas (2)"<<endl<<endl;
            opcion_menu=Opcion2();
            if(opcion_menu=="1"){
                MiPelicula1.muestraDatos();
                MiPelicula2.muestraDatos();
            }
            else{
                string cual_cambiar;
                cout<<"Cambiar MiPelicula1 (1) o MiPelicula2 (2)?"<<endl;
                cual_cambiar=Opcion2();
                cal=CambiaCal();
                if(cual_cambiar=="1"){
                    MiPelicula1.calificaVideo(cal);
                }
                else{
                    MiPelicula2.calificaVideo(cal);
                }
            }
        }
       cout<<"Deseas continuar? (s/n)"<<endl;
       cin>>op;
    };
}