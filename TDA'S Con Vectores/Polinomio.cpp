//---------------------------------------------------------------------------

#pragma hdrstop

#include "Polinomio.h"


Polinomio::Polinomio() {
	 vec = new NodoP[max];
	 nt = 0;
}

direccion Polinomio::buscar_exponente(int exp) {
    for (int i = 0; i < nt; ++i) {
        if (vec[i].exp == exp)
            return i;
    }
    return -1;
}

direccion Polinomio::buscar_termino(int i) {
    int pos = -1;
    for (int j = 0; j < nt; ++j) {
        pos++;
        if (i == pos)
            return j;
    }
    return -1;
}

bool Polinomio::es_cero() { return nt == 0; }

int Polinomio::grado() {
	int max_exp = vec[0].exp;
    for (int i = 1; i < nt; ++i) {
        if (vec[i].exp > max_exp)
            max_exp = vec[i].exp;
    }
    return max_exp;
}

int Polinomio::coeficiente(int exp) {
    int x = buscar_exponente(exp);
    if (x != -1)
        return vec[x].coef;
    throw Exception("No existe ese termino");
}

int Polinomio::exponente(int ntr) {
    direccion x = buscar_termino(ntr);
    if (x != -1)
        return vec[x].exp;
    throw Exception("No existe ese termino");
}

void Polinomio::asignar_coef(int coef, int exp) {
    direccion x = buscar_exponente(exp);
    if (x != -1) {
        vec[x].coef = coef;
        vec[x].exp = exp;
        if (vec[x].coef == 0)
            suprime(vec[x].exp);
    }
}

void Polinomio::poner_termino(int coef, int exp) {
    direccion x = buscar_exponente(exp);
    if (x == -1) {
        vec[nt].coef = coef;
        vec[nt].exp = exp;
        nt++;
    } else {
        asignar_coef(vec[x].coef + coef, exp);
    }
}

void Polinomio::suprime(int exp) {
    direccion x = buscar_exponente(exp);
    if (x != -1) {
        for (int i = x; i < nt - 1; ++i) {
            vec[i].coef = vec[i + 1].coef;
            vec[i].exp = vec[i + 1].exp;
        }
        nt--;
    }
}

void Polinomio::mostrar(TCanvas *canvas, int x, int y) {
    TRect rect(x, y, 500, y + 20);
    canvas->FillRect(rect);
    if (es_cero())
        canvas->TextOut(x, y, "P(X) = 0");
    else {
        String pol = "P(X) = ";
        for (int i = 0; i < nt; ++i) {
            int coef = vec[i].coef;
            int exp = vec[i].exp;
            if (exp == 0)
                pol += coef > 0 ? "+" + IntToStr(coef): IntToStr(coef);
            else if (coef > 0)
                pol += "+" + IntToStr(coef) + "x^" + IntToStr(exp);
            else
                pol += IntToStr(coef) + "x^" + IntToStr(exp);
		}
        canvas->TextOut(x, y, pol);
    }
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
