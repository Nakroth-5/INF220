//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioP.h"

PolinomioP::PolinomioP(): ptrPoli(nullptr), nt(0) {}

PolinomioP::~PolinomioP() {
    while (ptrPoli) {
        direccion temp = ptrPoli;
        ptrPoli = ptrPoli->sig;
        delete temp;
    }
    nt = 0;
}

bool PolinomioP::es_cero() { return ptrPoli == nullptr; }

int PolinomioP::grado() {
    if (es_cero())
        throw Exception("Polinomio vacio");
    int max_grado = ptrPoli->exp;
    for (direccion x = ptrPoli; x; x = x->sig) {
        if (x->exp > max_grado)
            max_grado = x->exp;
    }
    return max_grado;
}

PolinomioP::direccion PolinomioP::buscar_exponente(int exp) {
    for (direccion x = ptrPoli; x; x = x->sig)
        if (x->exp == exp)
            return x;
    return nullptr;
}

PolinomioP::direccion PolinomioP::buscar_termino(int i) {
    if (es_cero())
        throw Exception("Polinomio vacio");
    int j = 0;
    for (direccion x = ptrPoli; x; x = x->sig) {
        j++;
        if (j == i)
            return x;
    }
    return nullptr;
}

int PolinomioP::coeficiente(int exp) {
    if (es_cero())
        throw Exception("Polinomio vacio");
    direccion dir = buscar_exponente(exp);
    if (exp)
        return dir->coef;
    throw Exception("Error: No existe termino con ese exponente");
}

void PolinomioP::asignar_coef(int coef, int exp) {//modificar coef
    if (es_cero())
        throw Exception("Polinomio vacio");
    direccion x = buscar_exponente(exp);
    if (exp) {
        x->coef = coef;
        if (x->coef == 0)
            suprime(exp);
    } else
        throw Exception("Error: No existe termino con ese exponente");
}

void PolinomioP::poner_termino(int coef, int exp) {
    if (coef == 0)
        return;
    if (!buscar_exponente(exp)) {
        direccion x = new NodoPol(coef, exp);
        if (x) {
            x->sig = ptrPoli;
            ptrPoli = x;
            nt++;
        }
    } else
        asignar_coef(coeficiente(exp) + coef, exp);
}

void PolinomioP::suprime(int exp) {
    direccion act = ptrPoli;
    direccion ant = nullptr;
    while (act && act->exp != exp) {
        ant = act;
        act = act->sig;
    }

    if (act) {
        if (!ant)
            ptrPoli = act->sig;
        else
            ant->sig = act->sig;
        nt--;
        delete act;
    }
}

void PolinomioP::suma(PolinomioP *p1, PolinomioP *p2) {
    for (direccion x = p1->ptrPoli; x; x = x->sig)
        poner_termino(x->coef, x->exp);
    for (direccion x = p2->ptrPoli; x; x = x->sig)
        poner_termino(x->coef, x->exp);
}

void PolinomioP::resta(PolinomioP *p1, PolinomioP *p2) {
    for (direccion x = p1->ptrPoli; x; x = x->sig)
        poner_termino(x->coef, x->exp);
    for (direccion x = p2->ptrPoli; x; x = x->sig)
        poner_termino(-x->coef, x->exp);
}

void PolinomioP::multiplicar(PolinomioP *p1, PolinomioP *p2) {
    for (direccion x = p1->ptrPoli; x; x = x->sig) {
        for (direccion y = p2->ptrPoli; y; y = y->sig)
            poner_termino(y->coef * x->coef, y->exp + x->exp);
    }
}

double PolinomioP::evaluar(double x) {
    double y = 0;
    for (direccion p = ptrPoli; p; p = p->sig)
        y += p->coef * std::pow(x, p->exp);
    return y;
}

void PolinomioP::derivar(PolinomioP *p1) {
	for (direccion x = p1->ptrPoli; x; x = x->sig) {
		int coef = x->coef;
		int exp = x->exp;
		if (x->exp-- == -1)
			poner_termino(0, 0);
		else
			poner_termino(coef * exp, x->exp--);
	}
}


void PolinomioP::mostrar(TCanvas *canvas, int x, int y) {
	canvas->Font->Size = 12;
	TRect rect(x, y, 500, y + 20);
	canvas->Pen->Color = clBlack;
    canvas->FillRect(rect);
    if (es_cero())
		canvas->TextOut(x, y, "P(X) = 0");
    String poli = "P(X) = ";
    for (direccion x = ptrPoli; x; x = x->sig) {
		if (x->exp == 0) {
			poli += (x->coef) > 0? "+" + IntToStr(x->coef) :"" + IntToStr(x->coef);
		} else if (x->coef > 0)
			poli += "+" + IntToStr(x->coef) + "X^" + IntToStr(x->exp);
		else
			poli += IntToStr(x->coef) + "X^" + IntToStr(x->exp);
    }
	canvas->TextOut(x, y, poli);
}

//---------------------------------------------------------------------------
#pragma package(smart_init)


