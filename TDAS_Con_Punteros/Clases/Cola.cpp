//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cola.h"
Cola::Cola(): ini(nullptr), fin(nullptr) {}

bool Cola::vacia() { return ini == nullptr; }

void Cola::poner(int dato) {
    direccion x = new Nodo();
    if (!x)
        throw runtime_error("Error: No existe espacio en la memoria");

    x->dato = dato;
    x->sig = nullptr;

    if (vacia()) {
        ini = x;
        fin = x;
    } else {
        fin->sig = x;
        fin = x;
    }
}

void Cola::sacar(int &dato) {
    if (vacia())
        return;
    dato = ini->dato;
    direccion temp = ini;
    ini = ini->sig;
	delete temp;
}

void Cola::dibujar(TCanvas *canvas, int x, int y, int ancho_celda, int alto_celda,
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

void Cola::mostrar(TCanvas *canvas, int x, int y) {

	const int ancho = 50;
    const int alto = 25;
	TRect rect(x, y - 5, x + 500, y + 25);
	canvas->Brush->Color = clGradientActiveCaption;
	canvas->FillRect(rect);

	dibujar(canvas, x, y, ancho, alto, "Usuario", clLime, true);

	x += ancho;
	for (direccion temp = ini; temp; temp = temp->sig) {
		dibujar(canvas, x, y, ancho, alto, to_string(temp->dato), clWhite, true);
		x += ancho;
    }
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
