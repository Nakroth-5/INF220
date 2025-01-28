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
    if (vacio())
        throw Exception("Error: No existe ningun elemento en el conjunto");
    int lugar_buscado = rand() % cardinal() + 1;
    int lugar = 0;
	for (direccion x = ptrConjunto; x != NULO; x = m->obtener_dato(x, "->sig")) {
		lugar++;
		if (lugar == lugar_buscado)
			return m->obtener_dato(x, "->dato");
	}
	return -1;
}

void ConjuntoM::unir(ConjuntoM *c1, ConjuntoM *&c2) {
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

void ConjuntoM::interseccion(ConjuntoM *c1, ConjuntoM *&c2) {
	direccion x = ptrConjunto;
	while (x != NULO) {
		if (c1->pertenece(m->obtener_dato(x, "->dato"))) {
			c2->inserta(m->obtener_dato(x, "->dato"));
			suprime(m->obtener_dato(x, "->dato"));
			c1->suprime(m->obtener_dato(x, "->dato"));
		}
		x = m->obtener_dato(x, "->sig");
	}
}

void ConjuntoM::suprime(int elemento) {
   if (!pertenece(elemento))
        return;

	direccion act = ptrConjunto;
	direccion ant = NULO; // Nodo anterior

	while (act != NULO && m->obtener_dato(act, "->dato") != elemento) {
		ant = act;
		act = m->obtener_dato(act, "->sig");
	}

	if (act != NULO) {
		if (ant != NULO) {
			m->poner_dato(ant, "->sig", m->obtener_dato(act, "->sig"));
		} else {
			ptrConjunto =  m->obtener_dato(act, "->sig");
		}
		m->delete_espacio(act);
        cantidad--;
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
