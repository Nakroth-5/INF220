﻿#ifndef MatrizD_2_nodosH
#define MatrizD_2_nodosH
#include <vector>
#include <Vcl.h>
using namespace std;

// Declaración anticipada de NodoC
struct NodoC;

// Definición de NodoF
struct NodoF {
    int fila;
    NodoF* fila_ant;
    NodoF* fila_sig;
    NodoC* PtrCol;
};

// Definición de NodoC
struct NodoC {
    int columna;
    int dato;
    NodoC* col_sig;
};

class MatrizD_2_nodos {
private:
    typedef NodoF* direccion;
    direccion ptrFila;
    int dimf, dimc, rep, nt;

private:
    bool direccion_valida(int f, int c);
    direccion buscar_nodo_f(int f);
    NodoC* buscar_nodo_c(direccion nodo_f, int c); // Corregido el tipo de retorno

public:
    MatrizD_2_nodos();
    void dimencionar(int df, int dc);
    int dimencion_fila();
    int dimencion_columna();
    void poner_dato(int f, int c, int valor);
    int elemento(int f, int c);
    bool existe_valor_repetido(int valor);
    void definir_valor_repetido(int valor);
    void elimina_dato(int valor);
    direccion buscar_nodo(int f, int c);
    void eliminar_nodo(int f, int c);
    void dibujar(TCanvas* canvas, int x, int y,
                 int ancho_celda, int alto_celda, const string& mensaje, TColor color, bool con_borde);
    void dibujar_matriz(TCanvas* canvas, int x_inicial, int y_inicial,
                        int ancho_celda, int alto_celda);
};

#endif
