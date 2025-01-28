//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConjuntoP.h"

ConjuntoP::ConjuntoP(): ptrConjunto(nullptr), cantidad(0) {}

void ConjuntoP::anula() {
    while (ptrConjunto) {
        direccion temp = ptrConjunto;
        ptrConjunto = ptrConjunto->sig;
        delete temp;
    }
    cantidad = 0;
}

bool ConjuntoP::vacio() {
    return ptrConjunto == nullptr;
}

bool ConjuntoP::pertenece(int elemento) {
    for (direccion x = ptrConjunto; x; x = x->sig)
        if (x->dato == elemento)
            return true;
    return false;
}

void ConjuntoP::inserta(int elemento) {
    direccion x = new NodoC();
    if (!x)
        throw Exception("No existe espacio en la memoria");
    if (!pertenece(elemento)) {
        x->dato = elemento;
        x->sig = ptrConjunto;
        ptrConjunto = x;
        cantidad++;
    }
}

int ConjuntoP::cardinal() {
    return cantidad;
}

int ConjuntoP::ordinal(int elemento) {
    int i = 0;
    for (direccion x = ptrConjunto; x; x = x->sig) {
        i++;
        if (x->dato == elemento)
            return i;
    }
    return i;
}

void ConjuntoP::suprime(int elemento) {
    direccion act = ptrConjunto;
    direccion ant = nullptr;
    while (act && act->dato != elemento) {
        ant = act;
        act = act->sig;
    }

    if (act) {
        if (ant)
            ant->sig = act->sig;
        else
            ptrConjunto = act->sig;
        delete act;
        cantidad--;
    }
}

int ConjuntoP::muestrea() {
    if (vacio())
        throw Exception("Error: No existe ningun elemento en el conjunto");
    int lugar_buscado = rand() % cardinal() + 1;
    int lugar = 0;
    for (direccion x = ptrConjunto; x; x = x->sig) {
        lugar++;
        if (lugar == lugar_buscado)
            return x->dato;
    }
}


void ConjuntoP::unir(ConjuntoP *c1, ConjuntoP *&c2) {
    while (cardinal() > 0) {
        int ele = muestrea();
        c2->inserta(ele);
        suprime(ele);
    }

    while (c1->cardinal() > 0) {
        int ele = c1->muestrea();
        c2->inserta(ele);
        c1->suprime(ele);
    }
}

void ConjuntoP::interseccion(ConjuntoP *c1, ConjuntoP *&c2) {
	direccion x = ptrConjunto;
	while (x) {
		if (c1->pertenece(x->dato)) {
			c2->inserta(x->dato);
			suprime(x->dato);
            c1->suprime(x->dato);
        }
        x = x->sig;
    }
}

void ConjuntoP::mostrar(TCanvas *canvas, String conj, int x, int y) {
    TRect rect(x, y, 500, y + 20);
    canvas->FillRect(rect);
    canvas->Font->Size = 12;
    if (vacio())
        canvas->TextOut(x, y, conj + "{}");
    else {
        conj += "{ ";
        for (direccion k = ptrConjunto; k; k = k->sig) {
            conj += IntToStr(k->dato) + ((k->sig) ? ", " : "");
        }
        conj += " }";
        canvas->TextOut(x, y, conj);
    }
}


//---------------------------------------------------------------------------
#pragma package(smart_init)
