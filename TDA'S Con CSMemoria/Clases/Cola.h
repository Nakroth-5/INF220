//---------------------------------------------------------------------------

#ifndef ColaH
#define ColaH
#include <vcl.h>
#include "CSMemoria.h"
using namespace  std;

class Cola
{
private:
	direccion ini, fin;
	CSMemoria* m;
public:
	Cola(CSMemoria* mem);
    bool vacia();
    void poner(int dato);
	void sacar(int &dato);
    void dibujar(TCanvas *canvas, int x, int y,
				 int ancho_celda, int alto_celda, const string &mensaje, TColor color, bool con_borde);
	void mostrar(TCanvas* canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif

