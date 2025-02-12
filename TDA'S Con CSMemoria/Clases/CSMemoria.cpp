﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
CSMemoria::CSMemoria(): mem(new NodoM[MAX]) {
	for (int i = 0; i < MAX - 1; ++i) {
        mem[i].dato = 0;
		mem[i].link = i + 1;
	}
	mem[MAX - 1].link = NULO;
    libre = 0;
}

direccion CSMemoria::new_espacio(string ids) {
    int cant = cantidad_de_ids(ids);
    int dir = libre;
    int d = libre;
    for (int i = 1; i < cant; ++i) {
        mem[d].id = obtener_id(ids, i);
        d = mem[d].link;
    }
    libre = mem[d].link;
    mem[d].link = NULO;
    mem[d].id = obtener_id(ids, cant);
    return dir;
}

void CSMemoria::delete_espacio(direccion dir) {
    if (!es_direccion_valida(dir))
		throw Exception("Error: ingrese una dirección válida");
	int x = dir;
    while (mem[x].link != NULO)
        x = mem[x].link;
    mem[x].link = libre;
    libre = dir;
}

void CSMemoria::poner_dato(direccion dir, string id, int valor) {
    if (!es_direccion_valida(dir))
        throw Exception("Error: ingrese una dirección vólida");
    eliminar_flecha(id);
    bool encontrado = false;
    for (int z = dir; z != NULO; z = mem[z].link) {
        if (mem[z].id == id) {
            mem[z].dato = valor;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
        throw Exception("Error: el ID especificado no existe o el espacio fue liberado.");
}

int CSMemoria::obtener_dato(direccion dir, string id) {
    if (!es_direccion_valida(dir))
        return -1;
    eliminar_flecha(id);
    for (int z = dir; z != NULO; z = mem[z].link)
        if (mem[z].id == id)
            return mem[z].dato;
    return NULO;
}

int CSMemoria::espacios_disponibles() {
    int c = 0;
    for (int x = libre; x != NULO; x = mem[x].link)
        c++;
    return c;
}

int CSMemoria::espacios_ocupados() {
    return (MAX + 1 - espacios_disponibles());
}

bool CSMemoria::dir_libre(direccion dir) {
    for (int x = libre; x != NULO; x = mem[x].link)
        if (x == dir)
            return true;
    return false;
}

int CSMemoria::cantidad_de_ids(const string &ids) {
    stringstream ss(ids);
    string palabra;
    int c = 0;
    while (getline(ss, palabra, ','))
        c++;
    return c;
}

string CSMemoria::obtener_id(const string &cadena, int pos) {
    stringstream ss(cadena);
    string palabra;
    int c = 0;

    while (getline(ss, palabra, ',')) {
        c++;
        if (c == pos)
            return palabra;
    }

    return "";
}


void CSMemoria::eliminar_flecha(string &id) {
    if (id.substr(0, 2) == "->")
        id.erase(0, 2);
    else
        throw Exception("Error: ingrese  '->' antes del Id");
}

void CSMemoria::dibujar(TCanvas *canvas, int x, int y,
int ancho_celda, const string &mensaje, TColor color, bool con_borde) {

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

void CSMemoria::mostrar(TCanvas *canvas, int desde, int hasta) {
    canvas->Brush->Color = clGradientActiveCaption;
	canvas->Pen->Color = clBlack;
    //          x,   y,  b,   h
	TRect rect(500, 30, 730, 800);
	canvas->FillRect(rect);
	int x = 500, y = 30;
    int ancho_celda = 50;
    canvas->TextOut(x, 5, "Evert Rodriguez Araúz");
    dibujar(canvas, x, y, ancho_celda,  "dir", clGradientActiveCaption, false);
    dibujar(canvas, x + ancho_celda, y, ancho_celda,  "dato", clGradientActiveCaption, false);
	dibujar(canvas, x + 10 + ancho_celda * 2, y, ancho_celda,  "id", clGradientActiveCaption, false);
	dibujar(canvas, x + 20 + ancho_celda * 3, y, ancho_celda,  "link", clGradientActiveCaption, false);
    y += alto_celda;
	int aux = x;

    for (int i = desde; i <= hasta; i++) {
        dibujar(canvas, x, y, ancho_celda,  "     " + to_string(i), clWhite, false);//dir
        x += ancho_celda;
		dibujar(canvas, x, y, ancho_celda, "  " + to_string(mem[i].dato), clWhite, true);//dato
        x += ancho_celda;
        dibujar(canvas, x, y, ancho_celda + 20, mem[i].id, clWhite, true);//id
		x += ancho_celda + 20;
		dibujar(canvas, x, y, ancho_celda, "     " + to_string(mem[i].link), clYellow, true);//link
		x += ancho_celda;
		string libre_ = "";
		if (dir_libre(i))
			 libre_ = "L";
		else
			libre_ = "O";
		dibujar(canvas, x, y, ancho_celda, "" + libre_, clGradientActiveCaption, false);
        y += alto_celda;
        x = aux;
    }
    dibujar(canvas, x, y, ancho_celda,  "Libre = " + to_string(libre), clGradientActiveCaption, false);
}

//---------------------------------------------------------------------------
#pragma package(smart_init)

