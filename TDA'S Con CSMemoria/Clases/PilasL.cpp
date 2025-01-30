﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilasL.h"

PilasL::PilasL(CSMemoria* mem) : lista(new Lista(mem)) {}

PilasL::PilasL(): lista(new Lista()) {}

bool PilasL::vacia() { return lista->vacia(); }

void PilasL::poner(double dato) {
    lista->inserta(lista->primero(), dato);
}

void PilasL::sacar(double &dato) {
    if (vacia())
        throw Exception("Error: Pila vacía");
    dato = lista->recupera(lista->primero());
    lista->suprime(lista->primero());
}

void PilasL::suprime(direccion x) {

}

bool isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 2;
    return 0;
}

bool opApertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool opCierre(char c) {
    return c == ')' || c == ']' || c == '}';
}


string PilasL::prefija_a_posfija(string infija) {
    string postfix = "";
	PilasL operadores;

    for (size_t i = 0; i < infija.size(); ++i) {
        if (isdigit(infija[i])) {
            while (i < infija.size() && isdigit(infija[i])) {
                postfix += infija[i];
                i++;
            }
            postfix += ' ';
            i--;
        } else if (opApertura(infija[i]))
            operadores.poner(infija[i]);
        else if (opCierre(infija[i])) {
            double top;
            while (!operadores.vacia()) {
                operadores.sacar(top);
                if (opApertura(top)) break;
                postfix += (char)top;
                postfix += ' ';
            }
        } else if (isoperator(infija[i])) {
            double top;
            while (!operadores.vacia()) {
                operadores.sacar(top);
                if (precedence(top) < precedence(infija[i])) {
                    operadores.poner(top);
                    break;
                }
                postfix += (char)top;
                postfix += ' ';
            }
            operadores.poner(infija[i]);
        }
    }

    double top;
    while (!operadores.vacia()) {
        operadores.sacar(top);
        if (opApertura((char)top))
            throw Exception("Error: falta algun '), ], }'");
        postfix += (char)top;
        postfix += ' ';
    }
    return postfix;
}

double evaluar(double a, double b, char operacion) {
    if (operacion == '+') return a + b;
    if (operacion == '-') return a - b;
    if (operacion == '*') return a * b;
    if (operacion == '/') return a / b;
    if (operacion == '^') return pow(a, b);
    return -1;
}

double PilasL::evaluar_posfija(string posfija) {
    double resp = 0;
    PilasL operadores;
    for (size_t i = 0; i < posfija.size(); ++i) {
        if (isdigit(posfija[i])) {
            string num = "";
            while (i < posfija.size() && isdigit(posfija[i])) {
                num += posfija[i];
                i++;
            }
            operadores.poner(stoi(num));
        } else if (isoperator(posfija[i])) {
            double a, b;
            operadores.sacar(b);
            operadores.sacar(a);
            resp = evaluar(a, b, posfija[i]);
            operadores.poner(resp);
            i++;
        }
    }

    if (!operadores.vacia())
        operadores.sacar(resp);
    return resp;
}

string formatNumber(double number, int precision) {
    ostringstream oss;
    oss << fixed << setprecision(precision) << number;
    return oss.str();
}

void PilasL::dibujar(TCanvas *canvas, int x, int y, int ancho_celda, int alto_celda,
                     const string &mensaje, TColor color, bool con_borde) {

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

void PilasL::mostrar(TCanvas *canvas, int x, int y) {
    lista->mostrar(canvas, x + 80, y);
    const int ancho = 50;
    const int alto = 25;
    TRect rect(x, y, x + 70, y -500);
    canvas->Brush->Color = clGradientActiveCaption;
    canvas->FillRect(rect);
    // Crear una pila auxiliar para invertir el orden
    PilasL aux;
    int contador = 0;

    // Copiar elementos a la pila auxiliar (esto los invertirá)
    direccion actual = lista->primero();
    while (actual != NULO) {
		aux.poner(lista->recupera(actual));
        contador++;
        actual = lista->siguiente(actual);
    }

    dibujar(canvas, x, y, ancho, alto, "Usuario", clLime, true);

    y -= alto;
    while (!aux.vacia()) {
        double valor;
        aux.sacar(valor);
        string dato = formatNumber(valor, 2);
        dibujar(canvas, x, y, ancho, alto, dato, (TColor)0x00A5FF, true);
        y -= alto;
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
