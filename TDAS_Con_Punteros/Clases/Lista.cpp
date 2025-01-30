#pragma hdrstop
#include "Lista.h"

Lista::Lista() : ptrElementos(nullptr), cantidad(0) {}

bool Lista::vacia() { return ptrElementos == nullptr; }

direccion Lista::fin() {
    if (vacia())
        throw Exception("Error: lista vacia");
    for (direccion x = ptrElementos; x; x = x->sig)
        if (!x->sig)
            return x;
    return nullptr;
}

direccion Lista::primero() {
    return ptrElementos;
}

direccion Lista::anterior(direccion dir) {
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

direccion Lista::siguiente(direccion dir) {
    return dir->sig;
}

void Lista::anule() {
    while (ptrElementos) {
        direccion temp = ptrElementos;
        ptrElementos = ptrElementos->sig;
        delete temp;
    }
    cantidad = 0;
}

void Lista::inserta_primero(int dato) {
    direccion x = new NodoP(dato);
    x->sig = ptrElementos;
    ptrElementos = x;
    cantidad++;
}

void Lista::inserta(direccion dir, int dato) {
    direccion x = new NodoP(dato);
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

void Lista::inserta_final(int dato) {
    direccion x = new NodoP(dato);
    if (!vacia())
        fin()->sig = x;
    else
        ptrElementos = x;
    cantidad++;
}

int Lista::recupera(direccion dir) {
    if (vacia())
        throw Exception("Error: lista vacia");
    return dir->dato;
}

direccion Lista::localiza(int dato) {
    if (vacia())
        throw Exception("Error: lista vacia");
    for (direccion x = ptrElementos; x; x = x->sig)
        if (x->dato == dato)
            return x;
    return nullptr;
}

void Lista::suprime(direccion dir) {
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

void Lista::elimina_dato(int dato) {
    direccion sig = nullptr;
    direccion act = ptrElementos;
    while (act) {
        sig = act->sig;
        if (act->dato == dato)
            suprime(act);
        act = sig;
    }
}

void Lista::modifica(direccion dir, int dato) {
    if (vacia())
        throw Exception("Error: lista vacia");
    dir->dato = dato;
}

void Lista::mostrar(TCanvas *canvas, int x, int y) {
    TRect rect(x, y, 500, y + 20);
    canvas->Brush->Color = clGradientActiveCaption;
    canvas->FillRect(rect);

    if (vacia())
        canvas->TextOut(x, y, "Lista vacia");
    else {
        string listP = "<";
        for (direccion x = ptrElementos; x; x = x->sig) {
            listP += to_string(recupera(x));
            if (x->sig) {
                listP += ", ";
            }
        }
        listP += ">";
        canvas->TextOut(x, y, listP.c_str());
    }
}

