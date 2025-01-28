//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConjuntoM.h"

ConjuntoM::ConjuntoM(CSMemoria *mem): m(mem), ptrConjunto(NULO), cantidad(0) {}

bool ConjuntoM::vacio() {
    return ptrConjunto == NULO;
}

bool ConjuntoM::pertenece(int elemento) {
    for (direccion x = ptrConjunto; x != NULO; x = m->obtener_dato(x, "->sig"))
        if (m->obtener_dato(x, "->dato") == elemento)
            return true;
    return false;
}

void ConjuntoM::inserta(int elemento) {
	direccion x = m->new_espacio("dato,sig");
	if (x == NULO)
		throw Exception("No existe espacio en la memoria");
	if (!pertenece(elemento)) {
		m->poner_dato(x, "->dato",elemento);
		m->poner_dato(x, "->sig", ptrConjunto);
		ptrConjunto = x;
		cantidad++;
    }
}

int ConjuntoM::cardinal() {
    return cantidad;
}

int ConjuntoM::ordinal(int elemento) {
    int i = 0;
    for (direccion x = ptrConjunto; x != NULO; x = m->obtener_dato(x, "->sig")) {
        i++;
        if (m->obtener_dato(x, "->dato") == elemento)
            return i;
    }
    return i;
}

int ConjuntoM::muestrea() {
	if (cantidad > 0) {
		int lugarBuscado = 1 + rand() % cantidad;
        int lugar = 0;
		direccion x = ptrConjunto;

		while (x != NULO) { // Recorremos la lista enlazada
			lugar++;
			if (lugar == lugarBuscado) {
				int elemento = m->obtener_dato(x, "->dato");
				x = NULO;
				return elemento;
			} else {
				x = m->obtener_dato(x, "->sig");
            }
        }
    }

    throw Exception("Error: El conjunto está vacío."); // Si el conjunto está vacío, lanzamos una excepción
}


void ConjuntoM::suprime(int elemento) {
    for (direccion x = ptrConjunto; x != NULO; x = m->obtener_dato(x, "->sig")) {
        if (m->obtener_dato(x, "->dato") == elemento) {
            m->delete_espacio(x);
            break;
        }
    }
}

void ConjuntoM::mostrar(TCanvas *canvas, String conj, int x, int y) {
    TRect rect(x, y, 500, y + 20);
    canvas->FillRect(rect);
    //canvas->Font->Size = 12;
    if (vacio())
        canvas->TextOut(x, y, conj + "{}");
    else {
        conj += "{ ";
        for (direccion k = ptrConjunto; k != NULO; k = m->obtener_dato(k, "->sig")) {
            conj += IntToStr(m->obtener_dato(k, "->dato")) + ((m->obtener_dato(k,"->sig") != NULO) ? ", " : "");
        }
        conj += " }";
        canvas->TextOut(x, y, conj);
    }
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
