//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioL.h"

PolinomioL::PolinomioL(): pol(new Lista()) {}

PolinomioL::~PolinomioL() {

}

bool PolinomioL::es_cero() { return pol->vacia(); }

direccion PolinomioL::buscar_termino(int i) {
    if (es_cero())
		return nullptr;
    direccion x = pol->primero();
    int j = 0;
	while (x) {
        j++;
        if (j == i)
            return x;
        x = pol->siguiente(pol->siguiente(x));
    }
	return nullptr;
}

direccion PolinomioL::buscar_exponente(int exp) {
    if (es_cero())
		return nullptr;
    direccion x = pol->siguiente(pol->primero());
	while (x) {
        if (pol->recupera(x) == exp)
            return x;
		x = pol->siguiente(pol->siguiente(x));
    }
	return nullptr;
}

int PolinomioL::grado() {
    if (es_cero())
		return 0;
	direccion x = pol->siguiente(pol->primero());
    int max_exp = pol->recupera(x);
    x = pol->siguiente(pol->siguiente(x));
	while (x) {
        if (pol->recupera(x) > max_exp)
            max_exp = pol->recupera(x);
        x = pol->siguiente(pol->siguiente(x));
    }
    return max_exp;
}

int PolinomioL::coeficiente(int exp) {
    if (es_cero())
        throw Exception("Polinomio vacio");
    direccion x = buscar_exponente(exp);
	if (x)
        return pol->recupera(pol->anterior(x));
    throw Exception("Error: No exister termino");
}

void PolinomioL::asignar_coef(int coef, int exp) {
    direccion x = buscar_exponente(exp);
	if (x) {
        pol->modifica(pol->anterior(x), coef);
        if (pol->recupera(pol->anterior(x)) == 0) {
            pol->suprime(pol->anterior(x));
            pol->suprime(x);
        }
    } else
        throw "No existe t�rmino con ese exponente";
}

void PolinomioL::poner_termino(int coef, int exp) {
	direccion x = buscar_exponente(exp);
	if (!x && coef != 0) {
		pol->inserta_primero(exp);
		pol->inserta_primero(coef);
    } else {
		asignar_coef(pol->recupera(pol->anterior(x)) + coef, exp);
	}
}

int PolinomioL::exponente(int ntr) {
    direccion x = buscar_termino(ntr);
	if (x)
        return pol->recupera(pol->siguiente(x));
    throw "No existe ese exponente";
}

void PolinomioL::suprime(int exp) {
    asignar_coef(0, exp);
}

void PolinomioL::anula() {
    pol->anule();
}

double PolinomioL::evaluar(double x) {
    direccion k = pol->primero();
	double y = 0;
    while (k) {
        y += pol->recupera(k) * pow(x, pol->recupera(pol->siguiente(k)));
        k = pol->siguiente(pol->siguiente(k));
    }
    return y;
}

void PolinomioL::mostrar(TCanvas *canvas, int x, int y) {
    pol->mostrar(canvas, x, y);
}

void PolinomioL::operacion(PolinomioL *p1, PolinomioL *p2, int signo) {
    for (int i = 0; i < p1->numero_terminos(); ++i) {
        int exp = p1->exponente(i + 1);
        int coef = p1->coeficiente(exp);
        poner_termino(coef, exp);
    }

    for (int i = 0; i < p2->numero_terminos(); ++i) {
        int exp = p2->exponente(i + 1);
        int coef = p2->coeficiente(exp);
        poner_termino(coef * signo, exp);
    }
}

void PolinomioL::suma(PolinomioL *p1, PolinomioL *p2) {
    operacion(p1, p2, 1);
}

void PolinomioL::resta(PolinomioL *p1, PolinomioL *p2) {
    operacion(p1, p2, -1);
}

void PolinomioL::multiplicar(PolinomioL *p1, PolinomioL *p2) {
    for (int i = 1; i <= p1->numero_terminos(); ++i) {
        int expo = p1->exponente(i);
        int coefi = p1->coeficiente(expo);
        for (int j = 1; j <= p2->numero_terminos(); ++j ) {
            int exp = p2->exponente(i);
            int coef = p2->coeficiente(exp);
            poner_termino(coef * coefi, exp + expo);
        }
    }
}

//derivar en el mismo polinomio
void PolinomioL::derivar() {
    direccion x = pol->primero();
    while (x) {
        int coef = pol->recupera(x);
        int exp = pol->recupera(pol->siguiente(x));
        if (exp - 1 == -1) {
            pol->suprime(x);
            pol->suprime(pol->siguiente(x));
        } else {
            pol->modifica(x, coef * exp);
            pol->modifica(pol->siguiente(x), exp - 1);
		}
		if (es_cero())
			x = nullptr;
		else
        	x = pol->siguiente(pol->siguiente(x));
    }
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
