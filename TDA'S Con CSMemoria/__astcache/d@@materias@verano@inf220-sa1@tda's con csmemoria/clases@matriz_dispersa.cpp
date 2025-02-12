﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_dispersa.h"
Matriz_dispersa::Matriz_dispersa(CSMemoria *mem): m(mem), dimf(0), dimc(0), rep(0), nt(0), ptrMatD(NULO) {}

void Matriz_dispersa::dimencionar(int df, int dc) {
    dimf = df;  dimc = dc;
}

int Matriz_dispersa::dimencion_fila() { return dimf; }

int Matriz_dispersa::dimencion_columna() { return dimc; }

bool Matriz_dispersa::direccion_valida(int f, int c) {
    if ((f > 0 && f <= dimencion_fila()) && (c > 0 && c <= dimencion_columna()))
        return true;
    return false;
}

direccion Matriz_dispersa::buscar_nodo(int f, int c) {
    if (!direccion_valida(f, c))
        throw Exception("Direcciones no validas");

    for (direccion x = ptrMatD; x != NULO; x = m->obtener_dato(x, "->sig")) {
        if (m->obtener_dato(x, "->fila") == f && m->obtener_dato(x, "->columna") == c)
            return x;
    }
    return NULO;
}

void Matriz_dispersa::poner_dato(int f, int c, int valor) {
    if (!direccion_valida(f, c))
		throw Exception("Direcciones no validas");
    direccion existe = buscar_nodo(f, c);

    if (existe != NULO) {
        m->poner_dato(existe, "->dato", valor);
        if (valor == rep) {
            eliminar_nodo(f, c);
        }
    } else {
        if (valor != rep) {
            direccion x = m->new_espacio("fila,columna,dato,sig");
            m->poner_dato(x, "->fila", f);
            m->poner_dato(x, "->columna", c);
            m->poner_dato(x, "->dato", valor);
            m->poner_dato(x, "->sig", ptrMatD);
            ptrMatD = x;
        }
    }
}

void Matriz_dispersa::eliminar_nodo(int f, int c) {
    direccion actual = ptrMatD;
    direccion anterior = NULO;

    while (actual != NULO) {
        if (m->obtener_dato(actual, "->fila") == f && m->obtener_dato(actual, "->columna") == c) {
            if (anterior == NULO)
                ptrMatD = m->obtener_dato(actual, "->sig");
            else
                m->poner_dato(anterior, "->sig", m->obtener_dato(actual, "->sig"));
            m->delete_espacio(actual);
            return;
        }
        anterior = actual;
        actual = m->obtener_dato(actual, "->sig");
    }
}

void Matriz_dispersa::elimina_dato(int valor) {
    if (ptrMatD == NULO) return;
    direccion act = ptrMatD;
    direccion sig = NULO;
    while (act != NULO) {
        sig = m->obtener_dato(act, "->sig");
        if (m->obtener_dato(act, "->dato") == valor) {
            eliminar_nodo(m->obtener_dato(act, "->fila"), m->obtener_dato(act, "->columna"));
        }
        act = sig;
    }
}

bool Matriz_dispersa::existe_valor_repetido(int valor) {
	for (direccion x = ptrMatD; x != NULO; x = m->obtener_dato(x, "->sig"))
        if (m->obtener_dato(x, "->dato") == valor)
            return true;
    return false;
}

void Matriz_dispersa::definir_valor_repetido(int valor) {
    int valor_ant = rep;
    if (valor != rep) {
		rep = valor;
		if (existe_valor_repetido(valor)) {
			for (int i = 0; i < dimencion_fila(); ++i) {
				for (int j = 0; j < dimencion_columna(); ++j) {
					direccion x = buscar_nodo(i + 1, j + 1);
					if (x == NULO)
						poner_dato(i + 1, j + 1, valor_ant);
				}
			}
			elimina_dato(rep);
		}
	}
}
void Matriz_dispersa::dibujar(TCanvas *canvas, int x, int y,
                              int ancho_celda, int alto_celda, const string &mensaje, TColor color, bool con_borde) {

    TRect rect(x, y, x + ancho_celda, y + alto_celda);
    canvas->Brush->Color = color;
    canvas->FillRect(rect);
    canvas->TextOut(x + 3, y + 3, mensaje.c_str());

    if (con_borde) {
        canvas->Pen->Color = clBlack;
        canvas->MoveTo(x, y);
        canvas->LineTo(x + ancho_celda, y);
        canvas->LineTo(x + ancho_celda, y + alto_celda);
        canvas->LineTo(x, y + alto_celda);
        canvas->LineTo(x, y);
    }
}

void Matriz_dispersa::dibujar_matriz(TCanvas *canvas, int x_inicial, int y_inicial,
                                     int ancho_celda, int alto_celda) {
    int x, y;
    for (int fila = 1; fila <= dimf; ++fila) {
        for (int columna = 1; columna <= dimc; ++columna) {
            x = x_inicial + (columna - 1) * ancho_celda;
            y = y_inicial + (fila - 1) * alto_celda;

            direccion nodo = buscar_nodo(fila, columna);
			string mensaje = (nodo != NULO) ? to_string(m->obtener_dato(nodo, "->dato")) : to_string(rep);
            TColor color = (nodo != NULO) ? clSkyBlue : clWhite;
            bool con_borde = true;

            dibujar(canvas, x, y, ancho_celda, alto_celda, mensaje, color, con_borde);
        }
    }
}



//---------------------------------------------------------------------------
#pragma package(smart_init)
