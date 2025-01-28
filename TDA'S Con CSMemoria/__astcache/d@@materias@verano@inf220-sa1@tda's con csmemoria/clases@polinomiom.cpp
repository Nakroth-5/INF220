//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioM.h"

PolinomioM::PolinomioM(CSMemoria *mem): m(mem), ptrPoli(NULO), nt(0) {}

PolinomioM::~PolinomioM() {
    while (ptrPoli != NULO) {
        direccion sig = m->obtener_dato(ptrPoli, "->sig");
        m->delete_espacio(ptrPoli);
        ptrPoli = sig;
    }
    nt = 0;
}

bool PolinomioM::es_cero() { return ptrPoli == NULO; }

int PolinomioM::grado() {
    if (es_cero())
        throw Exception("Polinomio vacío");

    int max_grado = m->obtener_dato(ptrPoli, "->exp");
    for (direccion x = ptrPoli; x != NULO; x = m->obtener_dato(x, "->sig")) {
        int exp = m->obtener_dato(x, "->exp");
        if (exp > max_grado)
            max_grado = exp;
    }
    return max_grado;
}


direccion PolinomioM::buscar_exponente(int exp) {
    for (direccion x = ptrPoli; x != NULO; x = m->obtener_dato(x, "->sig"))
        if (m->obtener_dato(x, "->exp") == exp)
            return x;
    return NULO;
}

direccion PolinomioM::buscar_termino(int i) {
    if (es_cero())
        throw Exception("Polinomio vacio");
    int j = 0 ;
    for (direccion x = ptrPoli; x != NULO; x = m->obtener_dato(x, "->sig")) {
        j++;
        if (j == i)
            return x;
    }
    return NULO;
}

int PolinomioM::coeficiente(int exp) {
    if (es_cero())
        throw Exception("Polinomio vacio");
    direccion dir = buscar_exponente(exp);
    if (exp != NULO)
        return m->obtener_dato(dir, "->coef");
    throw Exception("Error: No existe termino con ese exponente");
}

int PolinomioM::exponente(int ntr) {
    direccion x = buscar_termino(ntr);
    if (x != NULO)
        return m->obtener_dato(x, "->exp");
    throw Exception("");
}

void PolinomioM::asignar_coef(int coef, int exp) {//modificar coef
    if (es_cero())
        throw Exception("Polinomio vacio");
    direccion x = buscar_exponente(exp);
    if (exp != NULO) {
        m->poner_dato(x, "->coef", coef);
        if (m->obtener_dato(x, "->coef") == 0)
            suprime(exp);
    } else
        throw Exception("Error: No existe termino con ese exponente");
}

void PolinomioM::poner_termino(int coef, int exp) {
    if (buscar_exponente(exp) == NULO) {
        direccion x = m->new_espacio("coef,exp,sig");
        if (x != NULO) {
            m->poner_dato(x, "->coef", coef);
            m->poner_dato(x, "->exp", exp);
            m->poner_dato(x, "->sig", ptrPoli);
            ptrPoli = x;
            nt++;
        }
    } else
        asignar_coef(coeficiente(exp) + coef, exp);
}

void PolinomioM::suprime(int exp) {
    direccion act = ptrPoli;
    direccion ant = NULO;
    while (act != NULO && m->obtener_dato(act, "->exp") != exp) {
        ant = act;
        act = m->obtener_dato(act, "->sig");
    }

    if (act != NULO) {
        if (ant == NULO)
            ptrPoli = m->obtener_dato(act, "->sig");
        else
            m->poner_dato(ant, "->sig", m->obtener_dato(act, "->sig"));
        nt--;
        m->delete_espacio(act);
    }
}

void PolinomioM::operacion(PolinomioM *p1, PolinomioM *p2, int signo) {
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

void PolinomioM::suma(PolinomioM *p1, PolinomioM *p2) {
    operacion(p1, p2, 1);
}

void PolinomioM::resta(PolinomioM *p1, PolinomioM *p2) {
    operacion(p1, p2, -1);
}


void PolinomioM::multiplicar(PolinomioM *p1, PolinomioM *p2) {
    for (int i = 0; i < p1->numero_terminos(); ++i) {
        int exp = p1->exponente(i + 1);
        int coef = p1->coeficiente(exp);
		for (int j = 0; j < p2->numero_terminos(); j++) {
			int expj = p2->exponente(j + 1);
			int coefj = p2->coeficiente(expj);
            poner_termino(coef * coefj, exp + expj);
		}
	}
}

double PolinomioM::evaluar(double x) {
    double resultado = 0;
    for (direccion i = ptrPoli; i != NULO; i = m->obtener_dato(i, "->sig"))
        resultado += m->obtener_dato(i, "->coef") * pow(x, m->obtener_dato(i, "->exp"));
    return resultado;
}

void PolinomioM::derivar(PolinomioM *p1) {
	direccion x = p1->ptrPoli;
    direccion sig = NULO;
    while (x != NULO) {
        int coef = m->obtener_dato(x, "->coef");
        int exp = m->obtener_dato(x, "->exp");
        if (exp - 1 == -1)
			poner_termino(0, exp - 1);
		else
            poner_termino(coef * exp, exp - 1);
        x = m->obtener_dato(x, "->sig");
    }
}

void PolinomioM::mostrar(TCanvas *canvas, int x, int y) {
    TRect rect(x, y, 500, y + 20);
    canvas->Pen->Color = clBlack;
    canvas->FillRect(rect);
    if (es_cero())
        canvas->TextOut(x, y, "P(X) = 0");
    String poli = "P(X) = ";
    for (direccion x = ptrPoli; x != NULO; x = m->obtener_dato(x, "->sig")) {
        int dato = (m->obtener_dato(x, "->coef"));
        if (m->obtener_dato(x, "->exp") == 0) {
            poli += dato > 0? "+" + IntToStr(dato) :"" + IntToStr(dato);
        } else if (dato > 0)
            poli += "+" + IntToStr(dato) + "X^" + IntToStr(m->obtener_dato(x, "->exp"));
        else
            poli += IntToStr(dato) + "X^" + IntToStr(m->obtener_dato(x, "->exp"));
    }
    canvas->TextOut(x, y, poli);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
