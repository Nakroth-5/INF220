//---------------------------------------------------------------------------

#ifndef PilasLH
#define PilasLH
#include "Lista.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <Vcl.h>
using namespace std;

class PilasL {
private:
    Lista* lista;
public:
	PilasL(CSMemoria* mem);
    PilasL();
    void poner(double dato);
    void sacar(double &dato);
    bool vacia();
    void suprime(direccion  x);
    string prefija_a_posfija(string infija);
    double evaluar_posfija(string posfija);
    void dibujar(TCanvas *canvas, int x, int y,
                 int ancho_celda, int alto_celda, const string &mensaje, TColor color, bool con_borde);
    void mostrar(TCanvas *canvas, int x, int y);
};

//---------------------------------------------------------------------------
#endif
