//---------------------------------------------------------------------------

#pragma hdrstop
#include "Pilas.h"

Pilas::Pilas() : tope(nullptr) {}

bool Pilas::vacia() { return tope == nullptr; }

void Pilas::poner(int dato) {
    direccion x = new Nodo();
    if (!x)
        throw Exception("Memoria llena");
    x->dato = dato;
    x->sig = tope;
    tope = x;
}

void Pilas::sacar(int &dato) {
    if (vacia())
        throw Exception("Error: Pila vacía");
    dato = tope->dato;
    suprime(tope);
}

void Pilas::suprime(direccion x) {
	if (!vacia()) {
		direccion temp = x;
		tope = x->sig;
		delete temp;
	}
}

void Pilas::dibujar(TCanvas *canvas, int x, int y, int ancho_celda, int alto_celda,
					const string &mensaje, TColor color, bool con_borde) {

	TRect rect(x, y, x + ancho_celda, y + alto_celda);
	canvas->Brush->Color = color;
	canvas->FillRect(rect);
	canvas->TextOut(x + 3, y + 3, mensaje.c_str());

	if (con_borde) {
		canvas->Pen->Color = clBlack;
		canvas->MoveTo(x, y);
		canvas->LineTo(x + ancho_celda, y);
		canvas->LineTo(x + ancho_celda, y + alto_celda);
		canvas->LineTo(x, y + alto_celda);
		canvas->LineTo(x, y);
	}
}


void Pilas::mostrar(TCanvas *canvas, int x, int y) {
    const int ancho = 50;
    const int alto = 25;

	// Crear una pila auxiliar para invertir el orden
    Pilas aux;
    int contador = 0;

    // Copiar elementos a la pila auxiliar (esto los invertirá)
    direccion actual = tope;
    while (actual != nullptr) {
        aux.poner(actual->dato);
        contador++;
        actual = actual->sig;
    }

	dibujar(canvas, x, y, ancho, alto, "Usuario", clLime, true);

	y -= alto; //y_base - alto;
	while (!aux.vacia()) {
		int valor;
		aux.sacar(valor);
        string dato = to_string(valor);
		dibujar(canvas, x, y, ancho, alto, dato, (TColor)0x00A5FF, true);
        y -= alto;
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
