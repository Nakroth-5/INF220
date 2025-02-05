//---------------------------------------------------------------------------

#pragma hdrstop

#include "Cola.h"
Cola::Cola(CSMemoria* mem): m(mem), ini(NULO), fin(NULO) {}

bool Cola::vacia() { return ini == NULO; }

void Cola::poner(int dato) {
	direccion x = m->new_espacio("dato,sig");
	if (x == NULO)
        throw runtime_error("Error: No existe espacio en la memoria");

	m->poner_dato(x, "->dato", dato);
	m->poner_dato(x, "->sig", NULO);

	if (vacia()) {
		ini = x;
		fin = x;
	} else {
		m->poner_dato(fin, "->sig", x);
		fin = x;
    }
}

void Cola::sacar(int &dato) {
    if (vacia())
        return;
	dato = m->obtener_dato(ini, "->dato");
	direccion temp = ini;
	ini = m->obtener_dato(ini, "->sig");
	m->delete_espacio(temp);
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
	for (direccion temp = ini; temp != NULO; temp = m->obtener_dato(temp, "->sig")) {
		dibujar(canvas, x, y, ancho, alto, to_string(m->obtener_dato(temp, "->dato")), clWhite, true);
		x += ancho;
	}
}


//---------------------------------------------------------------------------
#pragma package(smart_init)


