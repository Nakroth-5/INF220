//---------------------------------------------------------------------------

#ifndef Matriz_dispersa1H
#define Matriz_dispersa1H
#include <vector>
#include <Vcl.h>
using namespace std;
class Matriz_dispersa1 {
private:
    struct Nodo {
        int dato;
        int fila;
        int columna;
        Nodo *sig;
    };
    typedef Nodo *direccion;
    direccion ptrMatD;
    int dimf, dimc, rep, nt;
public:
    Matriz_dispersa1();
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
    //auxiliares
    vector<pair<int, int>> posiciones_repetidas;
    bool esta_registrada(int f, int c);
    bool direccion_valida(int f, int c);
};
//---------------------------------------------------------------------------
#endif
