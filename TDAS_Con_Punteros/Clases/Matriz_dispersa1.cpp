//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_dispersa1.h"
Matriz_dispersa1::Matriz_dispersa1(): dimf(0), dimc(0), rep(0), ptrMatD(nullptr) {}

void Matriz_dispersa1::dimencionar(int df, int dc) {
    dimf = df;  dimc = dc;
}

int Matriz_dispersa1::dimencion_fila() { return dimf; }

int Matriz_dispersa1::dimencion_columna() { return dimc; }

bool Matriz_dispersa1::direccion_valida(int f, int c) {
    if ((f > 0 && f <= dimencion_fila()) && (c > 0 && c <= dimencion_columna()))
        return true;
    return false;
}

Matriz_dispersa1::direccion Matriz_dispersa1::buscar_nodo(int f, int c) {
    if (!direccion_valida(f, c))
        throw Exception("Direcciones no validas");
    for (direccion x = ptrMatD; x; x = x->sig) {
        if (x->fila == f && x->columna == c)
            return x;
    }
    return nullptr;
}


void Matriz_dispersa1::poner_dato(int f, int c, int valor) {
    if (!direccion_valida(f, c))
        throw Exception("Direcciones no validas");

    direccion existe = buscar_nodo(f, c);
    if (existe != nullptr) {
        existe->dato = valor;
        if (valor == rep)
            eliminar_nodo(f, c);
    } else {
        if (valor != rep) {
            direccion x = new Nodo();
            x->fila = f;
            x->columna = c;
            x->dato = valor;
            x->sig = ptrMatD;
            ptrMatD = x;
        }
    }
}
/*
void Matriz_dispersa1::eliminar_nodo(int f, int c) {
    direccion actual = ptrMatD;
    direccion anterior = nullptr;

    while (actual) {
        if (actual->fila == f && actual->columna == c) {
            if (!anterior)
                ptrMatD = actual->sig;
            else
                anterior->sig = actual->sig;
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->sig;
    }
}*/

void Matriz_dispersa1::eliminar_nodo(int f, int c) {
    direccion act = ptrMatD;
    direccion ant = nullptr;
    while (act && !(act->columna == c && act->fila == f)) {
        ant = act;
        act = act->sig;
    }

    if (act) {
        if (ant)
            ant->sig = act->sig;
        else
            ptrMatD = act->sig;
        delete act;
    }
}

void Matriz_dispersa1::elimina_dato(int valor) {
    if (!ptrMatD) return;
    direccion act = ptrMatD;
    direccion sig = nullptr;
    while (act) {
        sig = act->sig;
        if (act->dato == valor) {
            eliminar_nodo(act->fila, act->columna);
        }
        act = sig;
    }
}

bool Matriz_dispersa1::existe_valor_repetido(int valor) {
    for (direccion x = ptrMatD; x; x = x->sig)
        if (x->dato == valor)
            return true;
    return false;
}

void Matriz_dispersa1::definir_valor_repetido(int valor) {
    int valor_ant = rep;
    if (valor != rep) {
        rep = valor;
	   	if (existe_valor_repetido(valor)) {
			for (int i = 0; i < dimencion_fila(); ++i) {
				for (int j = 0; j < dimencion_columna(); ++j) {
					direccion x = buscar_nodo(i + 1, j + 1);
					if (!x)
						poner_dato(i + 1, j + 1, valor_ant);
				}
			}
			elimina_dato(rep);
		}
	}
}
void Matriz_dispersa1::dibujar(TCanvas *canvas, int x, int y,
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

void Matriz_dispersa1::dibujar_matriz(TCanvas *canvas, int x_inicial, int y_inicial,
                                     int ancho_celda, int alto_celda) {
    canvas->Brush->Color = clGradientActiveCaption;
    TRect rect(x_inicial, y_inicial, 1000, 1000);
	canvas->FillRect(rect);
    int x, y;
    for (int fila = 1; fila <= dimf; ++fila) {
        for (int columna = 1; columna <= dimc; ++columna) {
            x = x_inicial + (columna - 1) * ancho_celda;
            y = y_inicial + (fila - 1) * alto_celda;

            direccion nodo = buscar_nodo(fila, columna);
            string mensaje = nodo ? to_string(nodo->dato) : to_string(rep);
            TColor color = nodo ? clSkyBlue : clWhite;
            bool con_borde = true;

            dibujar(canvas, x, y, ancho_celda, alto_celda, mensaje, color, con_borde);
        }
    }
}



//---------------------------------------------------------------------------
#pragma package(smart_init)
