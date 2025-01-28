//---------------------------------------------------------------------------

#ifndef ListaH
#define ListaH
#include <string>
#include <vcl.h>
using namespace std;

struct NodoP {
		int dato;
		NodoP *sig;
		NodoP(int dato): dato(dato), sig(nullptr) {}
};
typedef NodoP *direccion;

class Lista
{
private:

	int cantidad;
	direccion ptrElementos;
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
    void modifica(direccion dir, int dato);
	void mostrar(TCanvas *canvas, int x, int y);
};
//---------------------------------------------------------------------------
#endif
