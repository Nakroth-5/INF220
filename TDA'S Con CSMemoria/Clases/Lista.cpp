﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Lista.h"

Lista::Lista(CSMemoria *mem): m(mem), ptrElementos(NULO), longitud(0) {}

Lista::Lista(): m(new CSMemoria()), ptrElementos(NULO), longitud(0) {}

direccion Lista::primero() {
	return ptrElementos;
}

direccion Lista::fin() {
    if (vacia())
		throw Exception("Error: lista vacia");
	int dir_fin = NULO;
	direccion x = ptrElementos;
	while (x != NULO) {
		dir_fin = x;
		x = m->obtener_dato(x, "->sig");
	}
    return dir_fin;
}

direccion Lista::anterior(direccion dir) {
    if (dir == ptrElementos)
        return NULO;

    direccion x = ptrElementos;
    while (x != NULO) {
        if (m->obtener_dato(x, "->sig") == dir)
            return x;
        x = m->obtener_dato(x, "->sig");
    }
    return NULO;
}

direccion Lista::siguiente(direccion dir) {
    if (vacia())
        throw Exception("Error: lista vacia");
    return m->obtener_dato(dir, "->sig");
}


void Lista::inserta(direccion dir, int dato) {
    int x = m->new_espacio("dato,sig");
    if (x == NULO)
        throw Exception("Error: no existe espacio en la memoria");

	m->poner_dato(x, "->dato", dato);
    m->poner_dato(x, "->sig", NULO);

	if (vacia()) {
		ptrElementos = x;
		longitud = 1;
	} else {

		if (dir == primero()) {
			m->poner_dato(x, "->sig", dir);
			ptrElementos = x;
		}else {
			direccion ant = anterior(dir);
			m->poner_dato(ant, "->sig", x);
			m->poner_dato(x, "->sig", dir);
		}

		longitud++;
	}
}


void Lista::inserta_primero(int dato) {
    int x = m->new_espacio("dato,sig");
    if (x == NULO)
        throw Exception("Error: no existe espacio en la memoria");
    m->poner_dato(x, "->dato", dato);
    m->poner_dato(x, "->sig", ptrElementos);
    ptrElementos = x;
    longitud++;
}

void Lista::inserta_final(int dato) {
	int x = m->new_espacio("dato,sig");
    if (x == NULO)
		throw Exception("Error: no existe espacio en la memoria");
    m->poner_dato(x, "->dato", dato);
    m->poner_dato(x, "->sig", -1);
    if (!vacia())
        m->poner_dato(fin(), "->sig", x);
    else
        ptrElementos = x;
    longitud++;
}

int Lista::recupera(direccion dir) {
    if (vacia())
        throw Exception("Error: lista vacia");
    return m->obtener_dato(dir, "->dato");
}

direccion Lista::localiza(int dato) {
    if (vacia())
        throw Exception("Error: lista vacia");
    for (int x = ptrElementos; x != NULO; x = m->obtener_dato(x, "->sig"))
        if (recupera(x) == dato)
            return x;
    return NULO;
}

void Lista::suprime(direccion dir) {
    if (vacia())
        throw Exception("Error: lista vacia");
    direccion borrar = ptrElementos;
    direccion ant = NULO;

    while (borrar != NULO && borrar != dir) {
        ant = borrar;
        borrar = m->obtener_dato(borrar, "->sig");
    }

    if (borrar != NULO) {
        if (ant != NULO)
            m->poner_dato(ant, "->sig", m->obtener_dato(borrar, "->sig"));
        else
            ptrElementos = m->obtener_dato(borrar, "->sig");
        m->delete_espacio(borrar);
        longitud--;
    } else
        throw Exception("Error: direccion invalida");
}

void Lista::elimina_dato(int dato) {
    if (vacia())
        throw Exception("Error: lista vacia");

    direccion borrar = ptrElementos;
    direccion ant = NULO;

    while (borrar != NULO) {
        direccion sig = m->obtener_dato(borrar, "->sig");

        if (m->obtener_dato(borrar, "->dato") == dato) {
            if (ant != NULO)
                m->poner_dato(ant, "->sig", sig);
            else
                ptrElementos = sig;
            m->delete_espacio(borrar);
            longitud--;
        } else
            ant = borrar;
        borrar = sig;
    }
}

void Lista::modifica(direccion dir, int dato) {
    if (vacia())
        throw Exception("Error: lista vacia");
    m->poner_dato(dir, "->dato", dato);
}

void Lista::anule() {
    if (vacia())
        throw Exception("Error: lista vacia");

    direccion borrar = ptrElementos;

    while (borrar != NULO) {
        direccion sig = m->obtener_dato(borrar, "->sig");
        m->delete_espacio(borrar);
        borrar = sig;
    }

    ptrElementos = NULO;
    longitud = 0;
}

bool Lista::vacia() {
    return longitud == 0;
}

void Lista::mostrar(TCanvas *canvas, int x, int y) {
	//canvas->Font->Size = 12;
		//x,    y,  b,    h
	TRect rect(x, y, 500, y + 20);
    canvas->Brush->Color = clGradientActiveCaption;
	canvas->FillRect(rect);

    if (vacia())
		canvas->TextOut(x, y, "Lista vacia");
	else {
		String listM = "<";
		int k = ptrElementos;
		while (k != -1) {
			listM += recupera(k);
			k = m->obtener_dato(k, "->sig");
			if (k != -1)
				listM += ", ";
		}
		listM += ">";
		canvas->TextOut(x, y, listM);
	}
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
