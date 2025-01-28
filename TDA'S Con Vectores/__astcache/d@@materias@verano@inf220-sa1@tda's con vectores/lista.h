//---------------------------------------------------------------------------

#ifndef ListaH
#define ListaH
#include <vcl.h>
using namespace std;
typedef int direccion;
const int max = 100;
class Lista {
private:
    int cantidad;
    int datos[100];
public:
    Lista();
    direccion primero();
    direccion anterior(direccion dir);
    direccion siguiente(direccion dir);
    direccion fin();
    void inserta_primero(int dato);
    void inserta(direccion dir, int dato);
    void inserta_final(int dato);
    int recupera(direccion dir);
    direccion localiza(int dato);
    void suprime(direccion dir);
    void elimina_dato(int dato);
    int getLongitud() { return cantidad; }
    void anule();
    bool vacia();
    bool llena();
    void modifica(direccion dir, int dato);
    void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
