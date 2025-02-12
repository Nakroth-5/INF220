﻿//---------------------------------------------------------------------------

#ifndef ListaMH
#define ListaMH
#include "Clases/CSMemoria.h"

class ListaM {
private:
	direccion ptrElementos;
    int longitud;
    CSMemoria *m;
public:
    ListaM(CSMemoria *mem);
    direccion primero();
    direccion anterior(direccion dir);
    direccion siguiente(direccion dir);
    direccion fin();
    void inserta_primero(int dato);
    void inserta(direccion dir, int dato);
    void inserta_final(int dato);
    int recupera(direccion dir);
    direccion localiza(int dato);
    void suprime(direccion dir);
    void elimina_dato(int dato);
    void anule();
	bool vacia();
    int getLongitud() {return longitud; }
    void modifica(direccion dir, int dato);
	void mostrar(TCanvas *canvas, int x, int y);
};

//---------------------------------------------------------------------------
#endif
