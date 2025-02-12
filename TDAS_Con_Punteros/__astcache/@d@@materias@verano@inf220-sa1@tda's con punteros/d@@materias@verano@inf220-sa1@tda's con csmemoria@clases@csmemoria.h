﻿//---------------------------------------------------------------------------

#ifndef CSMemoriaH
#define CSMemoriaH
#include <string>
#include <sstream>
#include <vcl.h>
using namespace std;
const int NULO = -1;
typedef int direccion;
typedef AnsiString string1;
class CSMemoria {
private:
    const int MAX = 20;
    direccion libre;
    const int alto_celda = 25;
    struct NodoM {
        int dato;
        string id;
        direccion link;
    };
    NodoM *mem;
    int cantidad_de_ids(const string &ids);
    string obtener_id(const string &ids, int pos);
    void eliminar_flecha(string &id);
    bool es_direccion_valida(int dir) const {
        return dir >= 0 && dir < MAX;
    }
public:
    CSMemoria();
    direccion new_espacio(string ids);
    void delete_espacio(direccion dir);
    void poner_dato(direccion dir, string id, int valor);
    int obtener_dato(direccion dir, string id);
    int espacios_disponibles();
    int espacios_ocupados();
    bool dir_libre(direccion dir);
    void mostrar(TCanvas *canvas, int desde, int hasta);
    void dibujar(TCanvas *canvas, int x, int y, int ancho_celda,
                 const string &mensaje, TColor color, bool con_borde);
};
//---------------------------------------------------------------------------
#endif

