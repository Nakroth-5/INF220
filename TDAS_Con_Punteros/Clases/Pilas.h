//---------------------------------------------------------------------------

#ifndef PilasH
#define PilasH
#include <string>
using namespace std;
#include <Vcl.h>

class Pilas {
private:
    struct Nodo {
        int dato;
        Nodo* sig;
    };
    typedef Nodo* direccion;
    direccion tope;
public:
    Pilas();
    void poner(int dato);
    void sacar(int &dato);
    bool vacia();
    void suprime(direccion  x);
    void dibujar(TCanvas *canvas, int x, int y,
                 int ancho_celda, int alto_celda, const string &mensaje, TColor color, bool con_borde);
    void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
