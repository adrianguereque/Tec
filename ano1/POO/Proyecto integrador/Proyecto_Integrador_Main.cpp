#include "Proyecto_Integrador.h"
#include <iostream>
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
string Opcion2s_n(){
    string opcion;
    while (cin>>opcion){
        if(opcion=="s" || opcion=="n"){
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
        cout<<"Videos miscellaneos (1)"<<endl<<endl;
        cout<<"Series (2)"<<endl<<endl;
        cout<<"Peliculas (3)"<<endl<<endl;
        opcion_categoria=Opcion3();
        string opcion_menu;
        if(opcion_categoria=="1"){
            cout<<"Consultar videos (1)"<<endl<<endl;
            cout<<"Calificar videos (2)"<<endl<<endl;
            opcion_menu=Opcion2();
            if(opcion_menu=="1"){
                cout<<"Filtrar por calificacion? (s/n)"<<endl;
                string opcion_filtro=Opcion2s_n();
                if(opcion_filtro=="s"){
                    int calFiltro; cout<<"Introduce la calificacion: "; cin>>calFiltro;
                    cout<<"Los videos miscellaneos con esa calificacion o mayor son: "<<endl;
                    MiVideo1.muestraFiltroCalificacion(calFiltro);
                    MiVideo2.muestraFiltroCalificacion(calFiltro);
                }
                else{
                    MiVideo1.muestraDatos();
                    MiVideo2.muestraDatos();
                }
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
                cout<<"Filtrar por calificacion? (s/n)"<<endl;
                string opcion_filtro=Opcion2s_n();
                if(opcion_filtro=="s"){
                    int calFiltro; cout<<"Introduce la calificacion: "; cin>>calFiltro;
                    cout<<"Las series con esa calificacion o mayor son: "<<endl;
                    MiSerie1.muestraFiltroCalificacion(calFiltro);
                    MiSerie2.muestraFiltroCalificacion(calFiltro);
                    MiSerie3.muestraFiltroCalificacion(calFiltro);
                }
                else{
                    MiSerie1.muestraDatos();
                    MiSerie2.muestraDatos();
                    MiSerie3.muestraDatos();
                }
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
                cout<<"Filtrar por calificacion? (s/n)"<<endl;
                string opcion_filtro=Opcion2s_n();
                if(opcion_filtro=="s"){
                    int calFiltro; cout<<"Introduce la calificacion: "; cin>>calFiltro;
                    cout<<"Las peliculas con esa calificacion o mayor son: "<<endl;
                    MiPelicula1.muestraFiltroCalificacion(calFiltro);
                    MiPelicula2.muestraFiltroCalificacion(calFiltro);
                }
                else{
                    MiPelicula1.muestraDatos();
                    MiPelicula2.muestraDatos();
                }
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