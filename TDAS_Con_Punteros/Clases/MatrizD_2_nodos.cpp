﻿//---------------------------------------------------------------------------
#pragma hdrstop
#include "MatrizD_2_nodos.h"

MatrizD_2_nodos::MatrizD_2_nodos(): ptrFila(nullptr), dimf(0), dimc(0), nt(0), rep(0) {}

void MatrizD_2_nodos::dimencionar(int df, int dc) {
    dimf = df; dimc = dc;
}

int MatrizD_2_nodos::dimencion_columna() { return dimc; }

int MatrizD_2_nodos::dimencion_fila() { return dimf; }

bool MatrizD_2_nodos::direccion_valida(int f, int c) {
    if ((f > 0 && f <= dimencion_fila()) && (c > 0 && c <= dimencion_columna()))
        return true;
    return false;
}

MatrizD_2_nodos::direccion MatrizD_2_nodos::buscar_nodo_f(int f) {
    for (direccion x = ptrFila; x; x = x->fila_sig) {
        if (x->fila == f)
            return x;
    }
    return nullptr;
}

NodoC* MatrizD_2_nodos::buscar_nodo_c(direccion nodo_f, int c) {
    if (!nodo_f) return nullptr;
    for (NodoC* x = nodo_f->PtrCol; x; x = x->col_sig) {
        if (x->columna == c)
            return x;
    }
    return nullptr;
}

MatrizD_2_nodos::direccion MatrizD_2_nodos::buscar_nodo(int f, int c) {
    if (!direccion_valida(f, c))
        throw Exception("Direcciones no validas");
    return buscar_nodo_f(f);
}

int MatrizD_2_nodos::elemento(int f, int c) {
    if (!direccion_valida(f, c))
        throw Exception("Direcciones no validas");

    direccion nodo_f = buscar_nodo_f(f);
    if (!nodo_f) return rep;

    NodoC* nodo_c = buscar_nodo_c(nodo_f, c);
    if (!nodo_c) return rep;

    return nodo_c->dato;
}

void MatrizD_2_nodos::poner_dato(int f, int c, int valor) {
    if (!direccion_valida(f, c))
        throw Exception("Error fuera de rango");

    if (valor == rep) {
        eliminar_nodo(f, c);
        return;
    }

    direccion dir_fila = buscar_nodo_f(f);
    if (!dir_fila) {
        dir_fila = new NodoF();
        dir_fila->fila = f;
        dir_fila->PtrCol = nullptr;
        dir_fila->fila_sig = ptrFila;
        dir_fila->fila_ant = nullptr;
        if (ptrFila)
            ptrFila->fila_ant = dir_fila;
        ptrFila = dir_fila;
    }

    NodoC* dir_columna = buscar_nodo_c(dir_fila, c);
    if (!dir_columna) {
        dir_columna = new NodoC();
        dir_columna->columna = c;
        dir_columna->col_sig = dir_fila->PtrCol;
        dir_fila->PtrCol = dir_columna;
    }
    dir_columna->dato = valor;
}

void MatrizD_2_nodos::eliminar_nodo(int f, int c) {
    if (!direccion_valida(f, c))
        throw Exception("Direcciones no validas");

    direccion nodo_f = buscar_nodo_f(f);
    if (!nodo_f) return;

    NodoC* actual = nodo_f->PtrCol;
    NodoC* anterior = nullptr;

    while (actual && actual->columna != c) {
        anterior = actual;
        actual = actual->col_sig;
    }

    if (!actual) return;

    if (!anterior)
        nodo_f->PtrCol = actual->col_sig;
    else
        anterior->col_sig = actual->col_sig;

    delete actual;

    // Si la fila quedó vacía, la eliminamos
    if (!nodo_f->PtrCol) {
        if (nodo_f->fila_ant)
            nodo_f->fila_ant->fila_sig = nodo_f->fila_sig;
        else
            ptrFila = nodo_f->fila_sig;

        if (nodo_f->fila_sig)
            nodo_f->fila_sig->fila_ant = nodo_f->fila_ant;

        delete nodo_f;
    }
}

bool MatrizD_2_nodos::existe_valor_repetido(int valor) {
    for (direccion fila = ptrFila; fila; fila = fila->fila_sig) {
        for (NodoC* col = fila->PtrCol; col; col = col->col_sig) {
            if (col->dato == valor)
                return true;
        }
    }
    return false;
}

void MatrizD_2_nodos::definir_valor_repetido(int valor) {
	int valor_ant = rep;
    if (valor != rep) {
        rep = valor;
        for(int i = 1; i <= dimf; i++) {
            for(int j = 1; j <= dimc; j++) {
                // Si en esta posición había un valor implícito (antiguo_rep)
				// y no hay un valor explícito almacenado
				if(buscar_nodo(i, j) == nullptr) {
					poner_dato(i, j, valor_ant);
				}
            }
		}
        elimina_dato(rep);
    }
}

void MatrizD_2_nodos::elimina_dato(int valor) {
    for (direccion fila = ptrFila; fila;) {
        direccion sig_fila = fila->fila_sig;
        for (NodoC* col = fila->PtrCol; col;) {
            NodoC* sig_col = col->col_sig;
            if (col->dato == valor) {
                eliminar_nodo(fila->fila, col->columna);
            }
            col = sig_col;
        }
        fila = sig_fila;
    }
}

void MatrizD_2_nodos::dibujar(TCanvas *canvas, int x, int y,
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

void MatrizD_2_nodos::dibujar_matriz(TCanvas *canvas, int x_inicial, int y_inicial, int ancho_celda, int alto_celda) {
    canvas->Brush->Color = clGradientActiveCaption;  // Color de fondo del canvas
    TRect rect(x_inicial, y_inicial, 1000, 1000);   // Área del canvas
    canvas->FillRect(rect);                         // Rellenar el área con el color de fondo

    int x, y;
    for (int fila = 1; fila <= dimf; ++fila) {
        for (int columna = 1; columna <= dimc; ++columna) {
            x = x_inicial + (columna - 1) * ancho_celda;  // Posición X de la celda
            y = y_inicial + (fila - 1) * alto_celda;      // Posición Y de la celda

            NodoF* nodoF = buscar_nodo_f(fila);        // Buscar nodo de fila
            NodoC* nodoC = nullptr;
            if (nodoF != nullptr) {
                nodoC = buscar_nodo_c(nodoF, columna);  // Buscar nodo de columna
            }

            string mensaje;
            TColor color;
            if (nodoC != nullptr) {
                mensaje = to_string(nodoC->dato);  // Mostrar el valor del nodo de columna
                color = clSkyBlue;                 // Color para celdas con valores no nulos
            } else {
                mensaje = to_string(rep);          // Mostrar el valor repetido
                color = clWhite;                   // Color para celdas con valores nulos
            }

            dibujar(canvas, x, y, ancho_celda, alto_celda, mensaje, color, true);  // Dibujar la celda
        }
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
