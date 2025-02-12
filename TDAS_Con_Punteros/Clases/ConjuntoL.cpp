//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConjuntoL.h"

ConjuntoL::ConjuntoL(): lista(new Lista()) {}

bool ConjuntoL::vacio() {
    return lista->vacia();
}

bool ConjuntoL::pertenece(int elemento) {
	for (direccion x = lista->primero(); x; x = lista->siguiente(x))
        if (lista->recupera(x) == elemento)
            return true;
    return false;
}

void ConjuntoL::inserta(int elemento) {
    if (!pertenece(elemento)) {
        lista->inserta(lista->primero(),elemento);
    }
}

int ConjuntoL::cardinal() {
    return lista->getLongitud();
}

int ConjuntoL::ordinal(int elemento) {
    int pos = 0;
    for (direccion x = lista->primero(); x; x = lista->siguiente(x)) {
        pos++;
        if (lista->recupera(x) == elemento)
            return pos;
    }
    return -1;
}

int ConjuntoL::muestrea() {
    if (vacio())
        throw Exception("Error: No existe ningun elemento en el conjunto");
	int lugar_buscado = rand() % cardinal() + 1;
    int lugar = 0;
    for (direccion x = lista->primero(); x; x = lista->siguiente(x)) {
        lugar++;
        if (lugar == lugar_buscado)
            return lista->recupera(x);
    }
    return -1;
}

void ConjuntoL::suprime(int elemento) {
    for (direccion x = lista->primero(); x; x = x->sig)
        if (lista->recupera(x) == elemento) {
            lista->suprime(x);
            break;
        }
}

void ConjuntoL::anula() {
    lista->anule();
}

void ConjuntoL::unir(ConjuntoL *c1, ConjuntoL *&c2) {
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

void ConjuntoL::interseccion(ConjuntoL *c1, ConjuntoL *&c2) {
    direccion x = lista->primero();
    while (x) {
        int ele = lista->recupera(x);
        if (c1->pertenece(ele)) {
            c2->inserta(ele);
            suprime(ele);
            c1->suprime(ele);
        }
        x = lista->siguiente(x);
    }
}

void ConjuntoL::mostrar(TCanvas *canvas, String conj,int x, int y) {
    lista->mostrar(canvas, x, y);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

