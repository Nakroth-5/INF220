//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaP.h"


ListaP::ListaP(): ptrElementos(nullptr), cantidad(0) {}

bool ListaP::vacia() { return ptrElementos == nullptr; }

ListaP::direccion ListaP::fin() {
	if (vacia())
		throw 	Exception("Error: lista vacia");
    for (direccion x = ptrElementos; x; x = x->sig)
        if (!x->sig)
            return x;
    return nullptr;
}

ListaP::direccion ListaP::primero() {
	return ptrElementos;
}

ListaP::direccion ListaP::anterior(direccion dir) {
    if (vacia())
		throw Exception("Error: lista vacia");
    direccion ant = nullptr;
    for (direccion x = ptrElementos; x; x = x->sig) {
        if (x == dir)
            return ant;
        ant = x;
    }
    return nullptr;
}

ListaP::direccion ListaP::siguiente(direccion dir) {
    if (vacia())
		throw Exception("Error: lista vacia");
    if (dir == fin())
		throw Exception("Error: la direccion es la final");
    return dir->sig;
}

void ListaP::anule() {
    while (ptrElementos) {
        direccion temp = ptrElementos;
        ptrElementos = ptrElementos->sig;
        delete temp;
    }
    cantidad = 0;
}

void ListaP::inserta_primero(int dato) {
	direccion x = new NodoP(dato);
	x->sig = ptrElementos;
	ptrElementos = x;
    cantidad++;
}

void ListaP::inserta(direccion dir, int dato) {
    direccion x = new NodoP(dato);//sig = null
	if (vacia()) {
        ptrElementos = x;
        cantidad = 1;
    } else {
		if (dir == ptrElementos) {
            x->sig = dir;
            ptrElementos = x;
        } else {
            direccion ant = anterior(dir);
			ant->sig = x;
            x->sig = dir;
        }
        cantidad++;
    }
}

void ListaP::inserta_final(int dato) {
    direccion x = new NodoP(dato);
    if (!vacia())
        fin()->sig = x;
    else
        ptrElementos = x;
    cantidad++;
}

int ListaP::recupera(direccion dir) {
    if (vacia())
		throw Exception("Error: lista vacia");
    return dir->dato;
}

ListaP::direccion ListaP::localiza(int dato) {
    if (vacia())
		throw Exception("Error: lista vacia");
    for (direccion x = ptrElementos; x; x = x->sig)
        if (x->dato == dato)
            return x;
    return nullptr;
}

void ListaP::suprime(direccion dir) {
    direccion act = ptrElementos;
    direccion ant = nullptr;

    while (act && act != dir) {
        ant = act;
        act = act->sig;
    }

    if (act) {
        if (ant)
            ant->sig = act->sig;
        else
            ptrElementos = act->sig;
        delete act;
        cantidad--;
    }
}

void ListaP::elimina_dato(int dato) {
    direccion sig = nullptr;
    direccion act = ptrElementos;
    while (act) {
        sig = act->sig;
        if (act->dato == dato)
            suprime(act);
        act = sig;
    }
}

void ListaP::modifica(direccion dir, int dato) {
    if (vacia())
        throw Exception("Error: lista vacia");
    dir->dato = dato;
}

void ListaP::mostrar(TCanvas *canvas, int x, int y) {

	canvas->Font->Size = 12;
		//x,    y,  b,    h
	TRect rect(x, y, 500, y + 20);
    canvas->Brush->Color = clGradientActiveCaption;
	canvas->FillRect(rect);

	if (vacia())
		canvas->TextOut(x, y, "Lista vacia");
	else {
		string listP = "<";
		for (ListaP::direccion x = ptrElementos; x; x = x->sig) {
			listP += to_string(recupera(x));
			if (x->sig) {
                listP += ", ";
			}
		}
		listP += ">";
		canvas->TextOut(x, y, listP.c_str());
	}
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
