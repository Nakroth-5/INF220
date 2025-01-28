//---------------------------------------------------------------------------

#ifndef Matriz_dispersaH
#define Matriz_dispersaH
#include <vector>
#include <Vcl.h>
#include "CSMemoria.h"
using namespace std;
class Matriz_dispersa {
private:
    int dimf, dimc, rep, nt;
    direccion ptrMatD;
    CSMemoria *m;
public:
    Matriz_dispersa(CSMemoria *mem);
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
    void dibujar(TCanvas *canvas, int x, int y,
                 int ancho_celda, int alto_celda, const string &mensaje, TColor color, bool con_borde);
    void dibujar_matriz(TCanvas *canvas, int x_inicial, int y_inicial,
                        int ancho_celda, int alto_celda);
private:
	bool direccion_valida(int f, int c);
};
//---------------------------------------------------------------------------
#endif
